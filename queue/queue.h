#ifndef _QUEUE_
#define _QUEUE_

#include "../doubly-linked-list/dll.h"



typedef struct que
{   
    // the queue will use the doubly list under the hood
    Dlist *contents;
    //defines the size the the queue
    int size;
} Queue;


/**
 * function to create a new Stack 
 * and return the pointer of the newly 
 * created stack to the caller
 */
Queue *new_queue(int size);


/**
 * function to add new element 
 * to the front of the queue
 */
Queue *queue_enqueue(Queue *que, int data);


/**
 * function to remove an element 
 * from the back of the queue
 */
Queue *queue_dequeue(Queue *que);


/**
 * this function returns the 
 * front element of the queue
 */
int queue_peek(Queue *que);


/**
 * this function checks weather
 * the queue is empty or not
 * [returns boolean value]
 */
bool queue_is_empty(Queue *que);


/**
 * this function checks weather 
 * the queue is full or not.    
 * [returns boolean value]
 */
bool queue_is_full(Queue *que);


#endif