/*
 * src/ch_7/example.c
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/*
 * 带有可变参数表的简化的printf函数
 */
void minprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++) {
				putchar(*sval);
			}
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}


/*
 * 从iop指向的文件中最多读取n-1个字符，再加上一个NULL
 */
char *fgets(char *s, int n, FILE *iop)
{
	register int c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF) {
		if ((*cs++ = c) == '\n') {
			break;
		}
	}
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}


/*
 * 将字符串s输出到iop指向的文件中
 */
int fputs(char *s, FILE *iop)
{
	int c;

	while (c = *s++) {
		putc(c, iop);
	}

	return ferror(iop) ? EOF : 1;
}


/*
 * 读入一个输入行，并返回其长度
 */
int getline(char *line, int max)
{
	if (fgets(line, max, stdin) == NULL) {
		return 0;
	} else {
		return strlen(line);
	}
}
