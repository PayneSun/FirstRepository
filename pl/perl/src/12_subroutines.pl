=start
	12_subroutines.pl
	2019/3/8
=cut	

sub Hello{
	print "Hello, World\n";
}
Hello();

# 传参
sub Average{
	$n = scalar(@_);
	$sum = 0;
	
	foreach $item (@_) {
		$sum += $item;	
	}
	$average = $sum / $n;
	
	print "所有的参数：@_\n";
	print "第一个参数：$_[0]\n";
	print "参数平均值：$average\n";
}
Average(10, 20, 30);

# 传数组
sub PrintList {
	my @list = @_;
	print "列表为：@list\n";
}
$a = 10;
@b = (1, 2, 3);
PrintList($a, @b);

# 传哈希
sub PrintHash {
	my (%hash) = @_;
	
	foreach my $key (keys %hash) {
		my $value = $hash{$key};
		print "$key: $value\n";
	}
}
%hash = ('name'=>'sunpeng', 'age'=>18);
PrintHash(%hash);

# 返回值
sub add_a_b {
	# 不使用return
	$_[0] + $_[1];
	
	#使用return
#	return $_[0] + $_[1];
}
print add_a_b(1, 2) . "\n";

# Perl中的变量默认是全局的，my关键定义局部变量，local关键字将全局变量临时局部化
$str = "Lowbee";
sub PrintStr{
	local $str;
	$str = "Newbee";
	PrintMe();
	print $str . "\n";
} 
sub PrintMe{
	print $str . "\n";
}
PrintStr();
print $str . "\n";

# 静态变量
use feature 'state';
sub PrintCount {
	state $count = 0;
	print "counter: $count\n";
	$count++;
}
for (1..5) {
	PrintCount();
}
