/**************************************************************\
					       
\**************************************************************/
CREATE TABLE public.employees(
	id_employee       INT  NOT NULL ,
	salary_employee   FLOAT  NOT NULL ,
	id_type_emp       INT  NOT NULL  ,
	CONSTRAINT employees_PK PRIMARY KEY (id_employee)

	,CONSTRAINT employees_type_employee0_FK FOREIGN KEY (id_type_emp) REFERENCES public.type_employee(id_type_emp)
)WITHOUT OIDS;


-----------------------------------------
--	FUNCTIONS
-----------------------------------------
CREATE OR REPLACE FUNCTION f_create_employee(v_id_entity INT,v_salary FLOAT,v_id_type INT)
RETURNS INT AS $$
BEGIN
	INSERT INTO employees VALUES(v_id_entity,v_salary,v_id_type);
	return v_id_entity;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_update_employee(v_id INT,v_salary FLOAT,v_id_type INT)
RETURNS void AS $$
BEGIN
	UPDATE employees SET salary_employee=v_salary, id_type_emp=v_id_type, WHERE id_employee=v_id;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_employees()
RETURNS SETOF employees AS $$
BEGIN
	RETURN QUERY SELECT * FROM employees;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_employees_notDeleted()
RETURNS SETOF employees AS $$
BEGIN
	RETURN QUERY SELECT employees.* FROM employees 
		INNER JOIN entities ON id_entity=id_employee WHERE isDelete_entity=false;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_employee_by_code(v_code text)
RETURNS SETOF employees AS $$
BEGIN
	RETURN QUERY (SELECT employees.* FROM employees INNER JOIN entities ON id_entity=id_employee WHERE code_entity=UPPER(TRIM(v_code)));
END $$ LANGUAGE plpgsql;

-----------------------------------------
--	TRIGGERS
-----------------------------------------
CREATE OR REPLACE FUNCTION tf_create_employee()
RETURNS trigger AS $$
BEGIN
	IF NOT EXISTS( SELECT * FROM entities WHERE id_entity=new.id_employee) THEN
		RAISE EXCEPTION 'The entity does not exist !';
	ELSIF EXISTS( SELECT * FROM suppliers WHERE id_supplier=new.id_employee) THEN
		RAISE EXCEPTION 'The employee_id already exists in supplier table!';
	END IF;
	return new;
END $$ LANGUAGE plpgsql;
CREATE TRIGGER t_create_employee
BEFORE INSERT OR UPDATE ON employees
FOR EACH ROW
EXECUTE PROCEDURE tf_create_employee();