/*
 * 第13课 创建高级联结
 * 2019/10/23
 */
 
select cust_name, cust_contact
from customers as c, orders as o, orderitems as oi
where c.cust_id = o.cust_id and oi.order_num = o.order_num and prod_id = 'RGAN01';

-- 自联结
select cust_id, cust_name, cust_contact from customers
where cust_name = (select cust_name from customers where cust_contact = 'Jim Jones');
select c1.cust_id, c1.cust_name, c1.cust_contact from customers as c1, customers as c2
where c1.cust_name = c2.cust_name and c2.cust_contact = 'Jim Jones';

-- 自然联结
select c.*, o.order_num, o.order_date, oi.prod_id, oi.quantity, oi.item_price
from customers as c, orders as o, orderitems as oi
where c.cust_id = o.cust_id and oi.order_num = o.order_num and prod_id = 'RGAN01';

-- 外联结
select customers.cust_id, orders.order_num from customers inner join orders on customers.cust_id = orders.cust_id;
select customers.cust_id, orders.order_num from customers left outer join orders on customers.cust_id = orders.cust_id;

--
select customers.cust_id, count(orders.order_num) as num_ord
from customers inner join orders on customers.cust_id = orders.cust_id
group by customers.cust_id;