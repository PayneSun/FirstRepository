=start
	错误处理
	18_special_variables.pl
	2019/3/13
=cut


# $_默认输入和模式匹配内容

# $!错误值或错误信息

# $0正在执行的脚本的文件名
print "$0\n";

# $[数组的第一个元素的下标，默认是0

# $$运行当前脚本程序的进程号
print "$$\n";

# __FILE__当前文件名
print __FILE__ . "\n";

# __LINE__当前行号
print __LINE__ . "\n";

# __PACKAGE__当前包名
print __PACKAGE__ . "\n";

# $s~当前报表输出格式的名称，默认值是文件句柄名
