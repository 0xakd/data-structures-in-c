#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "dll.h"
#include "hash_table.h"




unsigned int hash(char *vertex) {
    unsigned int hash_value = 5381; // Initial prime value
    int c;

    while (c = *vertex++){ 
        hash_value = ((hash_value << 5) + hash_value) + c; // hash_value * 33 + c
    }
    printf("hash_value = %d\n", hash_value);
    return hash_value % VERTEX_COUNT; // Ensure it stays within bounds
}








HashIndex *create_hash_table(int capacity){
    if (capacity <= 0) capacity = VERTEX_COUNT;
    HashIndex *Htemp = (HashIndex *)malloc(sizeof(HashIndex));
    // Gtemp->_index = calloc(sizeof(Gtemp->_index), capacity);
    Htemp->_index = (DList *)calloc(capacity, sizeof(void *));

    for(int i = 0; i < capacity; i++ ){
        ((DList **)Htemp->_index)[i] = dll_new_list(); 
        
    }
    return Htemp;
}








HashIndex *insert_list(HashIndex *Htemp, char *st_vertex, char *end_vertex, int weight){
    unsigned int temp = hash(st_vertex);
    ((DList *)Htemp->_index)[temp] = *dll_push_(&((DList *)Htemp->_index)[temp], end_vertex, weight);
    return Htemp;
}





