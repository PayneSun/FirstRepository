=start
	文件操作
	15_files.pl
	2019/3/12
=cut

# open函数，只读<
open(DATA, "<tmp") or die "无法打开文件，$!";
while (<DATA>) {
	print "$_";
}

# open，
# <只写
# +<写，不删除原文件
# +>写，先删除原文件
# +>>，在尾部追加写

# sysopen函数
# O_RDWR, O_RDONLY, O_WRONLY, O_CREAT, O_APPEND, O_TRUNC, O_EXCL, O_NONBLOCK

# close函数
close(DATA) || die "无法关闭文件";

#$name = <STDIN>;
#print "$name\n";

open(DATA, "<tmp") or die "无法打开数据";
@lines = <DATA>;
print @lines;
close(DATA);

# 文件重命名
rename ($file_name_1, $file_name_2);

# 删除文件
unlink ($file_name);
