#ifndef _HASH_TABLE_
#define _HASH_TABLE_

#include "dll.h" 
#include <stdbool.h>


//definining the size of our hash table.
#define TABLE_SIZE 1000


//structure of my table
typedef struct htable{
    //creating indexing for our hash table.
    Dlist *_index;
} HTable;


/**
 * the create htable function
 * creates a new hash table of 
 * the size passed through the 
 * argument
 */
HTable *create_htable(int capacity);


/**
 * the hash function converts the key 
 * to a unsigned integer value and
 * returns the converted value 
 */
unsigned int hash(char *key);


/**
 * this function will insert new 
 * to our hash table at an index
 * returned by the hash function
 */
HTable *htable_insert(HTable *htbl, char *key);


/**
 * this function will check whether
 * a given value is present in 
 * the table or not.
 */
void htable_lookup(HTable *htbl, char *key);




#endif