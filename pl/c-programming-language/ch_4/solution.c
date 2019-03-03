/*
 * src/ch_4/solution.c
 *
 * 2019/2/19
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define SWAP(t, x, y) { t z = x; x = y; y = z; }

int solution_4_1(char s[], char t[]);
double solution_4_2(char s[]);
void solution_4_12(int x);
void solution_4_13(char s[], int left, int right);

int main()
{
//	char s[] = "abcabcabc";
//	char t[] = "abc";
//	printf("Result: %d\n", solution_4_1(s, t));

//	char s[] = "123.45e-6";
//	printf("Result: %f\n", solution_4_2(s));

//	int x = -1000;
//	solution_4_12(x);

//	char s[] = "ABCDEF";
//	puts(s);
//	solution_4_13(s, 0, strlen(s)-1);
//	puts(s);

	/* solution_4_14 */
//	int x = 1, y = 2;
//	printf("x=%d\ty=%d\n", x, y);
//	SWAP(int, x, y)
//	printf("x=%d\ty=%d\n", x, y);

	return 0;
}


/*
 * strrindex(s,t)
 */
int solution_4_1(char s[], char t[])
{
	int i, j, k;

	for (i = strlen(s); i >= 0; --i) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
			;
		}
		if (k > 0 && t[k] == '\0') {
			return i;
		}
	}

	return -1;
}


/*
 * atof
 */
double solution_4_2(char s[]) {
	double val, power, result = 0.0;
	int i, sign;

	for (i = 0; isspace(s[i]); i++) {
		;
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.') {
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	result = sign * val / power;

	int sign_index = -1;
	if (s[i] != '\0') {
		if (s[i] == 'e' || s[i] == 'E') {
			++i;
		}
		if(s[i] == '+' || s[i] == '-') {
			sign_index = i;
			++i;
		}
		for (val = 0.0; isdigit(s[i]); i++) {
			val = 10.0 * val + (s[i] - '0');
		}
		if (s[sign_index] == '+') {
			result *= pow(10, val);
		} else if (s[sign_index] == '-') {
			result /= pow(10, val);
		}
	}

	return result;
}


void solution_4_3(void)
{
	//todo
}


void solution_4_4(void)
{
	//todo
}


void solution_4_5(void)
{
	//todo
}


void solution_4_6(void)
{
	//todo
}


void solution_4_7(void)
{
	//todo
}


void solution_4_8(void)
{
	//todo
}


void solution_4_9(void)
{
	//todo
}


void solution_4_10(void)
{
	//todo
}


void solution_4_11(void)
{
	//todo
}


/*
 * itoa
 */
void solution_4_12(int x)
{
	if (x < 0) {
		putchar('-');
		x = -x;
	}

	if (x / 10) {
		solution_4_12(x / 10);
	}
	putchar(x % 10 + '0');
}


void solution_4_13(char s[], int left, int right)
{
	if (left >= right) {
		return;
	} else {
		char c = s[left];
		s[left] = s[right];
		s[right] = c;
		solution_4_13(s, ++left, --right);
	}
}


void solution_4_14(void)
{
	//todo
}
