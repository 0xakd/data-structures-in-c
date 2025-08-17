#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "dll.h"
#include "hash_table.h"
#include "hash_table.h"
#include "queue.h"
#include <string.h>



Graph *create_adj_list(Graph *Gtemp, int capacity){
    Gtemp->contents = create_hash_table(capacity);
    Gtemp->number_of_vertices = capacity;
    return Gtemp;
}




Graph *add_edge(Graph *Gtemp, char *st_vertex, char *end_vertex, int weight){
    Gtemp->contents =  insert_list(Gtemp->contents, st_vertex, end_vertex, weight);
    return Gtemp;
}



// Graph *create_adj_matrix(int capacity){
//     if (capacity <= 0) capacity = VERTEX_COUNT;
//     Graph *Gtemp = (Graph *)malloc(sizeof(Graph));
//     // Gtemp->_index = calloc(sizeof(Gtemp->_index), capacity);
//     Gtemp->contents->_index = (int **)calloc(capacity, sizeof(void *));

//     for(int i = 0; i < capacity; i++ ){
//         for (int j = 0; j < capacity; j++){
//             ((int **)Gtemp->contents->_index)[i][j] = 0; 
//         }
//     }
//     return Gtemp;
// }



DList *_vertex_neighbours(Graph *Gtemp, char *vertex_name){
    unsigned int temp_hash = hash(vertex_name);
    return ((DList **)Gtemp->contents->_index)[temp_hash];
}



// // Breadth-First Search (BFS) function
// void breadth_first_search(Graph *Gtemp, char *start_vertex) {
//     if (!Gtemp || !start_vertex) return;
    
//     int vnum = Gtemp->number_of_vertices;
//     bool *is_visited = (bool *)calloc(vnum, sizeof(bool));
//     memset(is_visited, false, sizeof(is_visited));
    
//     Queue *queue = new_queue(vnum);
//     queue_enqueue(queue, start_vertex, 0);
//     is_visited[hash(start_vertex)] = true;
    
//     printf("BFS Traversal: ");
//     while (!is_queue_empty(queue)) {
//         char *current_vertex = queue_dequeue(queue);
//         printf("%s ", current_vertex);
        
//         DList *neighbors = _vertex_neighbours(Gtemp, current_vertex);
//         ListNode *node = neighbors->head;
//         while (node) {
//             if (!is_visited[hash(node->data->vertex)]) {
//                 queue_enqueue(queue, node->data->vertex, 0);
//                 is_visited[hash(node->data->vertex)] = true;
//             }
//             node = node->right;
//         }
//     }
//     printf("\n");
// }



void breadth_first_search(Graph *Gtemp, char *start_vertex) {
    if (!Gtemp || !start_vertex) return;

    int vnum = Gtemp->number_of_vertices;
    bool *is_visited = (bool *)calloc(vnum, sizeof(bool)); // Allocate memory
    if (!is_visited) return;

    Queue *queue = new_queue(vnum);
    int index = hash(start_vertex);
    if (index < 0 || index >= vnum) { free(is_visited); return; } // Validate index

    queue_enqueue(queue, start_vertex, 0);
    is_visited[index] = true;

    printf("BFS Traversal: ");
    while (!is_queue_empty(queue)) {
        char *current_vertex = queue_dequeue(queue);
        if (!current_vertex) continue; // Avoid using NULL

        printf("%s ", current_vertex);
        free(current_vertex); // Free memory after use

        DList *neighbors = _vertex_neighbours(Gtemp, current_vertex);
        if (!neighbors) continue;

        ListNode *node = neighbors->head;
        while (node) {
            int neighbor_index = hash(node->data->vertex);
            if (neighbor_index >= 0 && neighbor_index < vnum && !is_visited[neighbor_index]) {
                queue_enqueue(queue, node->data->vertex, 0);
                is_visited[neighbor_index] = true;
            }
            node = node->right;
        }
    }
    printf("\n");

    free(is_visited); // Free allocated memory
}

