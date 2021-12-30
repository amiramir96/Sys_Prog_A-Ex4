#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "graphAlgo.h"

int main(){
    // just notes for tests:
    pnode n1 = (node*)calloc(1,sizeof(node)); 
    pnode n2 = (node*)calloc(1,sizeof(node)); 
    pnode n0 = (node*)calloc(1,sizeof(node)); 
    
    n1->node_id = 1;
    n2->node_id = 2;
    n0-> node_id = 0;
    n1->next = n2;
    // n2->next = n3;
        
    printGraph_cmd(n1);
    printf("hello! we printed graph!\n\n");

    pedge e1, e2, e3;
    n1->edges = (edge*)calloc(1,sizeof(edge));
    e1 = n1->edges;
    e1->endpoint = n2;
    e1->weight=1;

    e1->next = (edge*)calloc(1,sizeof(edge));
    e1 = e1->next;
    e1->endpoint = n0;
    e1->weight = 7;
    if (e1->next == NULL){
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    pnode * head;
    head = &n1;
    
    insert_node_cmd(head, n0);
    printf("hi we added item to the graph!\n\n");
    printGraph_cmd(*head);
    printf("printed again^^\n");
    int dist1 = shortest_path(*head, 1,0);
    int dist2 = shortest_path(*head, 1,2);
    printf("distance from 1 to 0: %d\n", dist1);
    printf("distance from 1 to 2: %d\n", dist2);
    deleteGraph_cmd(head);
}