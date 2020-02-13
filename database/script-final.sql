------------------------------------------------------------
-- Table: cities
------------------------------------------------------------
CREATE TABLE public.cities(
	id_city     SERIAL NOT NULL ,
	name_city   VARCHAR (50) NOT NULL ,
	cp_city     VARCHAR (50) NOT NULL  ,
	CONSTRAINT cities_PK PRIMARY KEY (id_city)
)WITHOUT OIDS;

------------------------------------------------------------
-- Table: streets
------------------------------------------------------------
CREATE TABLE public.streets(
	id_street       SERIAL NOT NULL ,
	name_street     VARCHAR (50) NOT NULL ,
	number_street   VARCHAR (50) NOT NULL ,
	id_city			INT NOT NULL,
	CONSTRAINT streets_PK PRIMARY KEY (id_street)
)WITHOUT OIDS;

------------------------------------------------------------
-- Table: entities
------------------------------------------------------------
CREATE TABLE public.entities(
	id_entity         SERIAL NOT NULL ,
	isDelete_entity   BOOL  NOT NULL DEFAULT false ,
	name_entity       VARCHAR (50) NOT NULL ,
	forename_entity   VARCHAR (50) NOT NULL ,
	birthday_entity   DATE  NOT NULL ,
	phone_entity      VARCHAR (50) NOT NULL ,
	code_entity       VARCHAR (50) NOT NULL UNIQUE ,
	picture_entity	  VARCHAR (100) DEFAULT null ,
	id_street 		  INT NOT NULL,
	CONSTRAINT entities_PK PRIMARY KEY (id_entity)
)WITHOUT OIDS;

------------------------------------------------------------
-- Table: type_employee
------------------------------------------------------------
CREATE TABLE public.type_employee(
	id_type_emp     SERIAL NOT NULL ,
	name_type_emp   VARCHAR (50) NOT NULL UNIQUE  ,
	CONSTRAINT type_employee_PK PRIMARY KEY (id_type_emp)
)WITHOUT OIDS;

------------------------------------------------------------
-- Table: employee
------------------------------------------------------------
CREATE TABLE public.employees(
	id_employee       INT  NOT NULL ,
	salary_employee   FLOAT  NOT NULL ,
	id_type_emp       INT  NOT NULL  ,
	CONSTRAINT employees_PK PRIMARY KEY (id_employee)

	,CONSTRAINT employees_type_employee0_FK FOREIGN KEY (id_type_emp) REFERENCES public.type_employee(id_type_emp)
)WITHOUT OIDS;

------------------------------------------------------------
-- Table: suppliers
------------------------------------------------------------
CREATE TABLE public.suppliers(
	id_supplier       INT  NOT NULL,
	fax_supplier	  VARCHAR(50),
	CONSTRAINT suppliers_PK PRIMARY KEY (id_supplier)
)WITHOUT OIDS;

------------------------------------------------------------
-- Table: Plannings
------------------------------------------------------------
CREATE TABLE public.plannings(
	id_planning             SERIAL NOT NULL ,
	isDelete_planning		BOOL NOT NULL DEFAULT false,
	begin_planning          TIMESTAMP  NOT NULL ,
	end_planning            TIMESTAMP  NOT NULL ,
	comment_planning        VARCHAR (2000) DEFAULT NULL,
	isDayOff				BOOL NOT NULL DEFAULT true,
	id_employee             INT  NOT NULL ,
	CONSTRAINT plannings_PK PRIMARY KEY (id_planning)
)WITHOUT OIDS;

------------------------------------------------------------
-- Table: Products
------------------------------------------------------------
CREATE TABLE public.products(
	id_product     		SERIAL NOT NULL ,
	isDelete_product   	bool NOT NULL DEFAULT false,
	name_product     	VARCHAR (50) UNIQUE NOT NULL  ,
	picture_product     VARCHAR (50),
	price_product		FLOAT NOT NULL DEFAULT 0,
	quantity_stock		INT NOT NULL DEFAULT 0,
	centiliter_capacity INT NOT NULL DEFAULT 0,
	centiliter_remainder INT,
	alarm_count			INT,
	CONSTRAINT products_PK PRIMARY KEY (id_product)
)WITHOUT OIDS;


/**************************************************************\
					       Orders
\**************************************************************/
CREATE TABLE public.orders(
	id_order	SERIAL NOT NULL,
	id_stakeholder INT NOT NULL,
	time_transaction  TIMESTAMP NOT NULL DEFAULT current_timestamp,
	price_order FLOAT NOT NULL DEFAULT 0,
	deleted_order BOOL NOT NULL DEFAULT false,
	CONSTRAINT orders_PK PRIMARY KEY (id_order),
	CONSTRAINT orders_entity_FK FOREIGN KEY (id_stakeholder) REFERENCES public.entities(id_entity)
)WiTHOUT OIDS;

/**************************************************************\
					       compose_Order
\**************************************************************/
CREATE TABLE public.compose_order(
	id_order	INT NOT NULL,
	id_product  INT NOT NULL,
	quantity_ordered INT NOT NULL DEFAULT 0,
	CONSTRAINT compose_order_PK PRIMARY KEY (id_order,id_product),
	CONSTRAINT compose_order_order_FK FOREIGN KEY (id_order) REFERENCES public.orders(id_order),
	CONSTRAINT compose_order_product_FK FOREIGN KEY (id_product) REFERENCES public.products(id_product)
)WiTHOUT OIDS;

/**************************************************************\
					      Compose_Product
\**************************************************************/
/**
 * EX : rhum coca = (coca) compose (rhum coca) par 33cl
 */
CREATE TABLE public.compose_product(
	id_product	INT NOT NULL,
	id_ingredient  INT NOT NULL,
	quantity_used FLOAT NOT NULL,
	CONSTRAINT compose_product_PK PRIMARY KEY(id_ingredient,id_product),
	CONSTRAINT compose_product_compose_FK FOREIGN KEY (id_product) REFERENCES public.products(id_product),
	CONSTRAINT compose_product_composed_FK FOREIGN KEY (id_ingredient) REFERENCES public.products(id_product)
)WiTHOUT OIDS;


------------------------------------------------------------
-- Constraints
------------------------------------------------------------
ALTER TABLE public.streets
	ADD CONSTRAINT streets_cities0_FK
	FOREIGN KEY (id_city)
	REFERENCES public.cities(id_city);
	
ALTER TABLE public.entities
	ADD CONSTRAINT entities_streets0_FK
	FOREIGN KEY (id_street)
	REFERENCES public.streets(id_street);
	
ALTER TABLE public.employees
	ADD CONSTRAINT employees_entities0_FK
	FOREIGN KEY (id_employee)
	REFERENCES public.entities(id_entity);

ALTER TABLE public.employees
	ADD CONSTRAINT employees_type_employee1_FK
	FOREIGN KEY (id_type_emp)
	REFERENCES public.type_employee(id_type_emp);

ALTER TABLE public.suppliers
	ADD CONSTRAINT suppliers_entities0_FK
	FOREIGN KEY (id_supplier)
	REFERENCES public.entities(id_entity);

ALTER TABLE public.plannings
	ADD CONSTRAINT plannings_employees0_FK
	FOREIGN KEY (id_employee)
	REFERENCES employees(id_employee);
--------------------------------------
--	FUNCTIONS AND TRIGGER FOR cities
-----------------------------------------
CREATE OR REPLACE FUNCTION f_create_city(v_city TEXT,v_cp TEXT)
RETURNS INT AS $$
DECLARE
	v_id INT;
BEGIN
	SELECT id_city INTO v_id FROM cities WHERE name_city=LOWER(TRIM(v_city)) AND cp_city=LOWER(TRIM(v_cp)); 
	IF (v_id IS NULL) THEN
		INSERT INTO cities(name_city,cp_city) VALUES($1,$2) RETURNING id_city INTO v_id;
	END IF;
	return v_id;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_update_city(v_id INT,v_city TEXT,v_cp TEXT)
RETURNS void AS $$
BEGIN
	UPDATE cities SET name_city=v_city, cp_city=v_cp WHERE id_city=v_id;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_cities()
RETURNS SETOF cities AS $$
BEGIN
	RETURN QUERY SELECT * FROM cities;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION ft_create_city()
RETURNS trigger AS $$
BEGIN
	new.name_city=LOWER(TRIM(new.name_city));
	new.cp_city=LOWER(TRIM(new.cp_city));
	IF EXISTS(select * from cities where name_city=new.name_city and cp_city=new.cp_city) THEN
		RAISE EXCEPTION '[CITY][ERROR] the tuple already exist !';
	END IF;
	RETURN new;
END $$ LANGUAGE plpgsql;
CREATE TRIGGER t_create_city
BEFORE INSERT OR UPDATE ON cities
EXECUTE PROCEDURE ft_create_city();
-----------------------------------------
--	FUNCTIONS AND TRIGGER FOR streets
-----------------------------------------
CREATE OR REPLACE FUNCTION f_create_street(v_street TEXT,v_number TEXT,v_id_city INT)
RETURNS INT AS $$
DECLARE
	v_id_street INT;
BEGIN
	SELECT id_street INTO v_id_street FROM streets WHERE name_street=LOWER(TRIM(v_street)) AND number_street=LOWER(TRIM(v_number));
	IF(v_id_street IS NULL) THEN
		INSERT INTO streets(name_street,number_street,id_city) VALUES ($1,$2,$3) RETURNING id_street INTO v_id_street; 
	END IF;
	return v_id_street;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_update_street(v_id INT,v_street TEXT,v_number TEXT,v_id_city INT)
RETURNS void AS $$
BEGIN
	UPDATE streets SET name_street=v_street, number_street=v_number,id_city=v_id_city WHERE id_street=v_id;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_streets()
RETURNS SETOF streets AS $$
BEGIN
	RETURN QUERY SELECT * FROM streets;
END $$ LANGUAGE plpgsql;


-----------------------------------------
--	FUNCTIONS AND TRIGGER FOR entities
-----------------------------------------
CREATE OR REPLACE FUNCTION f_create_entity(v_name TEXT,v_forename TEXT,v_birthday DATE,v_phone TEXT,v_picture TEXT,v_id_street INT,v_code TEXT DEFAULT '')
RETURNS INT AS $$
DECLARE
	v_id entities.id_entity%TYPE DEFAULT null;
BEGIN
	SELECT id_entity INTO v_id FROM entities WHERE code_entity=UPPER(TRIM(v_code));
	IF(v_id IS NULL) THEN
		INSERT INTO entities(name_entity,forename_entity,birthday_entity,phone_entity,picture_entity,id_street,code_entity)
			VALUES($1,$2,$3,$4,$5,$6,$7) RETURNING id_entity INTO v_id;
	END IF;
	return v_id;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_update_entity(v_id INT,v_delete BOOL ,v_name TEXT,v_forename TEXT,v_birthday DATE,v_phone TEXT,v_code TEXT,v_picture TEXT,v_id_street INT)
RETURNS void AS $$
BEGIN
	UPDATE entities SET isDelete_entity=v_delete, name_entity=v_name, forename_entity=v_forename, birthday_entity=v_birthday,phone_entity=v_phone, code_entity=v_code, picture_entity=v_picture , id_street=v_id_street WHERE id_entity=v_id; 
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION ft_create_entity()
RETURNS trigger AS $$
BEGIN
	new.name_entity=LOWER(TRIM(new.name_entity));
	new.forename_entity=LOWER(TRIM(new.forename_entity));
	new.code_entity=UPPER(TRIM(new.code_entity));
	IF (new.code_entity = '' OR new.code_entity IS NULL) THEN
		new.code_entity = new.id_entity;
	END IF;
	return new;
END $$ LANGUAGE plpgsql;
CREATE TRIGGER t_create_entity
BEFORE INSERT OR UPDATE ON entities
FOR EACH ROW
EXECUTE PROCEDURE ft_create_entity();

CREATE OR REPLACE FUNCTION ft_delete_entity()
RETURNS trigger AS $$
BEGIN
	IF EXISTS (SELECT * FROM employees WHERE id_employee=old.id_entity) THEN
		RAISE EXCEPTION 'An employee still exist with this ID !';
	ELSIF EXISTS (SELECT * FROM suppliers WHERE id_supplier=old.id_entity) THEN
		RAISE EXCEPTION 'A suppliers still exist with this ID !';
	END IF;
	return old;
END $$ LANGUAGE plpgsql;
CREATE TRIGGER t_delete_entity
BEFORE DELETE on entities
FOR EACH ROW
EXECUTE PROCEDURE ft_delete_entity();
-----------------------------------------
--	FUNCTIONS AND TRIGGER FOR type_employee
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

CREATE OR REPLACE FUNCTION f_get_types_employee()
RETURNS SETOF type_employee AS $$
BEGIN
	RETURN QUERY SELECT * FROM type_employee;
END $$ LANGUAGE plpgsql;

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
-----------------------------------------
--	FUNCTIONS AND TRIGGER FOR employee
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
	UPDATE employees SET salary_employee=v_salary, id_type_emp=v_id_type WHERE id_employee=v_id;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_employees()
RETURNS SETOF employees AS $$
BEGIN
	RETURN QUERY SELECT * FROM employees;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_employees_where_deleted(v_isDelete BOOl DEFAULT false)
RETURNS SETOF employees AS $$
BEGIN
	RETURN QUERY (SELECT employees.* FROM employees INNER JOIN entities ON id_entity=id_employee WHERE isDelete_entity=v_isDelete);
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_employee_by_code(v_code text)
RETURNS SETOF employees AS $$
BEGIN
	RETURN QUERY (SELECT employees.* FROM employees INNER JOIN entities ON id_entity=id_employee WHERE code_entity=UPPER(TRIM(v_code)));
END $$ LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION ft_create_employee()
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
EXECUTE PROCEDURE ft_create_employee();

-----------------------------------------
--	FUNCTIONS AND TRIGGER FOR plannings
-----------------------------------------
CREATE OR REPLACE FUNCTION f_create_planning(v_begin timestamp,v_end timestamp,v_id_employee INT,v_comment TEXT DEFAULT null,v_isDayOff BOOL DEFAULT TRUE)
RETURNS INT AS $$
DECLARE
	v_id INT DEFAULT null;
BEGIN
	INSERT INTO plannings(begin_planning,end_planning,id_employee,comment_planning,isDayOff) 
		VALUES ($1,$2,$3,$4,$5) RETURNING id_planning INTO v_id;
	return v_id;
END $$ LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION f_update_planning(v_id INT,v_isDelete BOOL,v_begin timestamp,v_end timestamp,v_id_employee INT,v_comment text ,v_isDayoff BOOL)
RETURNS VOID AS $$
DECLARE
BEGIN
	UPDATE plannings SET isDelete_planning=$2,begin_planning=$3,end_planning=$4,id_employee=$5,comment_planning=$6,isDayOff=$7 WHERE id_planning=$1;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_plannings()
RETURNS setof plannings AS $$
BEGIN
	RETURN QUERY select * from plannings;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_plannings_where_deleted(v_isDelete BOOl default false)
RETURNS setof plannings AS $$
BEGIN
	RETURN QUERY select * from plannings WHERE isDelete_planning=v_isDelete;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION ft_create_planning()
RETURNS trigger AS $$
BEGIN
	--Test data integrity
	IF (new.begin_planning>new.end_planning) THEN
		RAISE EXCEPTION '[Planning][ERROR] begin_planning > end_planning';
	END IF;
	return new;
END $$ LANGUAGE plpgsql;
CREATE trigger t_create_planning
BEFORE INSERT ON plannings
FOR EACH ROW 
EXECUTE PROCEDURE ft_create_planning();
-----------------------------------------
--	FUNCTIONS AND TRIGGER FOR supplier
-----------------------------------------
CREATE OR REPLACE FUNCTION f_create_supplier(v_id_entity INT,v_fax TEXT)
RETURNS INT AS $$
BEGIN
	INSERT INTO suppliers VALUES(v_id_entity,v_fax);
	RETURN v_id_entity;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_update_supplier(v_id INT,v_fax TEXT)
RETURNS void AS $$
BEGIN
	UPDATE suppliers SET fax_supplier=v_fax WHERE id_supplier=v_id;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_suppliers()
RETURNS SETOF suppliers AS $$
BEGIN
	RETURN QUERY SELECT * FROM suppliers;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_suppliers_where_delete(v_isDelete BOOL DEFAULT false)
RETURNS SETOF suppliers AS $$
BEGIN
	RETURN QUERY (SELECT suppliers.* FROM suppliers INNER JOIN entities ON id_entity=id_supplier WHERE isDelete_entity=v_isDelete);
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION tf_create_supplier()
RETURNS trigger AS $$
BEGIN
	IF NOT EXISTS( SELECT * FROM entities WHERE id_entity=new.id_supplier) THEN
		RAISE EXCEPTION 'The entity does not exist !';
	ELSIF EXISTS( SELECT * FROM employees WHERE id_employee=new.id_supplier) THEN
		RAISE EXCEPTION 'The supplier_id already exists in employee table!';
	END IF;
	return new;
END $$ LANGUAGE plpgsql;
CREATE TRIGGER tf_create_supplier
BEFORE INSERT OR UPDATE ON suppliers
FOR EACH ROW
EXECUTE PROCEDURE tf_create_supplier();

-----------------------------------------
--	FUNCTIONS AND TRIGGER FOR Product
-----------------------------------------
-----------------------------------------
--	FUNCTIONS
-----------------------------------------

CREATE OR REPLACE FUNCTION f_create_product(v_name TEXT,v_picture TEXT,v_price FLOAT,v_stock INT, v_capacity FLOAT,v_remainder FLOAT,v_alarm INT)
RETURNS INT AS $$
DECLARE
	v_id INT;
BEGIN
	SELECT id_product INTO v_id FROM products WHERE name_product=v_name;
	IF (v_id IS NULL) THEN
		INSERT INTO products(name_product,picture_product,price_product,quantity_stock,centiliter_capacity,centiliter_remainder,alarm_count)
		 VALUES($1,$2,$3,$4,$5,$6,$7) RETURNING id_product INTO v_id;
	END IF;
	return v_id;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_update_product(v_id INT,v_isDelete BOOL, v_name TEXT,v_picture TEXT,v_price FLOAT,v_stock INT, v_capacity FLOAT,v_remainder FLOAT,v_alarm INT )
RETURNS void AS $$
BEGIN
	UPDATE products SET isDelete_product=v_isDelete, name_product=v_name, picture_product=v_picture,price_product=v_price,quantity_stock=v_stock,centiliter_capacity=v_capacity,
			centiliter_remainder=v_remainder,alarm_count=v_alarm WHERE id_product=v_id;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_products()
RETURNS SETOF products AS $$
BEGIN
	RETURN QUERY SELECT * FROM products;
END $$ LANGUAGE plpgsql;

-----------------------------------------
--	TRIGGERS
-----------------------------------------

CREATE OR REPLACE FUNCTION ft_create_product()
RETURNS trigger AS $$
BEGIN
	new.name_product=LOWER(TRIM(new.name_product));
	RETURN new;
END $$ LANGUAGE plpgsql;
CREATE TRIGGER t_create_product
BEFORE INSERT OR UPDATE ON products
FOR EACH ROW
EXECUTE PROCEDURE  ft_create_product();

-----------------------------------------
--	FUNCTIONS AND TRIGGER FOR Order
-----------------------------------------
-----------------------------------------
--	FUNCTIONS
-----------------------------------------

CREATE OR REPLACE FUNCTION f_create_order(v_stakeholder INT,v_time TIMESTAMP DEFAULT current_timestamp,v_price FLOAT DEFAULT 0)
RETURNS INT AS $$
DECLARE
	v_id INT;
BEGIN
	INSERT INTO orders (id_stakeholder,time_transaction,price_order) VALUES(v_stakeholder,v_time,v_price) RETURNING id_order INTO v_id;
	RETURN v_id;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_update_order(v_order INT,v_stakeholder INT,v_time TIMESTAMP ,v_price FLOAT,v_delete BOOL)
RETURNS void AS $$
BEGIN
	UPDATE orders SET id_order=v_order, id_stakeholder=v_stakeholder, time_transaction=v_time, price_order=v_price , deleted_order=v_delete WHERE id_order=v_order; 
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_orders()
RETURNS SETOF orders AS $$
BEGIN
	RETURN QUERY SELECT * FROM orders;
END $$ LANGUAGE plpgsql;


-----------------------------------------
--	FUNCTIONS AND TRIGGER FOR compose_order
-----------------------------------------
-----------------------------------------
--	FUNCTIONS
-----------------------------------------
CREATE OR REPLACE FUNCTION f_append_to_order(v_order INT,v_product INT,v_qty INT)
RETURNS VOID AS $$
BEGIN
	INSERT INTO compose_order VALUES(v_order,v_product,v_qty);
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_update_orderComposition(v_order INT,v_product INT,v_qty INT)
RETURNS void AS $$
BEGIN
	UPDATE compose_order SET id_order=v_order, id_product=v_product , quantity_ordered=v_qty WHERE id_order=v_order AND id_product=v_product; 
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_delete_orderComposition(v_order INT,v_product INT)
RETURNS void AS $$
BEGIN
	delete from compose_order WHERE id_order=v_order AND  id_product=v_product;  
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_orderComposition_by_order(v_id INT)
RETURNS SETOF compose_order AS $$
BEGIN
	RETURN QUERY SELECT * FROM compose_order WHERE id_order=v_id;
END $$ LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION f_append_ingredient_to_product(v_product INT,v_ingredient INT,v_quantity FLOAT)
RETURNS VOID AS $$
DECLARE
	v_id INT;
BEGIN
	INSERT INTO compose_product VALUES(v_product,v_ingredient,v_quantity);
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_update_composition_of_product(v_product INT,v_ingredient INT,v_quantity FLOAT)
RETURNS void AS $$
DECLARE 
	v_table public.compose_product%ROWTYPE;
BEGIN
	SELECT * INTO v_table FROM compose_product WHERE id_product=v_product AND  id_ingredient=v_ingredient;
	IF(v_table IS NULL) THEN
		PERFORM f_append_ingredient_to_product(v_product,v_ingredient,v_quantity);
	ELSE
		UPDATE compose_product SET id_product=v_product, id_ingredient=v_ingredient, quantity_used=v_quantity WHERE id_product=v_product AND  id_ingredient=v_ingredient;
	END IF;  
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_delete_composition(v_product INT,v_ingredient INT)
RETURNS void AS $$
BEGIN
	delete from compose_product WHERE id_product=v_product AND  id_ingredient=v_ingredient;  
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_delete_all_from(v_product INT)
RETURNS void AS $$
BEGIN
	delete from compose_product WHERE id_product=v_product;
END $$ LANGUAGE plpgsql;



CREATE OR REPLACE FUNCTION f_get_ingredient_of(v_product INT)
RETURNS SETOF compose_product AS $$
BEGIN
	RETURN QUERY SELECT * FROM compose_product WHERE id_product=v_product ;
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_product_uses(v_ingredient INT)
RETURNS SETOF compose_product AS $$
BEGIN
	RETURN QUERY SELECT * FROM compose_product WHERE id_ingredient=v_ingredient ;
END $$ LANGUAGE plpgsql;




select f_create_city('liege','4000');
select f_create_city('wavre','1300');

select f_create_street('rue saint gilles','412',1);
select f_create_street('rue saint gilles','42',1);

select f_create_type_employee('manager');
select f_create_type_employee('barman');
select f_create_type_employee('waiter');
select f_create_entity('admin','admin',to_date('01-01-1900','dd-mm-yyyy'),'0499999999','null',1,'admin');
select f_create_employee(1,0,1);
