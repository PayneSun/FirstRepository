/******************************************
 * /dsaac/src/ch_05_hash/hash_quad.c
 *
 * Open addressing hashing.
 *
 * 2018.08.24
 *****************************************/


#include "hash_quad.h"
#include <stdio.h>

#define MinTableSize 1000

typedef struct HashEntry Cell;


/*
 *
 */
enum KindOfEntry {Legitimate, Empty, Deleted};


/*
 *
 */
struct HashEntry {
	ElementType Element;
	enum KindOfEntry Info;
};


/*
 *
 */
struct HashTbl {
	int TableSize;
	Cell *TheCells;
};


/*
 *
 */
HashTable InitializeTable(int TableSize) {
	HashTable H;
	int i;

	if (TableSize < MinTableSize) {
		Error("Table size too small");
		return NULL;
	}

	H = malloc(sizeof(struct HashTbl));
	if (H == NULL) {
		FatalError("Out of space!!!");
	}

	H->TableSize = NextPrime(TableSize);
	H->TheCells = malloc(sizeof(Cell) * H->TableSize);
	if (H->TheCells == NULL) {
		FatalError("Out of space!!!");
	}
	for (i = 0; i < H->TableSize; i++) {
		H->TheCells[i].Info = Empty;
	}

	return H;
}


/*
 *
 */
Position Find(ElementType Key, HashTable H) {
	Position CurrentPos;
	int CollisionNum;

	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != Empty &&
			H->TheCells[CurrentPos].Element != Key) {
		CurrentPos += 2 * ++CollisionNum - 1;
		if (CurrentPos >= H->TableSize) {
			CurrentPos -= H->TableSize;
		}
	}

	return CurrentPos;
}


/*
 *
 */
void Insert(ElementType Key, HashTable H) {
	Position Pos;

	Pos = Find(Key, H);
	if (H->TheCells[Pos].Info != Legitimate) {
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
	}
}


/*
 *
 */
HashTable Rehash(HashTable H) {
	int i, OldSize;
	Cell *OldCells;

	OldCells = H->TheCells;
	OldSize = H->TableSize;

	H = InitializeTable(2 * OldSize);
	for (i = 0; i < OldSize; i++) {
		if (OldCells[i].Info == Legitimate) {
			Insert(OldCells[i].Element, H);
		}
	}
	free(OldCells);

	return H;
}
