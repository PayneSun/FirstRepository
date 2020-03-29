/******************************************
 * /dsaac/src/ch_05_hash/hash_quad.h
 *
 * 2018.08.24
 *****************************************/

#ifndef CH_05_HASH_HASH_QUAD_H_
#define CH_05_HASH_HASH_QUAD_H_


typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);


#endif /* CH_05_HASH_HASH_QUAD_H_ */
