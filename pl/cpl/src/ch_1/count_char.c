/**
 * count_char.c
 *
 * 2019/1/14
 */

#include <stdio.h>

main() {
	long nc;

	nc = 0;
	while(getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
}
