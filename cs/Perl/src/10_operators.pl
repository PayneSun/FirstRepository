=start
	运算符
	10_operators.pl
	2019/3/7
=cut

use constant true => 1;
use constant TRUE => 1;
use constant false => 0;
use constant FALSE => 0;

# 乘幂
$a = 3;
$b = 4;
$c = $a ** $b;
print "\$c = $c\n";

# 检查两个数是否相等
$c = $a <=> $b;
print "\$c = $c\n";

# 字符串比较
# lt小于，gt大于，le小于等于，ge大于等于，eq等于，ne不等于，cmp比较

# 逻辑运算符
# and，&&，or，||，not
$a = true;
$b = false;
$c = ($a and $b);
print "\$a and \$b = $c\n";

# 引号运算，q{}为字符串添加单引号，qq{}为字符串添加双引号，qx{}为字符串添加反引号
$a = 10;
$b = q{a = $a};
print "q{a = \$a} = $b\n";
$b = qq{a = $a};
print "q{a = \$a} = $b\n";
$t = qx{date};
print "qx{a = \$a} = $t\n";

# 其他运算符
# 点号（.）用于连接两个字符串
# x运算符返回字符串重复的次数，例如：('-' x 3)输出---。
