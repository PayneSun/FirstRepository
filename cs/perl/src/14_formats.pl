=start
	时间日期
	14_formats.pl
	2019/3/8
=cut

$text = "one two three";
format STDOUT =
first: ^<<<<<
	$text
second: ^<<<<<
	$text
third: ^<<<<
	$text
.
write;

# 值域格式
format EMPLOYEE =
=============================
@<<<<<<<<<<<<<< @<<
$name, $age
@####.##
$salary
=============================
.
select(STDOUT);
$~ = EMPLOYEE;
@n = ("abc", "def", "ghi");
@a = (20, 30, 40);
@s = (100.00, 300.00, 500.00);

$i = 0;
foreach (@n) {
	$name = $_;
	$age = $a[$i];
	$salary = $s[$i++];
	write;
}

# 格式变量
$~ = "MYFORMAT";
write;
format MYFORMAT = # 定义格式MYFORMAT
=============================
	Text # 菜鸟教程
=============================
.
write;

# 输出到其它文件
if (open(MYFILE, ">tmp")) {
$~ = MYFORMAT;
write MYFILE;

format MYFILE = 
=============================
	输出到文件中
=============================
.
close MYFILE;
}

# 使用指定格式打印到默认文件中
if (open(MYFILE, ">>tmp")) {
select(MYFILE);	#使得默认文件变量的打印输出到MYFILE中
$~ = "OTHER";
write; #默认文件变量，打印到select指定的文件中，必使用$~指定的格式OTHER

format OTHER = 
=============================
	使用定义的格式输出到文件中
=============================
.
close MYFILE;
}
