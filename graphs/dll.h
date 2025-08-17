#ifndef _DLL_V2_
#define _DLL_V2_


#include "graph.h"



//structure for storing data of each nodes.
typedef struct DNode {
    char *vertex;
    int weight;
}DNode;


//defining a structure for a doubly list node.
typedef struct list_node {
    struct list_node *left;
    DNode *data;
    struct list_node *right;
} ListNode;


//structure of out doubly linked list.
typedef struct graph_list{
    ListNode *head;
    int len;
    ListNode *tail;
}DList;






//Function declarations
ListNode *dll_new_node(char *vertex_name, int weight);


DList *dll_new_list();


DList *dll_push_(DList *list, char *vertex_name, int weight);



DList *dll_add_(DList *list, char *vertex_name, int weight);


char *dll_remove(DList *list);


#endif
