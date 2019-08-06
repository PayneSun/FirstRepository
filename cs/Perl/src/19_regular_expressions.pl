=start
	错误处理
	19_regular_expressions.pl
	2019/3/13
=cut

# 匹配操作符：m//，=~表示相匹配，!~表示不匹配
$bar = "I am a student, welcome to muc.";
if ($bar =~ /stu/) {
	print "匹配成功\n";
} else {
	print "匹配失败\n";
}

# 正则表达式变量
# $`：匹配部分的前一部分字符串
# $&：匹配的字符串
# $'：尚未匹配的剩余字符串
$str = "welcome to muc.";
$str =~ m/to/;
print "\$`：$`\n";
print "\$&：$&\n";
print "\$'：$'\n";

# 替换操作符：s///
$str = "hello perl, you are so bad.";
$str =~ s/bad/good/;
print $str . "\n";
$str =~ s/o/*/;
print $str . "\n";

# 转化操作符
$str = "welcome tooo beijing. 123 go.";

$str =~ tr/a-z/A-Z/;
print $str . "\n";

$str =~ tr/A-Z/a-z/s;
print $str . "\n";

$str =~ tr/\t //d;
print $str . "\n";

$str =~ tr/0-9/*/;
print $str . "\n";