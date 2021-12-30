#include "graph.h"
#include <math.h>

/**
 * @brief set all nodes distances to 'inf' except the src node which will be 0
 * 
 * @param head 
 * @param src 
 */
void initiate_nodes(pnode head, int src){
    // dist- holds the miniml distance from src, initially -1.
    //state- describes state of node i dijksta process: 0- dist is -1, 1- seen but not visited, 2- visited.

    pnode curr = head;
    while(curr->next){
        curr->dist = -1; 
        curr->state = 0;
        curr = head->next;
    }
    curr = get_node(&head, src);
    curr -> dist = 0;
    curr -> state = 1;
}

int shortest_path(pnode head, int src, int dest){
    //set all distances to -1, state to 0 (unseen).
    //set src dist to 0 and state to 1, update nighbors distance and insert his nighbors to list
    //  {run over list, take minimal distance node as current
    //  update distance to nighbors, add them to list. set current to visited.}
    //repeat until list is empty

    pnode curr_node = head;
    initiate_nodes(head, src);
    int min_node_id = 0;
    while(min_node_id != -1){//stop if no relevant node was found
        min_node_id = -1;
        curr_node = head;
        int min_dist = -1;
        while(curr_node){
            if(curr_node->state == 1){
                if(min_dist == -1 || min_dist > curr_node -> dist){
                    min_node_id = curr_node -> node_id;
                }
            }
        }
        if(min_node_id != -1){
            curr_node = get_node(head, min_node_id);
            pedge e= curr_node -> edges;
            //ease edges
            while(e){
                //condition: the endnode is unseen, or seen (not visited) and has bigger distance than dist+weight
                if(e->endpoint->state==0 || (e->endpoint->state==1 && (curr_node->dist + e->weight) < e->endpoint -> dist)){
                    e->endpoint->state = 1;
                    e->endpoint -> dist = curr_node->dist + e->weight;
                }
            }
            curr_node -> state = 2;
        }
    }
    pnode dest_pnode = get_node(head, dest);
    return dest_pnode -> dist; 
    //how to improve- efficient data structure to keep relevant nodes (state 1)
}


int TSP(pnode head, pnode tspArr){
    return -2;
}