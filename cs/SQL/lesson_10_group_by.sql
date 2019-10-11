/*
 * 第10课 分组数据
 * 2019/10/11
 */
 
--
select vend_id, count(*) as num_prods from Products group by vend_id; 

select cust_id, count(*) as orders from orders group by cust_id having count(*) >= 2;

select cust_id, count(*) as orders from orders where prod_name >= 4 group by cust_id having count(*) >= 2;