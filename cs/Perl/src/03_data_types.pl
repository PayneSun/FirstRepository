=start
	数据类型
	03_data_types.pl
	2019/3/5
=cut


# Perl有三个基础的数据类型：标量、数组、哈希

# 标量，以$开头
$myfirst = 123;

# 数组，以@开头
@arr = (1, 2, 3);

# 哈希，以%开头
%h = ('a' => 1, 'b' => 2);

# 整型
$x = 12345;

# 浮点数，浮点寄存器不能精确地存贮浮点数，从而产生误差
$value1 = 9.01e+21 + 0.01 - 9.01e+21;
$value2 = 9.01e+21 - 9.01e+21 + 0.01;
#print($value1);
#print($value2);

# \u：只有h会转换为大写
$str = "\uhello";
print("$str\n");

# \U：所有字母都会转换为大写
$str = "\Uhello";
print("$str\n");

# \U\E：UE之间的字母都会转换为大写
$str = "\Uhel\Elo";
print("$str\n");
