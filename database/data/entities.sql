/**************************************************************\
					       ENTITIES
\**************************************************************/
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


-----------------------------------------
--	FUNCTIONS
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




CREATE OR REPLACE FUNCTION f_update_entity(v_id INT,v_delete BOOL ,v_name TEXT,v_forename TEXT,v_phone TEXT,v_birthday DATE, v_code TEXT,v_picture TEXT,v_id_street INT)
RETURNS void AS $$
BEGIN
	UPDATE entities SET isDelete_entity=v_delete, name_entity=v_name, forename_entity=v_forename, phone_entity=v_phone, birthday_entity=v_birthday, code_entity=v_code, picture_entity=v_picture , id_street=v_id_street WHERE id_entity=v_id; 
END $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION f_get_entities()
RETURNS SETOF entities AS $$
BEGIN
	RETURN QUERY SELECT * FROM entities;
END $$ LANGUAGE plpgsql;

-----------------------------------------
--	TRIGGERS
-----------------------------------------
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

CREATE OR REPLACE FUNCTION tf_delete_entity()
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
EXECUTE PROCEDURE tf_delete_entity();