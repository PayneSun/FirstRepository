=start
	时间日期
	13_references.pl
	2019/3/8
=cut

# 创建引用，在变量名前加\
$foo = 10;
$sref = \$foo;	# 标量变量引用
$aref = [1, "foo", undef, 13];	# 匿名数组引用
$href = {APR => 4, AUG => 8};	# 匿名哈希引用
$fref = sub { print "foo\n"; };	# 匿名子程序引用

# 取消引用，在引用前加$、@、%
$var = 10;
$r = \$var;
print "type of r: ", ref($r), "\n";
print "\$var: ", $$r, "\n";
@var = (1..5);
$r = \@var;
print "type of r: ", ref($r), "\n";
print "\@var: ", @$r, "\n";
%var = ('a', 10, 'b', 20);
$r = \%var;
print "type of r: ", ref($r), "\n";
print "\$var: ", %$r, "\n";

# 引用函数，\&
sub PrintHash{
	my (%hash) = @_;
	foreach $item (%hash) {
		print "elem: $item\n";
	}
}
%var = ('fc', 10, 'ms', 20);
$cref = \&PrintHash;
&$cref(%var);
