/*
 * 第7课 创建计算字段
 * 2019/10/11
 */
 
-- 拼接字段
select * from vendors;
select concat(vend_name, '(', vend_country, ')') from vendors order by vend_name;
select concat(vend_name, '(', vend_country, ')') as vend_title from vendors order by vend_name;

-- 执行算术计算
select * from orderitems;
select prod_id, quantity, item_price, quantity * item_price as expanded_price from orderitems where order_num = 20008;