=start
	数组
	06_arrays.pl
	2019/3/6
=cut

# 创建数组
@array1 = (1, 2, "hello");
@array2 = qw/1 2 3/;
print "\@array1 = @array1\n";
print "\@array2 = @array2\n";

# 数组序列号
@var_num = (1..10);
@var_alp = ('a'..'z');
print "\@var_num = @var_num\n";
print "\@var_alp = @var_alp\n";

# 数组大小
@array = (1, 2, 3);
$array[50] = 4;
$size = @array;
print "数组大小：$size\n";
print "最大索引：$#array\n";

# 添加和删除数组元素
@site = ("google", "facebook", "microsoft");
print "\@site = @site\n";
push(@site, "baidu");		#在数组尾部追加元素
print "\@site = @site\n";
unshift(@site, "huawei");	#在数组首部追加元素
print "\@site = @site\n";
pop(@site);					#删除数组尾部元素
print "\@site = @site\n";
shift(@site);				#移除数组首部元素
print "\@site = @site\n";

# 切割数组
@alpha0 = ('A'..'Z');
@alpha1 = @alpha0[0,1,2];
@alpha2 = @alpha0[0..2];
print "\@alpha1 = @alpha1\n";
print "\@alpha2 = @alpha2\n";

#替换数组元素
@nums = (0..9);
print "\@nums = @nums\n";
splice(@nums, 5, 5, (11..15));
print "\@nums = @nums\n";

# 将字符串转换为数组
$var_str = "A-B-C";
@var_arr = split('-', $var_str);
print "\$var_arr[1]: $var_arr[1]\n";

# 将数组转换为字符串
@array = (1..5);
$varst = join('*', @array);
print "\$varst: $varst\n";

# 数组排序
@nums = (9, 4, 6, 7, 3, 5);
@rest = sort(@nums);
print "\@rest = @rest\n";

# 特殊变量$[
@sites = qw(ms fc qa);
$[ = 1;
print "\@sites[1]: $sites[1]\n";

# 合并数组
@nums = (1, 3, (4, 5, 6));
print "numbers = @nums\n";
@odd = (1, 3, 5);
@even = (2, 4, 6);
@nums = (@odd, @even);
print "numbers = @nums\n";

