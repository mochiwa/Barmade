/**************************************************************\
				SUPLLIERS	       
\**************************************************************/
CREATE TABLE public.suppliers(
	id_supplier       INT  NOT NULL,
	fax_supplier	  VARCHAR(50),
	CONSTRAINT suppliers_PK PRIMARY KEY (id_supplier)
)WITHOUT OIDS;


-----------------------------------------
--	FUNCTIONS
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

-----------------------------------------
--	TRIGGERS
-----------------------------------------
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