/*
 * 第4课 过滤数据
 * 2019/10/06
 */

-- 使用where子句
select prod_name, prod_price from Products where prod_price = 3.49;

-- 使用where子句操作符
select prod_name, prod_price from Products where prod_price < 10;
select vend_id, prod_name from Products where vend_id != 'DLL01';
select prod_name, prod_price from Products where prod_price between 5 and 10;
select * from Customers;
select * from Customers where cust_email is null;