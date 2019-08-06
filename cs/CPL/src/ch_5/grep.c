/*
 * src/ch_5/grep.c
 *
 * 2019/2/21
 */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max);

int main(int argc, int *argv[])
{
	char line[MAXLINE];
	int found = 0;

	if (argc != 2) {
		printf("Usage: find pattern\n");
	} else {
		while (getline(line, MAXLINE) > 0) {
			if (strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				found++;
			}
		}
	}

	return found;
}
