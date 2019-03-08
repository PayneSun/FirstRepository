/*
 * src/ch_7/cat.c
 *
 * 2019/2/27
 */

#include <stdio.h>

void filecopy(FILE *ifp, FILE *ofp);

int main(int argc, char *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);

	if (argc == 1) {
		filecopy(stdin, stdout);
	} else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "r")) == NULL) {
				printf("cat: can't open %s\n", *argv);
				return 1;
			} else {
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}

	return 0;
}


/*
 * 将文件ifp复制到文件ofp
 */
void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF) {
		putc(c, ofp);
	}
}
