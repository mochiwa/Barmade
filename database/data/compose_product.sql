/**************************************************************\
					       Product
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
