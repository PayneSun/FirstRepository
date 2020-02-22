/*
 * 第9课 汇总数据
 * 2019/10/11
 */

--
select avg(prod_price) as avg_price from products;
select avg(prod_price) as avg_price from products where vend_id = 'DLL01';

select count(*) as num_cust from customers;
select count(cust_email) as num_cust from customers;

select max(prod_price) as max_price from products;
select min(prod_price) as min_price from products;

select sum(quantity) as items_ordered from orderitems where order_num = 20005;
select sum(item_price * quantity) as total_price from orderitems where order_num = 20005;

select avg(distinct prod_price) as avg_price from products where vend_id = 'DLL01';
select count(*) as num_items, min(prod_price) as price_min, max(prod_price) as price_max, avg(prod_price) as price_avg from products;