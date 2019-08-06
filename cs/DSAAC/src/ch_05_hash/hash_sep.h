/******************************************
 * ch_05_hash/hash_sep.h
 *
 * 2018.08.24
 *****************************************/


#ifndef CH_05_HASH_HASH_SEP_H_
#define CH_05_HASH_HASH_SEP_H_


struct ListNode;
struct HashTbl;
typedef struct ListNode *Position;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);


#endif /* CH_05_HASH_HASH_SEP_H_ */
