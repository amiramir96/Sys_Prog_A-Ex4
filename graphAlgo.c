#include "graph.h"
#include <math.h>

/**
 * @brief set all nodes distances to 'inf' except the src node which will be 0
 * 
 * @param head 
 * @param src 
 */
void initiate_nodes(pnode head, int src){
    pnode curr = head;
    while(curr->next){
        curr->dist = INFINITY; // dist is double
        curr = head->next;
    }
    curr = get_node(&head, src);
    curr -> dist = 0;
}

int shortest_path(pnode head, int src, int dest){
    //create list for distances, fathers
    //initiate distance to infinity for all edges, fathers to null
    //src dist to 0, update nighbors distance and insert his nighbors to list
    //  {run over list, take minimal distance node as current
    //  update distance to nighbors, add them to list. set current to visited.}
    //repeat until list is empty

    pnode curr_node = head;
    initiate_nodes(head, src);
    
}