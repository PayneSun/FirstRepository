/*
 * src/ch_8/example.c
 *
 * 2019/2/28
 */
 
#include "syscalls.h"


/*
 * 无缓冲的单字符输入
 */
int getchar(void)
{
	char c;
	
	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}


/*
 * 简单的带缓冲区的版本
 */
int getchar(void)
{
	static char buf[BUFSIZ];
	static char *bufp = buf;
	static int n = 0;
	
	if (n == 0) {
		n = read(0, buf, sizeof buf);
		bufp = buf;
	}
	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
} 
