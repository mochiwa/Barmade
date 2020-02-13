/**************************************************************\
					       Product
\**************************************************************/
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
	IF (v_isDelete = TRUE) THEN
		IF ((select * from compose_product WHERE id_ingredient=v_id) IS NOT NULL) THEN
			v_isDelete=FALSE;
		END IF;
	END IF;

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