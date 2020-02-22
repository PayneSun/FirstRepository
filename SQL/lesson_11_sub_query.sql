/*
 * 第11课 使用子查询
 * 2019/10/12
 */
 
--
select order_num from orderitems where prod_id = 'RGAN01';

select cust_id from orders where order_num in (select order_num from orderitems where prod_id = 'RGAN01');

select cust_name, cust_contact from customers
	where cust_id in (select cust_id from orders 
						where order_num in (select order_num from orderitems 
												where prod_id = 'RGAN01'));

select cust_name, cust_state, (select count(*) from orders where orders.cust_id = customers.cust_id) as orders
from customers order by cust_name;