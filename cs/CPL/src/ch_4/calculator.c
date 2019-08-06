/*
 * src/ch_4/calculator.cs
 *
 * 2019/2/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP	100
#define NUMBER	'0'
#define MAXVAL	100
#define BUFFSIZE	100

int sp = 0;
double val[MAXVAL];

int bufp = 0;
char buf[BUFFSIZE];

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0) {
				push (pop() / op2);
			} else {
				printf("error: zero divisor\n");
			}
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unkown command %s\n", s);
			break;
		}
	}

	return 0;
}


void push(double f)
{
	if (sp < MAXVAL) {
		val[sp++] = f;
	} else {
		printf("error: stack full, can't push %g\n", f);
	}
}


double pop(void)
{
	if (sp > 0) {
		return val[sp--];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}


/*
 * 获取下一个运算符或数值操作数
 */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t') {
		;
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		return c;
	}
	i = 0;
	if (isdigit(c)) {	/* 收集整数部分 */
		s[i] = c;
		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}
	if (c == '.') {	/* 收集小数部分 */
		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}

	return NUMBER;
}


int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c)
{
	if (bufp >= BUFFSIZE) {
		printf("ungetch: too many characters\n");
	} else {
		buf[bufp++] = c;
	}
}
