#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"

//Function to create a new node
DNode *dll_new_node(char *data){
    DNode *temp = (DNode *)malloc(sizeof(DNode));
    temp->data = malloc(strlen(data) + 1); 
    temp->prev = NULL;
    strcpy(temp->data, data);
    temp->next= NULL;
    return temp;
}


//Function for initialising a new list
Dlist *dll_new_list(){
    Dlist *n_list = (Dlist *)malloc(sizeof(Dlist));
    n_list->len=0;
    n_list->head = NULL;
    n_list->tail = NULL;
    if(!n_list) return NULL;
    else return n_list;
}



//Function to push new node at the end of the list.
Dlist *dll_push(Dlist *list, char *data){
    if(!list) return NULL;
    DNode *n_node = dll_new_node(data);
    if(list->head==NULL){
        list->head = n_node;
        list->tail = n_node;
    }else{
        DNode *current = list->head;
        while(current->next!=NULL) current = current->next;
        current->next = n_node;
        n_node->prev = current;
        list->tail = n_node;
    }
    list->len++;
    return list;
}




//Function to find weather a given data is present in the list or not.
int dll_find(Dlist *list, char *data){
    if(!list) return 0;
    if(!list->head) return 0;

    DNode *current = list->head;

    int index = 0, count = 0;
    
    while(!current){
        if (strcmp(current->data,data)==0) count++; 
        current = current->next;
        index++;
    }
    if (count>0) return index;
    else return -1;
}

