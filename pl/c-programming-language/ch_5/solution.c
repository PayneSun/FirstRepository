/*
 * src/ch_5/solution.c
 *
 * 2019/3/2
 */

#include <stdio.h>
#include <string.h>

void solution_5_1(void);
void solution_5_2(void);
void solution_5_3(char *, char *);
int solution_5_4(char *, char *);
void solution_5_5_1(char *, char *, int);
void solution_5_5_2(char *, char *, int);
int solution_5_5_3(char *, char *, int);
void solution_5_6(void);
void solution_5_7(void);
void solution_5_8(void);
void solution_5_9(void);
void solution_5_10(void);
void solution_5_11(void);
void solution_5_12(void);
void solution_5_13(void);
void solution_5_14(void);
void solution_5_15(void);
void solution_5_16(void);
void solution_5_17(void);
void solution_5_18(void);
void solution_5_19(void);
void solution_5_20(void);

int main()
{
//	char s[20] = "abc";
//	char t[] = "def";
//	solution_5_3(s, t);
//	printf("s=%s\n", s);

//	char s[] = "ABCDEFG";
//	char t[] = "EFG";
//	printf("result: %d\n", solution_5_4(s, t));

//	char s[10] = "ABCD";
//	char t[5] = "abcd";
//	solution_5_5_1(s, t, 3);
//	printf("s=%s\n", s);
//	solution_5_5_2(s, t, 3);
//	printf("s=%s\n", s);
//	printf("result: %d\n", solution_5_5_3(s, t, 3));

	return 0;
}



/*
 * todo
 */
void solution_5_1(void)
{
}


/*
 * todo
 */
void solution_5_2(void)
{
}


/*
 * 用指针方式实现strcat(s,t)
 */
void solution_5_3(char *s, char *t)
{
	printf("s=%s\n", s);
	printf("t=%s\n", t);
	while (*s != '\0') {
		s++;
	}
	for (;*t != '\0'; s++, t++) {
		*s = *t;
	}
	*s = '\0';
}


/*
 * strend(s,t)
 */
int solution_5_4(char *s, char *t)
{
	int i, ns, nt;

	ns = strlen(s);
	nt = strlen(t);
	for (i = 0; i < nt; i++) {
		if (s[ns - nt + i] != t[i]) {
			break;
		}
	}

	if (i == nt) {
		return 1;
	} else {
		return 0;
	}
}


/*
 * 实现strncpy(s,t,n)
 */
void solution_5_5_1(char *s, char *t, int n)
{
	int i = 0;
	for (i = 0; *t != '\0' && i < n; ++i) {
		*s = *t;
		s++;
		t++;
	}
	*s = '\0';
}


/*
 * 实现strncat(s,t,n)
 */
void solution_5_5_2(char *s, char *t, int n)
{
	while (*s != '\0') {
		s++;
	}

	int i;
	for (i = 0; *t != '\0' && i < n; ++i) {
		*s = *t;
		s++;
		t++;
	}
	*s = '\0';
}


/*
 * 实现strncmp(s,t,n)
 */
int solution_5_5_3(char *s, char *t, int n)
{
	int i;
	for (i = 0; *s != '\0' && *t != '\0' && i < n; ++i) {
		if (*s < *t) {
			return -1;
		} else if (*s > *t) {
			return 1;
		}
	}

	return 0;
}


/*
 * todo
 */
void solution_5_6(void)
{
}


/*
 * todo
 */
void solution_5_7(void)
{
}


/*
 * todo
 */
void solution_5_8(void)
{
}


/*
 * todo
 */
void solution_5_9(void)
{
}


/*
 * todo
 */
void solution_5_10(void)
{
}



/*
 * todo
 */
void solution_5_11(void)
{
}


/*
 * todo
 */
void solution_5_12(void)
{
}


/*
 * todo
 */
void solution_5_13(void)
{
}


/*
 * todo
 */
void solution_5_14(void)
{
}


/*
 * todo
 */
void solution_5_15(void)
{
}


/*
 * todo
 */
void solution_5_16(void)
{
}


/*
 * todo
 */
void solution_5_17(void)
{
}


/*
 * todo
 */
void solution_5_18(void)
{
}


/*
 * todo
 */
void solution_5_19(void)
{
}


/*
 * todo
 */
void solution_5_20(void)
{
}
