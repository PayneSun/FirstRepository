/*
 * 第14课 组合查询
 * 2019/10/23
 */

select cust_name, cust_contact, cust_email from customers where cust_state in ('IL', 'IN', 'MI')
union
select cust_name, cust_contact, cust_email from customers where cust_name = 'Fun4All';

select cust_name, cust_contact, cust_email from customers where cust_state in ('IL', 'IN', 'MI')
union all
select cust_name, cust_contact, cust_email from customers where cust_name = 'Fun4All';

select cust_name, cust_contact, cust_email from customers where cust_state in ('IL', 'IN', 'MI')
union
select cust_name, cust_contact, cust_email from customers where cust_name = 'Fun4All'
order by cust_name, cust_contact;