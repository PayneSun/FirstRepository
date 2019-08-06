/*
 * src/ch_6/table_search.c
 *
 * 2019/2/26
 */


#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define HASHSIZE 101

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

static struct nlist *hashtab[HASHSIZE];


/*
 * 为字符串s生成散列值
 */
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++) {
		hashval = *s + 31 * hashval;
	}
	return hashval % HASHSIZE;
}


/*
 * 在hashtable中查找s
 */
struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0) {
			return np;
		}
	}
	return NULL;
}


/*
 * 将（name, defn)加入到hashtable中
 */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *)malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL) {
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else {
		free((void *)np->defn);
	}
	if ((np->defn = strdup(defn)) == NULL) {
		return NULL;
	}

	return np;
}

