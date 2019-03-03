/*
 * src/ch_3/solution.c
 *
 * 2019/2/15
 */


#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef enum radix {
	BIN = 2, OCT = 8, DEC = 10, HEX = 16
} enum_radix;

int solution_3_1(int x, int v[], int n);
void solution_3_2(char s[], char t[]);
void solution_3_3(char s[], char t[]);
void solution_3_4(int n, char s[]);
void solution_3_5(unsigned n, char s[], enum_radix b);
void solution_3_6(int n, char s[], int mw);

int main()
{
//	int array[5] = {1, 2, 3, 4, 5};
//	int x = 5;
//	printf("the location of %d is in: %d\n", x, solution_3_1(x, array, 5));

//	char t[] = "cnnv avjfa	vsdjkf\nvsvsf";
//	char s[100];
//	solution_3_2(s, t);

//	char s[] = "a-dE-M0-9-";
//	char t[100];
//	solution_3_3(s, t);

//	char s[100];
//	int n = INT_MIN;
//	solution_3_4(n, s);

//	unsigned n = 123;
//	enum_radix er = HEX;
//	char s[100];
//	solution_3_5(n, s, er);

	char s[100];
	int n = 123;
	int mw = 10;
	solution_3_6(n, s, mw);
}


/*
 * binsearch
 */
int solution_3_1(int x, int v[], int n) 
{
	int low = 0,
		high = n - 1,
		mid = (low + high) / 2;

	while (v[mid] != x && low <= high) {
		if (v[mid] > x) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}

	if (v[mid] == x)
		return mid;
	else
		return -1;
}


/*
 * escape(s,t)
 */
void solution_3_2(char s[], char t[])
{
	int i = 0, j = 0;

	while (t[j] != '\0') {
		switch (t[j]) {
			case '\n':
				s[i++] = '\\';
				s[i++] = 'n';
				break;
			case '\t':
				s[i++] = '\\';
				s[i++] = 't';
				break;
			case ' ':
				s[i++] = '\\';
				s[i++] = 'e';
				break;
			default:
				s[i++] = t[j];
				break;
		}
		++j;
	}
	s[i] = '\0';

	printf("Before copy: %s\n", t);
	printf("After  copy: %s\n", s);
}


/*
 * expand(s1, s2)
 */
void solution_3_3(char s[], char t[])
{
	int i, j = 0;
	char lc, rc;

	for (i = 0; i < strlen(s); ++i) {
		if (s[i] == '-') {
			if (i == 0 || i == strlen(s) - 1) {
				t[j++] = s[i];
			} else {
				lc = s[i-1];
				rc = s[i+1];
				for (int k = 1; k < rc - lc; ++k) {
					t[j++] = lc + k;
				}
			}
		} else {
			t[j++] = s[i];
		}
	}
	t[j] = '\0';

	printf("Before expand: %s\n", s);
	printf("After  expand: %s\n", t);
}


/*
 * itoa
 */
void solution_3_4(int n, char s[])
{
	printf("Integer: %d\n", n);

	int i, sign, extra;
	if ((sign = n) < 0) {
		extra = (-1) * (n % 10);
		n = (-1) * (n / 10);
		i = 0;
		s[i++] = extra + '0';
	}

	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';

	//reverse(s);
	int c;
	for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

	printf("String : %s\n", s);
}


/*
 * itob(n,s,b)
 */
void solution_3_5(unsigned n, char s[], enum_radix b)
{
	printf("Integer: %d\n", n);
	int	i = 0;

	do {
		if (b == HEX) {
			s[i++] = (n % b > 9) ? (n % b - 10 + 'A') : (n % b + '0');
		} else {
			s[i++] = n % b + '0';
		}
	} while ((n /= b) > 0);

	if (b == OCT) {
		s[i++] = '0';
	} else if (b == HEX) {
		s[i++] = 'X';
		s[i++] = '0';
	}
	s[i] = '\0';

	int c;
	for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

	printf("String : %s\n", s);
}


/*
 *
 */
void solution_3_6(int n, char s[], int mw)
{
	printf("Integer: %d\n", n);

	int i = 0, sign, extra;
	if ((sign = n) < 0) {
		extra = (-1) * (n % 10);
		n = (-1) * (n / 10);
		s[i++] = extra + '0';
	}

	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0) { s[i++] = '-'; }
	s[i] = '\0';

	//reverse(s);
	char c;
	for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

	//insert blanket
	if (mw > strlen(s)) {
		int i, j, len = strlen(s);
		for (i = mw, j = len; j >= 0; --i, --j) {
			s[i] = s[j];
		}
		while(i >= 0) {
			s[i--] = ' ';
		}
	}

	printf("String : %s\n", s);
}
