=start
	错误处理
	17_error_handling.pl
	2019/3/13
=cut

# warn函数触发一个警告信息，输出到STDERR
chdir("/etc") or warn "无法切换到目录";

# die函数执行退出
chdir("/etc") or die "无法切换到目录";
