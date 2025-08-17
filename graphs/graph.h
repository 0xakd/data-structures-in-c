#ifndef _GRAPH_
#define _GRAPH_

#include "hash_table.h"
#include "dll.h"


//definining the size of our hash table.
#define VERTEX_COUNT 1000





//defining the indexing of our Adjacency list.
typedef struct graph {
    //creating index
    HashIndex *contents;
    int number_of_vertices;
}Graph;






//Function declarations
unsigned int hash(char *vertex);


Graph *create_adj_list(Graph *Gtemp,int capacity);


Graph *add_edge(Graph *Gtemp, char *st_vertex, char *end_vertex, int weight);


// Graph *create_adj_matrix(int capacity);


void breadth_first_search(Graph *Gtemp, char *start_vertex) ;


// void breadth_first_search(Graph *Gtemp);

#endif