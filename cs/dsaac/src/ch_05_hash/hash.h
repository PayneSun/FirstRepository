/******************************************
 * ch_05_hash/hash.h
 *
 * 2018.08.24
 *****************************************/


#ifndef CH_05_HASH_HASH_H_
#define CH_05_HASH_HASH_H_

typedef unsigned int Index;


/*
 *
 */
Index Hash1(const char* key, int TableSize) {
	unsigned int hash_val = 0;

	while (*key != '\0') {
		hash_val += *key++;
	}

	return hash_val % TableSize;
}


/*
 *
 */
Index Hash2(const char* key, int TableSize) {
	return (key[0] + 27 * key[1] * 729 * key[2]) % TableSize;
}


/*
 *
 */
Index Hash3(const char* key, int TableSize) {
	unsigned int hash_val = 0;

	while (*key != '\0') {
		hash_val = (hash_val << 5) + *key++;
	}

	return hash_val % TableSize;
}

#endif /* CH_05_HASH_HASH_H_ */
