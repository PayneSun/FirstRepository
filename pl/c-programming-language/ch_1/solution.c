/**
 * ch_1/solution.c
 *
 * 2019/1/15
 */

#include <stdio.h>
#include <string.h>

void solution_1_1();
void solution_1_2();
void solution_1_3();
void solution_1_4();
void solution_1_5();
void solution_1_6();
void solution_1_7();
void solution_1_8();
void solution_1_9();
void solution_1_10();
void solution_1_11();
void solution_1_12();
void solution_1_13();
void solution_1_14();
void solution_1_15();
void solution_1_16();
void solution_1_17();
void solution_1_18();
void solution_1_19(char in[]);
void solution_1_20(int n);
void solution_1_21();
void solution_1_22();
void solution_1_23();
void solution_1_24();

int main()
{
//	solution_1_1();
//	solution_1_2();
//	solution_1_3();
//	solution_1_4();
//	solution_1_5();
//	solution_1_6();
//	solution_1_7();
//	solution_1_8();
//	solution_1_9();
//	solution_1_10();
//	solution_1_11();
//	solution_1_12();
//	solution_1_13();
//	solution_1_14();
//	solution_1_15();
//	solution_1_16();
//	solution_1_17();
//	solution_1_18();
//	char instr[] = "123456789";
//	solution_1_19(instr);
	int n = 1;
	solution_1_20(n);
//	solution_1_21();
//	solution_1_22();
//	solution_1_23();
//	solution_1_24();

	return 0;
}


void solution_1_1()
{
	printf("hello, world\n");
}


void solution_1_2()
{
//	printf("hello, world\c");
	printf("hello, world\n");
}


void solution_1_3()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Fahr  Celsius\n");
	printf("=============\n");
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}


void solution_1_4()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Celsius  Fahr\n");
	printf("=============\n");
	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0 / 5.0) * celsius + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}


void solution_1_5()
{
	float fahr;

	printf("Fahr  Celsius\n");
	printf("=============\n");

	for (fahr = 300; fahr >= 0; fahr -= 20) {
		printf("%3.0f %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
	}
}


void solution_1_6()
{
	printf("%d\n", getchar() != EOF);
}


void solution_1_7()
{
	printf("%d\n", EOF);
}


void solution_1_8()
{
	int c,    /* input */
		ec,   /* empty space count */
		tc,   /* tab count */
		nc;   /* next line count */

	ec = tc = nc = 0;
	while ((c = getchar()) != EOF){
		if (c == ' ') { ec++; }
		if (c == '\t') { tc++; }
		if (c == '\n') { nc++; }
	}
	printf("\nec = %d, tc = %d, nc = %d\n", ec, tc, nc);
}


void solution_1_9()
{
	int c, ec = 0;
	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			putchar(c);
			ec = 0;
		} else {
			ec++;
			if (ec <= 1) {
				putchar(c);
			}
		}
	}
}


void solution_1_10()
{
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		}
		else if (c == '\b') {
			putchar('\\');
			putchar('b');
		}
		else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		}
		else {
			putchar(c);
		}
	}
}


void solution_1_11()
{
	int c,       /* input char */
		nl,      /* line count */
		nw,      /* word count */
		nc,      /* char count */
		state;   /* word state */

	state = 0;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n') {
			++nl;
		}
		if (c == ' ' || c == '\n' || c == '\t') {
			state = 0;
		}
		else if (state == 0) {
			state = 1;
			++nw;
		}
	}
	printf("\nnl = %d, nw = %d, nc = %d", nl, nw, nc);
}


void solution_1_12() {
	int c,       /* input char */
		state;   /* word state */

	state = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == 1) {
				putchar('\n');
			}
			state = 0;
		}
		else {
			state = 1;
			putchar(c);
		}
	}
}


void solution_1_13()
{
	int c,             /* input char */
		length,        /* word length count */
	    wordLen[10];   /* word length array */

	for (int i = 0; i < 10; ++i) {
		wordLen[i] = 0;
	}

	/* count word length */
	length = 0;
	char testArray[] = "x  g t o a b c d ee ff ggg hhh tyrtyrtyr iii";
	int m = 0;
	do {
		c = testArray[m];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			length++;
		}
		else {
			if (length > 0) {
				++wordLen[length];
				length = 0;
			}
		}
		++m;
	} while (c != EOF);

	/* print result */
	printf("\nLen Sum\n");
	for (int i = 0; i < 10; ++i) {
		if (wordLen[i] > 0) {
			printf("%d   ", i);
			for (int j = 0; j < wordLen[i]; ++j) {
				printf("*");
			}
			printf("\n");
		}
	}
}


void solution_1_14()
{
	int c, alphabet[26];

	for (int i = 0; i < 26; ++i) {
		alphabet[i] = 0;
	}

	//while ((c = getchar()) != EOF) {
	int i = 0;
	char testArray[] = "qwertyuiopasdfghjlmnbvcxzasfhjrxncjddnc";
	while (c = testArray[i]) {
		++i;
		if (c >= 'a' && c <= 'z') {
			++alphabet[c - 'a'];
		}
		else if (c >= 'A' && c <= 'Z') {
			++alphabet[c - 'A'];
		}
	}

	for (int i = 0; i < 26; ++i) {
		printf("%c  ", 'a' + i);
	}
	printf("\n");
	for (int i = 0; i < 26; ++i) {
		printf("%d  ", alphabet[i]);
	}
}


void solution_1_15()
{
	float fahr;

	printf("Fahr  Celsius\n");
	printf("=============\n");
	for (fahr = 300; fahr >= 0; fahr -= 20) {
		printf("%3.0f %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
	}
}


void solution_1_16()
{
	int c, i;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		putchar(c);
	}
	printf("\nLength = %d\n", i);
}


void solution_1_17()
{
	int c, index = 0;
	char instr[1000];

	while ((c = getchar()) != EOF) {
		instr[index++] = c;

		if (c == '\n') {
			if (index >= 80) {
				instr[index] = '\0';
				printf("Length=\%d: %s\n", index, instr);
			}
			index = 0;
		}
	}
}


void solution_1_18()
{
	int c, index = 0;
	char instr[1000];

	while ((c = getchar()) != EOF) {
		instr[index++] = c;
		if (c == '\n') {
			for (--index; index >= 0; --index) {
				if (instr[index] == '\n') {
					continue;
				}
				if ((instr[index] != ' ') && (instr[index] != '\t')) {
					instr[++index] = '\0';
					printf("%s\n", instr);
					index = 0;
					break;
				}
			}
		}
	}
}


void solution_1_19(char instr[])
{
	printf("Before\t%s\n", instr);

	int c, idx, len;
	len = strlen(instr);
	for (idx = 0; idx < len / 2; ++idx) {
		c = instr[idx];
		instr[idx] = instr[len-1-idx];
		instr[len-1-idx] = c;
	}

	printf("After\t%s\n", instr);
}


void solution_1_20(int n)
{
	int c, i;

	while((c = getchar()) != EOF) {
		if (c == '\t') {
			for (i = 0; i < n; ++i) {
				printf(" ");
			}
		} else {
			putchar(c);
		}
	}
}


void solution_1_21()
{

}


void solution_1_22()
{

}


void solution_1_23()
{

}


void solution_1_24()
{

}
