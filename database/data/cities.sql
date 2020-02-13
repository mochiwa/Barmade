/**************************************************************\
					       CITIES
\**************************************************************/
CREATE TABLE public.cities(
	id_city     SERIAL NOT NULL ,
	name_city   VARCHAR (50) NOT NULL ,
	cp_city     VARCHAR (50) NOT NULL  ,
	CONSTRAINT cities_PK PRIMARY KEY (id_city)
)WITHOUT OIDS;

-----------------------------------------
--	FUNCTIONS
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

-----------------------------------------
--	TRIGGERS
-----------------------------------------

/**
 * @brief      check if tuple(city,cp) exist and  trim() and lower() city_name and cp
 *
 * @note       Test:
 * 				tuple(city,cp) exist -> raise error
 *
 * @author     mochiwa
 * @date       18-Apr-2019
 */
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