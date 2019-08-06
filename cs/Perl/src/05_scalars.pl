=start
	标量
	05_scalars.pl
	2019/3/6
=cut

# 数字标量
$integer = 200;
$float = 123.45;
$bigfloat = -1.2e-23;
$octal = 0377;
$hexa = 0xff;
print "\$integer = $integer\n";
print "\$float = $float\n";
print "\$bigfloat = $bigfloat\n";
print "\$octal = $octal\n";
print "\$hexa = $hexa\n";

# 字符串标量
$var = "ABC";
$double = "hello - $var";
print "\$var = $var\n";
print "\$double = $double\n";

# 标量运算
$str = "hello" . "world";	# 字符串连接
$num = 5 + 10;
$mix = $str . $num;
print "str = $str\n";
print "num = $num\n";
print "mix = $mix\n";

# 特殊字符串是单独的标记，不能写在字符串中
print "文件名：" . __FILE__ . "\n";
print "行   号：" . __LINE__ . "\n";
print "包   名：" . __PACKAGE__ . "\n";

# v字符：v开头后面跟数字，数字代表字符的ascii值，字符间用句号分割
$foo = v102.111.111;
print "\$foo = $foo\n"; 