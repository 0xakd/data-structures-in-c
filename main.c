#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphs/dll.h"
#include "graphs/graph.h"


void main(){
    Graph *my_graph = create_adj_list(my_graph, z);

    my_graph = add_edge(my_graph, "A", "B", 20);
    my_graph = add_edge(my_graph, "B", "D", 30);
    my_graph = add_edge(my_graph, "D", "C", 54);



    // Graph *my_matrix = create_adj_matrix(5);


    breadth_first_search(my_graph, "A");
}
