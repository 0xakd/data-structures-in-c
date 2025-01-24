#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "../doubly-linked-list/dll.h"


//Function for initialising a new stack
Stack *new_stack(int size){
    // allocate memory ffor stack object 
    Stack* stk = (Stack *)malloc(sizeof(Stack));

    // set the size of the stack equal to 
    // the size given by the user 
    stk->size = size;

    // we will use a DLL as the interal data structure
    // for the stack so stacck contents will be a DLL 
    stk->contents = dll_new_list();

    // return the newly created stack
    return stk;   
}

//push - Function to add new node from the top of the stack.
Stack *stack_push(Stack *stk, int data){
    stk = dll_push(stk->contents, data);
    return stk;
}

//pop - Function to remove the top-most element from the stk.
int stack_pop(Stack *stk){
    return dll_pop(stk->contents);
}

//peek - Function to returns the top-most element of the stack
int stack_peek(Stack *stk){
    return dll_peek(stk->contents);
}

//isEmpty - Function to check weather the stack is empty or not.
bool stack_is_empty (Stack *stk){
    return dll_size(stk->contents) == 0;
}

//isFull - Function to check weather the stack is FULL or not.
bool stack_is_full(Stack *stk){
    return dll_size(stk->contents) == stk->size;
}
