/*
 * 第8课 使用函数处理数据
 * 2019/10/11
 */

--
select vend_name, upper(vend_name)  as vend_name_upcase from vendors order by vend_name;

-- 
select order_num from orders where year(order_date) = 2012;  -- for MySQL and MariaDB