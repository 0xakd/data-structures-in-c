#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"
#include "dll.h"


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
Queue *queue_enqueue(Queue *que, char *vertex_name, int weight){
    if (is_queue_full(que)!=true){
        que->contents = dll_add_(que->contents, vertex_name, weight);
    }else{
        printf("Queue is already full.\n");
    }
    return que;
}


// function to remove the last element
// from the queue and return the removed element
char *queue_dequeue(Queue *que){
    if (!is_queue_empty(que)){
        return dll_remove(que->contents);
    }else{
        printf("Nothing to remove.\n");
        return NULL;
    }
}


// // function to return the top-most element of the stack
// int queue_peek(Queue *que){
//     if (is_queue_empty(que)!=true){
//         return dll_peek(que->contents);
//     }else{
//         printf("Queue is empty.\n");
//         return 0;
//     }
// }

// function to check weather the queue is empty or not.
bool is_queue_empty (Queue *que){
    return (que->contents->len == 0);
}

//isFull - Function to check weather the stack is FULL or not.
bool is_queue_full(Queue *que){
    return (que->contents->len == que->size);
}