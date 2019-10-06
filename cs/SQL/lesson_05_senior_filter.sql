/*
 * 第5课 高级数据过滤
 * 2019/10/06
 */

-- 组合WHERE子句
select prod_id, prod_price, prod_name from Products where vend_id = 'DLL01' and prod_price <= 4;
select prod_name, prod_price, vend_id from Products where vend_id = 'DLL01' or vend_id = 'BRS01';
select prod_name, prod_price, vend_id from Products where (vend_id = 'DLL01' or vend_id = 'BRS01') and prod_price >= 10;
select prod_name, prod_price, vend_id from Products where vend_id in ('DLL01', 'BRS01') order by prod_price;
select prod_name, prod_price, vend_id from Products where not vend_id in ('DLL01', 'BRS01') order by prod_price;