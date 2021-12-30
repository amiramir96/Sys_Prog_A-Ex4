#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "graphAlgo.h"

int main(){
    pnode head = NULL;
    // just notes for tests:
    pnode n0 = (node*)calloc(1,sizeof(node)); 
    pnode n1 = (node*)calloc(1,sizeof(node)); 
    pnode n2 = (node*)calloc(1,sizeof(node)); 
    
    n0-> node_id = 0;
    n1->node_id = 1;
    n2->node_id = 2;
    insert_node_cmd(&head, n0);
    insert_node_cmd(&head, n1);
    insert_node_cmd(&head, n2);
    printf("print graph (nodes only):\n");
    printGraph_cmd(head);
    //n0->next = n1;
    //n1->next = n2;
    // n2->next = n3;
    insert_edge(head, 0, 3, 1);
    insert_edge(head, 1, 2, 2);
    insert_edge(head, 2, 5, 1);
    insert_edge(head, 0, 6, 2);
    // pedge e1, e2, e3;
    // n1->edges = (edge*)calloc(1,sizeof(edge));
    // e1 = n1->edges;
    // e1->endpoint = n2;
    // e1->weight=1;

    // e1->next = (edge*)calloc(1,sizeof(edge));
    // e1 = e1->next;
    // e1->endpoint = n0;
    // e1->weight = 7;
    // if (e1->next == NULL){
    //     printf("true\n");
    // }
    // else{
    //     printf("false\n");
    // }
    // pnode * head;
    // head = &n1;
        printf("print graph with edges:\n");
    printGraph_cmd(head);
    int dist1 = shortest_path(head, 1,0);
    int dist2 = shortest_path(head, 1,2);
    int dist3 = shortest_path(head, 0,2);
    int dist4 = shortest_path(head, 2,0);
    printf("distance from 1 to 0: %d\n", dist1);
    printf("distance from 1 to 2: %d\n", dist2);
    printf("distance from 0 to 2: %d\n", dist3);
    printf("distance from 2 to 0: %d\n", dist4);
    deleteGraph_cmd(&head);
}