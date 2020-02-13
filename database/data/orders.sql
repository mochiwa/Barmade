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