=start
	哈希
	07_hashes.pl
	2019/3/6
=cut

# 创建哈希
%data1 = ('google', 'google.com', 'facebook', 'facebook.com');
%data2 = ('google'=>'google.com', 'facebook'=>'facebook.com');
%data3 = (-google=>'google.com', -facebook=>'facebook.com');
$data4{'google'} = 'google.com';
$data4{'facebook'} = 'facebook.com';

# 访问哈希元素
print "data1{'google'}: $data1{'google'}\n";
print "data2{'google'}: $data2{'google'}\n";
print "data3{'google'}: $data3{-google}\n";
print "data4{'google'}: $data4{'google'}\n";

# 读取哈希值
%data = (-taobao=>45, -google=>30, -runoob=>40);
@array = @data{-taobao, -google};
print "\@array: @array\n";

# 读取哈希的key和value
%data = ('google'=>'google.com', 'facebook'=>'facebook.com');
@dks = keys %data;
print "\@dks: @dks\n";
@dvs = values %data;
print "\@dvs: @dvs\n";

# 检查元素是否存在
%data = ('google'=>'google.com', 'facebook'=>'facebook.com');
if (exists($data{'facebook'})) {
	print "$data{'facebook'}\n";
} else {
	print "no exists!\n";
}

# 添加或删除元素
%data = ('google'=>'google.com', 'facebook'=>'facebook.com');
$data{'baidu'} = 'baidu.com';
$size = keys %data;
print "\$size = $size\n";
delete $data{'baidu'};
$size = keys %data;
print "\$size = $size\n";
