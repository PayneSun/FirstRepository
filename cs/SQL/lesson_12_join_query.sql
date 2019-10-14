/*
 * 第12课 创建联结
 * 2019/10/12
 */
 
--
select vend_name, prod_name, prod_price from vendors, products where vendors.vend_id = products.vend_id; 
select vend_name, prod_name, prod_price from vendors inner join products on vendors.vend_id = products.vend_id; 

--
select prod_name, vend_name, prod_price, quantity 
from orderitems, products, vendors 
where products.vend_id = vendors.vend_id and orderitems.prod_id = products.prod_id and order_num = 20007;