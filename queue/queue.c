#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "../doubly-linked-list/dll.h"


//Function for initialising a new queue.
Queue *new_queue(int size){
    // allocate memory for Queue object.
   Queue *que = (Queue *)malloc(sizeof(Queue));

   // set the size of queue equal to 
   // the size of given by the user
   que->size = size;

    // we will use a DLL as the interal data structure
    // for the queue so queue contents will be a DLL 
    que->contents = dll_new_list();

    //return the newly created queue
    return que;
}


// function to add new element/member
// at the beginning of the queue.
Queue *queue_enqueue(Queue *que, int data){
    que = dll_add(que->contents, data);
    return que;
}


// function to remove the last element
// from the queue and return the removed element
int queue_dequeue(Queue *que){
    return dll_remove(que->contents);
}


// function to return the top-most element of the stack
int queue_peek(Queue *que){
    return dll_peek(que->contents);
}

// function to check weather the queue is empty or not.
bool queue_is_empty (Queue *que){
    return dll_size(que->contents) == 0;
}

//isFull - Function to check weather the stack is FULL or not.
bool queue_is_full(Queue *que){
    return dll_size(que->contents) == que->size;
}