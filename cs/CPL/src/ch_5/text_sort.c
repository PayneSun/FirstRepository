/*
 * src/ch_5/text_sort.c
 *
 * 2019/2/20
 */


#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);


int main()
{
	int nlines;

	if ((nlines == readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
	} else {
		printf("error: input too big to sort!\n");
		return 1;
	}
}


#define MAXLEN 1000
int getline(char *lineptr[], int maxlines);
char *alloc(int n);


int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = alloc(len)) == NULL) {
			return -1;
		} else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}


void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; ++i) {
		printf("%s\n", lineptr[i]);
	}
}


void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}


void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
