/*
 * 第10课 分组数据
 * 2019/10/11
 */
 
--
select vend_id, count(*) as num_prods from Products group by vend_id; 

select cust_id, count(*) as orders from orders group by cust_id having count(*) >= 2;

select vend_id, count(*) as num_prods from products where prod_price >= 4 group by vend_id having count(*) >= 2;

select order_num, count(*) as items from orderitems group by order_num having count(*) >= 3 order by items, order_num;