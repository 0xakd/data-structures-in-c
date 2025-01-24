#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

//Function to create a new node
DNode *new_node(int data){
    DNode *temp = (DNode *)malloc(sizeof(DNode));
    temp->prev = NULL;
    temp->data=data;
    temp->next= NULL;
    return temp;
}



//Function for initialising a new list
Dlist *new_list(){
    Dlist *n_list = (Dlist *)malloc(sizeof(Dlist));
    n_list->len=0;
    if(!n_list) return n_list;
}



//Function to add new node at the beginning.
Dlist *add(Dlist *list, int data){
    if(!list) return NULL;
    DNode *n_node = new_node(data);
    
    if (!list->head){
        list->head = n_node;
        list->tail=n_node;
    }else{
        list->head->prev = n_node;
        n_node->next = list->head;
        list->head = n_node;
    }
    list->len++;
    return list;
}



//Function to push new node at the end of the list.
Dlist *push(Dlist *list, int data){
    if(!list) return NULL;
    DNode *n_node = new_node(data);
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



//Function for removing the node at the beginning of the list.
int pop(Dlist *list){
    if(!list) return 0;
    if(!list->head) return 0;
    DNode *current = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    int pop_data = current->data;
    free(current);
    list->len--;
    return pop_data;
}



//Function to remove the last node from the list.
int remove_node(Dlist *list){
    if(!list) return 0;
    if(!list->head) return 0;
    
    DNode *current = list->head, *temp;

    while (current->next!=NULL) current = current->next;
    current->prev->next = NULL;
    list->tail = current->prev;
    int pop_data = current->data;
    free(current);
    list->len--;
    return pop_data;
}



//Function to find weather a given data is present in the list or not.
int find(Dlist *list, int data){
    if(!list) return 0;
    if(!list->head) return 0;

    DNode *current = list->head;

    int index = 0, count = 0;
    
    while(!current){
        if (current->data == data) count++; 
        current = current->next;
        index++;
    }
    if (count>0) return index;
    else return -1;
}



//Function to print all the nodes 
void display(Dlist *list){
    if(!list) return;
    if(!list->head) return;

    DNode *current = list->head;

    int count = 1;
    
    while(current!=NULL){
        printf("Node %d = %d\n", count, current->data );
        count++; 
        current = current->next;
    }
}



//Function for returning the size of the ll.
int size(Dlist *list){
    if(!list) return 0;
    if(!list) return 0;
    return list->len;
}
