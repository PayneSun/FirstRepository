=start
	时间日期
	11_datetime.pl
	2019/3/8
=cut

# time()、localtime()、gmtime()

#@months = qw(一月 二月 三月 四月 五月 六月 七月 八月 九月 十月 十一月 十二月);
#@days = qw(星期日 星期一 星期二 星期三 星期四 星期五 星期六);

$datestr = localtime();
$gmdtstr = gmtime();
print "$datestr\n";
print "$gmdtstr\n";

# 格式化日期和时间
($sec, $min, $hour, $mday, %mon, $year, $wday, $yday, $isdst) = localtime();
printf("%02d:%02d:%02d\n", $hour, $min, $sec);

# 新纪元时间
$epoc = time();
print "从1970年1月1日累计的秒数为：$epoc\n";

# POSIX函数strftime()
use POSIX qw(strftime);
$datestr = strftime "%Y-%m-%d %H:%M:%S", localtime;
printf("$datestr\n");