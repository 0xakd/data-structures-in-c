#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../doubly-linked-list/dll.h"
#include "hash_table.h"


//this function creates a new hash table and initialise each index of the table with a dll. 
HTable *create_htable(int capacity){
    if (capacity <= 0) capacity = TABLE_SIZE;
    HTable *htbl = (HTable *)malloc(sizeof(HTable));
    htbl->_index = calloc(sizeof(void *), capacity);

    for(int i = 0; i < capacity; i++ ){
        for (int i = 0; i < capacity; i++) {
            htbl->_index[i] = *dll_new_list(); 
        }
    }
    return htbl;
}


//this function takes a string and returns non-negative integers
unsigned int hash(char *key){
        int len = strlen(key);
        unsigned int hash_value = 0;
        for (int i = 0; i < len; i++){
            hash_value += key[i];
            hash_value = (hash_value * key[i]) % TABLE_SIZE ;
        }
        return hash_value;
}



//this function will insert new values into the hash table
HTable *htable_insert(HTable *htbl, char *key){
    unsigned int temp = hash(key);
    htbl->_index[temp] = *dll_push(&htbl->_index[temp], key);
    return htbl;
}


//this function will check for a given value in the table 
void htable_lookup(HTable *htbl, char *key){
    unsigned int temp_index = hash(key);
    if (!htbl) return;
    int temp_return = dll_find(&htbl->_index[temp_index], key);
    if (temp_return != -1 ) printf("value not found\n");
    else printf("value found\n");
}