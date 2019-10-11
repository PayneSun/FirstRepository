/*
 * 第6课 用通配符进行过滤
 * 2019/10/06
 */
 
--
select prod_id, prod_name from Products where prod_name like 'Fish%';
select prod_id, prod_name from Products where prod_name like '%bean bag%';
select prod_id, prod_name from Products where prod_name like 'F%y';
select prod_id, prod_name from Products where prod_name like '__ inch teddy bear';
select * from Customers;
select cust_contact from Customers where cust_contact like '[JM]%' order by cust_contact;