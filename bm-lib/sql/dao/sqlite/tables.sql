------------------------------------------------------------
-- Table: entities
------------------------------------------------------------
CREATE TABLE entities(
	id_entity          INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT ,
	isDelete_entity    INTEGER NOT NULL ,
	name_entity        TEXT NOT NULL ,
	forename_entity    TEXT NOT NULL ,
	birthday_entity    NUMERIC NOT NULL ,
	phone_entity       TEXT NOT NULL ,
	code_entity        TEXT NOT NULL ,
	image_entity       TEXT
);


------------------------------------------------------------
-- Table: addresses
------------------------------------------------------------
CREATE TABLE addresses(
	id_address        INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT ,
	street            TEXT NOT NULL ,
	number_address    TEXT NOT NULL
);


------------------------------------------------------------
-- Table: cities
------------------------------------------------------------
CREATE TABLE cities(
	id_city      INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT ,
	name_city    TEXT NOT NULL ,
	cp_city      TEXT NOT NULL
);


------------------------------------------------------------
-- Table: type_employee
------------------------------------------------------------
CREATE TABLE type_employee(
	id_type_emp      INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT ,
	name_type_emp    TEXT NOT NULL
);


------------------------------------------------------------
-- Table: employees
------------------------------------------------------------
CREATE TABLE employees(
        id_employee        INTEGER NOT NULL ,
	id_entity          INTEGER NOT NULL ,
	salary_employee    REAL NOT NULL ,
	id_type_emp        INTEGER NOT NULL,
	CONSTRAINT employees_PK PRIMARY KEY (id_entity,id_employee)

	,CONSTRAINT employees_entities_FK FOREIGN KEY (id_entity) REFERENCES entities(id_entity)
	,CONSTRAINT employees_type_employee0_FK FOREIGN KEY (id_type_emp) REFERENCES type_employee(id_type_emp)
);


------------------------------------------------------------
-- Table: suppliers
------------------------------------------------------------
CREATE TABLE suppliers(
	id_entity          INTEGER NOT NULL ,
	id_supplier        INTEGER NOT NULL ,
	fax_supplier       TEXT NOT NULL ,
	isDelete_entity    INTEGER NOT NULL ,
	name_entity        TEXT NOT NULL ,
	forename_entity    TEXT NOT NULL ,
	birthday_entity    NUMERIC NOT NULL ,
	phone_entity       TEXT NOT NULL ,
	code_entity        TEXT NOT NULL ,
	image_entity       TEXT,
	CONSTRAINT suppliers_PK PRIMARY KEY (id_entity,id_supplier)

	,CONSTRAINT suppliers_entities_FK FOREIGN KEY (id_entity) REFERENCES entities(id_entity)
);


------------------------------------------------------------
-- Table: logs
------------------------------------------------------------
CREATE TABLE logs(
	id_log        INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT ,
	time_log      NUMERIC NOT NULL ,
	action_log    TEXT NOT NULL ,
	info_log      TEXT NOT NULL
);


------------------------------------------------------------
-- Table: orders_form
------------------------------------------------------------
CREATE TABLE orders_form(
	id_order              INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT ,
	time_sell             NUMERIC NOT NULL ,
	time_buy              NUMERIC NOT NULL ,
	id_entity             INTEGER NOT NULL ,
	id_entity_entities    INTEGER NOT NULL

	,CONSTRAINT orders_form_entities_FK FOREIGN KEY (id_entity) REFERENCES entities(id_entity)
	,CONSTRAINT orders_form_entities0_FK FOREIGN KEY (id_entity_entities) REFERENCES entities(id_entity)
);


------------------------------------------------------------
-- Table: type_product
------------------------------------------------------------
CREATE TABLE type_product(
	id_type_product      INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT ,
	name_type_product    TEXT NOT NULL
);


------------------------------------------------------------
-- Table: product
------------------------------------------------------------
CREATE TABLE product(
	id_product              INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT ,
	isDelete                INTEGER NOT NULL ,
	name_product            TEXT NOT NULL ,
	price_product           REAL NOT NULL ,
	quantity_stock          INTEGER NOT NULL ,
	centiliter_capacity     REAL NOT NULL ,
	centiliter_remainder    REAL NOT NULL ,
	alarm_count             INTEGER NOT NULL ,
	image_product           TEXT NOT NULL ,
	id_type_product         INTEGER NOT NULL

	,CONSTRAINT product_type_product_FK FOREIGN KEY (id_type_product) REFERENCES type_product(id_type_product)
);


------------------------------------------------------------
-- Table: belong
------------------------------------------------------------
CREATE TABLE belong(
	id_address    INTEGER NOT NULL ,
	id_city       INTEGER NOT NULL,
	CONSTRAINT belong_PK PRIMARY KEY (id_address,id_city)

	,CONSTRAINT belong_addresses_FK FOREIGN KEY (id_address) REFERENCES addresses(id_address)
	,CONSTRAINT belong_cities0_FK FOREIGN KEY (id_city) REFERENCES cities(id_city)
);


------------------------------------------------------------
-- Table: locate
------------------------------------------------------------
CREATE TABLE locate(
	id_address    INTEGER NOT NULL ,
	id_entity     INTEGER NOT NULL,
	CONSTRAINT locate_PK PRIMARY KEY (id_address,id_entity)

	,CONSTRAINT locate_addresses_FK FOREIGN KEY (id_address) REFERENCES addresses(id_address)
	,CONSTRAINT locate_entities0_FK FOREIGN KEY (id_entity) REFERENCES entities(id_entity)
);


------------------------------------------------------------
-- Table: compose_order
------------------------------------------------------------
CREATE TABLE compose_order(
	id_order      INTEGER NOT NULL ,
	id_product    INTEGER NOT NULL ,
	quantity      INTEGER NOT NULL,
	CONSTRAINT compose_order_PK PRIMARY KEY (id_order,id_product)

	,CONSTRAINT compose_order_orders_form_FK FOREIGN KEY (id_order) REFERENCES orders_form(id_order)
	,CONSTRAINT compose_order_product0_FK FOREIGN KEY (id_product) REFERENCES product(id_product)
);


------------------------------------------------------------
-- Table: compose_product
------------------------------------------------------------
CREATE TABLE compose_product(
	id_product                    INTEGER NOT NULL ,
	id_product_compose_product    INTEGER NOT NULL,
	CONSTRAINT compose_product_PK PRIMARY KEY (id_product,id_product_compose_product)

	,CONSTRAINT compose_product_product_FK FOREIGN KEY (id_product) REFERENCES product(id_product)
	,CONSTRAINT compose_product_product0_FK FOREIGN KEY (id_product_compose_product) REFERENCES product(id_product)
);


------------------------------------------------------------
-- Table: plannings
------------------------------------------------------------
CREATE TABLE plannings(
	id_planning              INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT ,
	isDelete_planning        INTEGER NOT NULL ,
	begin_planning           NUMERIC NOT NULL ,
	end_planning             NUMERIC NOT NULL ,
	comment                  TEXT NOT NULL ,
	id_entity                INTEGER ,
	id_employee              INTEGER ,
	id_planning_plannings    INTEGER

	,CONSTRAINT plannings_employees_FK FOREIGN KEY (id_entity,id_employee) REFERENCES employees(id_entity,id_employee)
	,CONSTRAINT plannings_plannings0_FK FOREIGN KEY (id_planning_plannings) REFERENCES plannings(id_planning)
);


