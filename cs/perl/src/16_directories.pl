=start
	目录操作
	16_directories.pl
	2019/3/12
=cut

# 显示目录下的所有文件
$dir1 = "*";
@files1 = glob($dir1);
foreach (@files1) {
	print $_ . "\n";
}

# 显示目录下所有以.pl结尾的文件
$dir2 = "*.pl";
@files2 = glob($dir2);
foreach (@files2) {
	print $_ . "\n";
}
	
# 列出目录下的所有文件
opendir (DIR, '..') or die "无法打开目录，$！";
while ($file = readdir DIR) {
	print "$file\n";
}
closedir DIR;

# 创建新目录
$dir = "tmpdir";
mkdir ($dir) or die "无法创建$dir目录，$!";
print "目录创建成功\n";

# 删除目录
$dir = ".\\tmpdir";
rmdir ($dir) or die "无法删除$dir目录，$!";
print "目录删除成功\n";

# 切换目录
$dir = "..\\src";
chdir ($dir) or die "无法切换目录到$dir，$!";
print "当前目录为$dir\n";
