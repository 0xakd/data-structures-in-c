#ifndef _STACK_
#define _STACK_

#include "../doubly-linked-list/dll.h"
#include <stdbool.h>


typedef struct stk
{   
    // the stack will use the doubly list under the hood
    Dlist *contents;
    //defines the size the the stack
    int size;
} Stack;


Stack *create_new_hlist(){
    return dll_new_list();
}





/**
 * function to create a new Stack 
 * and return the pointer of the newly 
 * created stack to the caller
 */
Stack *new_stack(int size);


/**
 * push - Function to add 
 * new node from the top of the stack.
 */
Stack *stack_push(Stack *stk, int data);


/**
 * pop - Function to remove the 
 * top-most element from the stk.
 */
int stack_pop(Stack *stk);


/**
 * peek - Function to returns the
 * top-most element of the stack.
 */
int stack_peek(Stack *stk);

/**
* isEmpty - Function to check weather 
* the stack is empty or not.
*/
bool is_stack_empty (Stack *stk);


/**
 * isFull - Function to check weather 
 * the stack is FULL or not.
 */
bool is_stack_full (Stack *stk);



#endif