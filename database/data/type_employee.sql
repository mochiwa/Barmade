/**************************************************************\
					     TYPE_EMPLOYEE
\**************************************************************/

CREATE TABLE public.type_employee(
	id_type_emp     SERIAL NOT NULL ,
	name_type_emp   VARCHAR (50) NOT NULL UNIQUE  ,
	CONSTRAINT type_employee_PK PRIMARY KEY (id_type_emp)
)WITHOUT OIDS;

-----------------------------------------
--	FUNCTIONS
-----------------------------------------
CREATE OR REPLACE FUNCTION f_create_type_employee(v_type_employee TEXT)
RETURNS INT as $$
DECLARE
	v_id INT;
BEGIN
	SELECT id_type_emp INTO v_id FROM type_employee WHERE name_type_emp=UPPER(TRIM(v_type_employee));
	IF (v_id IS NULL) THEN
		INSERT INTO type_employee(name_type_emp) VALUES(v_type_employee) RETURNING id_type_emp INTO v_id;
	END IF;
	RETURN v_id;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_types_Employee()
RETURNS SETOF type_employee AS $$
BEGIN
	RETURN QUERY SELECT * FROM type_employee;
END $$ LANGUAGE plpgsql;

-----------------------------------------
--	TRIGGERS
-----------------------------------------
CREATE OR REPLACE FUNCTION ft_create_type_employee()
RETURNS trigger AS $$
BEGIN
	new.name_type_emp=UPPER(TRIM(new.name_type_emp));
	return new;
END $$ LANGUAGE plpgsql;
CREATE trigger t_create_type_employee
BEFORE INSERT OR UPDATE ON type_employee
FOR EACH ROW
EXECUTE PROCEDURE ft_create_type_employee();