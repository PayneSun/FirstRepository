/*
 * src/ch_5/echo.c
 *
 * 2019/2/21
 */


#include <stdio.h>

int main(int argc, char *argv)
{
	int i;

	for (i = 1; i < argc; i++) {
		printf("%s%s", argv[i], (i < argc-1) ? " " : "");
	}
	printf("\n");

	return 0;
}
