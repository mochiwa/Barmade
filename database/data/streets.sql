/**************************************************************\
					       STREETS
\**************************************************************/
CREATE TABLE public.streets(
	id_street       SERIAL NOT NULL ,
	name_street     VARCHAR (50) NOT NULL ,
	number_street   VARCHAR (50) NOT NULL ,
	id_city			INT NOT NULL,
	CONSTRAINT streets_PK PRIMARY KEY (id_street)
)WITHOUT OIDS;


-----------------------------------------
--	FUNCTIONS
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
	UPDATE streets SET name_street=v_name, number_street=v_number,id_city=v_id_city WHERE id_street=v_id;
END $$ LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION f_get_streets()
RETURNS SETOF streets AS $$
BEGIN
	RETURN QUERY SELECT * FROM streets;
END $$ LANGUAGE plpgsql;
-----------------------------------------
--	TRIGGERS
-----------------------------------------
/**
 * @brief      check if tuple(street,number_street)exist and trim and lower 
 *
 * @note       Test:
 * 				tuple(street,number_street,id_city) exist -> raise error
 *
 * @author     mochiwa
 * @date       18-Apr-2019
 */
CREATE OR REPLACE FUNCTION ft_create_street()
RETURNS trigger AS $$
BEGIN
	new.name_street=LOWER(TRIM(new.name_street));
	new.number_street=LOWER(TRIM(new.number_street));
	IF EXISTS(select * from streets where name_street=new.name_street AND number_street=new.number_street AND id_city=new.id_city) THEN
		RAISE EXCEPTION '[ADDRESS][ERROR] the tuple already exist !';
	END IF;
	RETURN new;
END $$ LANGUAGE plpgsql;
CREATE TRIGGER t_create_street
BEFORE INSERT OR UPDATE ON streets
FOR EACH ROW
EXECUTE PROCEDURE ft_create_street();