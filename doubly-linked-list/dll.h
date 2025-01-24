#ifndef _dll_
#define _dll_

typedef struct dll_node
{
    struct dll_node *prev;
    int data;
    struct dll_node *next;

} DNode;

typedef struct dll
{   
    // pointer to the last node of the list
    // default value is NULL
    DNode *head;
    // pointer to the last node of the list 
    // default value is NULL
    DNode *tail;
    // store the length of the list 
    // on add +1; on removal -1
    // default value is 0
    int len;
} Dlist;

/**
 * function to create a new node 
 * and return the pointer of the newly
 * created node to the caller 
 */
DNode *dll_new_node(int data);
/**
 * function to create a new DLL list 
 * and return the pointer of the newly 
 * created list to the caller
 */
Dlist *dll_new_list();


/**
 * add new data node to the list 
 * at the beginning 
 */
Dlist *dll_add(Dlist *list,  int data);

/**
 * add new node to the end of the list
 */
Dlist *dll_push(Dlist *list, int data);

/**
 * pop function will remove the node
 * at the begging and will return the 
 * data that was stored in the node 
 */
int dll_pop(Dlist *list);

/**
 * remove will remove the node at the end
 * and return the data that was stored in
 * the node
 */
int dll_remove(Dlist *list);

/**
 * find - will return the node position 
 * if the data is found in the list 
 * or it will return -1 if the data 
 * does not exists in the node 
 */
int dll_find(Dlist *list, int data);

/**
 * display - will print all the node values with their positions
 */
void dll_display(Dlist *list);

/**
 * size - will return the length of the list
 */
int dll_size(Dlist *list);

#endif