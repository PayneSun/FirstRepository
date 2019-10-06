/*
 * 第3课 排序检索数据
 * 2019/10/06
 */
 
-- 排序数据
select prod_name from Products order by prod_name;

-- 按多个列排序
select prod_id, prod_price, prod_name from Products order by prod_price, prod_name;

-- 按列位置排序
select prod_id, prod_price, prod_name from Products order by 2, 3;

-- 指定排序方向
select prod_id, prod_price, prod_name from Products order by prod_price desc, prod_name;