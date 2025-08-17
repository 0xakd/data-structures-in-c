#ifndef _HASH_TABLE_V2_
#define _HASH_TABLE_V2_


#include <stdio.h>
#include <stdlib.h>
#include "graph.h"




//defining the indexing of our Hash Table index.
typedef struct HashIndex {
    //creating index
    void *_index;
}HashIndex;


unsigned int hash(char *vertex);
HashIndex *create_hash_table(int capacity);
HashIndex *insert_list(HashIndex *Htemp, char *st_vertex, char *end_vertex, int weight);


#endif