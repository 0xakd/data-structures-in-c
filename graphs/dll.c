#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"



//Function to create a new node
ListNode *dll_new_node(char *vertex, int weight){
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = (DNode *)malloc(sizeof(DNode));
    temp->data->vertex = (char *)malloc(strlen(vertex) + 1); 
    temp->data->weight = weight;
    temp->left = NULL;
    strcpy(temp->data->vertex, vertex);
    temp->right= NULL;
    return temp;
}





//Function for initialising a new list
DList *dll_new_list(){
    DList *n_list = (DList *)malloc(sizeof(DList));
    if (!n_list) return NULL;

    n_list->len=0;
    n_list->head = NULL;
    n_list->tail = NULL;
    
    if(!n_list) return NULL;
    else return n_list;
}





//Function to push new node at the end of the list.
DList *dll_push_(DList *list, char *vertex_name, int weight){
    if(!list) return NULL;
    ListNode *n_node = dll_new_node(vertex_name, weight);

    if (!n_node) return NULL;


    if(list->head==NULL){
        list->head = n_node;
        list->tail = n_node;
    }else{
        list->tail->right = n_node;
        n_node->left = list->tail;
        list->tail = n_node;
    }
    list->len++;
    return list;
}






//Function to push new data at the beginning of the list
DList *dll_add_(DList *list, char *vertex_name, int weight){
    DList *dll_add(DList *list, int data);
    if(!list) return NULL;
    ListNode *n_node = dll_new_node(vertex_name, weight);
    
    if (!list->head){
        list->head = n_node;
        list->tail=n_node;
    }else{
        list->head->left = n_node;
        n_node->right = list->head;
        list->head = n_node;
    }
    list->len++;
    return list;
}




//Function to remove the last node from the list.
char *dll_remove(DList *list){
    if(!list) return NULL;
    if(!list->head) return NULL;
    
    ListNode *current = list->head, *temp;

    while (current->right!=NULL) current = current->right;
    current->left->right = NULL;
    list->tail = current->left;
    char *pop_data = malloc(strlen(current->data->vertex) + 1);
    strcpy(pop_data, current->data->vertex);
    free(current);
    list->len--;
    return pop_data;
}