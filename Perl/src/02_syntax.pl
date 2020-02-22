=start
	基础语法
	02_syntax.pl
	2019/3/5
=cut

#打印
print "Hello, World\n";
print("Hello, World\n");

# 变量
$a = 10;
print "a = $a\n";
#print 'a = $a\n';

# Here文档
$var = <<"EOF";
这是一个Here文档实例，使用双引号。可以在这输入字符串和变量。例如：a = $a
EOF
print "$var\n";
