/*
 * src/ch_7/solution.c
 *
 * 2019/3/2
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

void solution_7_1(char **argv);
void solution_7_2(void);
void solution_7_3(void);
void solution_7_4(char *, ...);
void solution_7_5(FILE *f1, FILE *f2);
void solution_7_6(void);
void solution_7_7(void);
void solution_7_8(void);
void solution_7_9(void);


int main(int argc, char *argv[])
{
//	solution_7_1(argv);

//	int ival = 5;
//	solution_7_4("%d\n", ival);

	FILE *f1, *f2;
	f1 = fopen("file1.txt", "r");
	f2 = fopen("file2.txt", "r");
	solution_7_5(f1, f2);


	return 0;
}


/*
 *
 */
void solution_7_1(char **argv)
{
	printf("Before: %s\nAfter: ", argv[0]);
	for (; *argv[0] != '\0';++argv[0]) {
		if (isalpha(*argv[0])) {
			putchar(toupper(*argv[0]));
		} else {
			putchar(*argv[0]);
		}
	}
}


/*
 * todo
 */
void solution_7_2(void)
{
}


/*
 * todo
 */
void solution_7_3(void)
{
}


/*
 * todo
 * minscanf
 */
void solution_7_4(char *fmt, ...)
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
 * todo
 */
void solution_7_5(FILE *f1, FILE *f2)
{
	char line1[512], line2[512];

	while (fgets(line1, 512, f1) && fgets(line2, 512, f2)) {
		if (strcmp(line1, line2)) {
			fputs(line1, stdout);
			fputs(line2, stdout);
			break;
		}
	}
}


/*
 * todo
 */
void solution_7_6(void)
{
}


/*
 * todo
 */
void solution_7_7(void)
{
}


/*
 * todo
 */
void solution_7_8(void)
{
}


/*
 * todo
 */
void solution_7_9(void)
{
}
