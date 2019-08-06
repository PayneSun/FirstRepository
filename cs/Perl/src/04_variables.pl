=start
	变量
	04_variables.pl
	2019/3/6
=cut

# use strict语句可以让所有变量需要强制声明类型

# 标量变量
$age = 25;
$name = "runoob";
$salary = 145.67;
print "Age = $age\n";
print "name = $name\n";
print "salary = $salary\n";

# 数组变量
@ages = (25, 30, 40);
@names = ("google", "runoob", "taobao");
print "\$ages[1] = $ages[1]\n";
print "\$names[1] = $names[1]\n";

# 哈希变量
%data = ('google', 45, 'taobao', 40);
print "\$data{'google'} = $data{'google'}\n";

# 变量上下文
@names = ("google", "runoob", "taobao");
@copy = @names;		# 复制数组
$size = @names;		# 数组赋值给标量，返回数组元素个数
print "\@copy: @copy\n";
print "\$size: $size\n";
