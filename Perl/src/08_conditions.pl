=start
	条件语句
	08_conditions.pl
	2019/3/7
=cut


# 三元运算符
$like = 10;
$stat = ($like > 5) ? "Like" : "Unlike";
print "\$stat = $stat\n";

# if-else
$a = "";
if ($a) {
	print "true\n";
} else {
	print "false\n";
}

# if-elsif
$a = 20;
if ($a < 20) {
	print "<20\n";
} elsif ($a < 30) {
	print "< 30\n";
} else {
	print ">= 30\n";
}

# unless
$a = 10;
unless ($a < 10) {
	print "\$a = $a\n";
}

# switch，case默认自带break，取消break通过next语句实现
use Switch;
$var = 10;
@array = (10, 20, 30);
%hash = ('key1'=>10, 'key2'=>20);
switch($var) {
	case 10 		{ print "数字10\n"; next; }
	case "a"		{ print "字符串a\n"; }
	case [1..5]		{ print "数字在列表中"; }
	case (\@array)	{ print "数字在数组中"; }
	case (\%hash)	{ print "在哈希"; }
	else			{ print "没有匹配的条件"; } 
}