=start
	循环语句
	09_loops.pl
	2019/3/7
=cut

# 循环类型：while、until、for、foreach、do..while
# 循环控制：next、last、continue、redo、goto

# while
$a = 10;
while ($a < 20) {
	print "$a ";
	$a = $a + 2;
}
print "\n";

# until
$a = 5;
until ($a > 10 ) {
	print "$a ";
	$a = $a + 2;
}
print "\n";

# for
for ($a = 0; $a < 5; $a += 1) {
	print "$a ";
}
print "\n";

# foreach
@list = (1..9);
foreach $a (@list) {
	print "$a ";
}
print "\n";

# do..while
$a = 10;
do {
	print "$a ";
	$a += 2;
} while ($a < 15);
print "\n";
