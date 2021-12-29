#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int main(){

    char chr;
    int num_of_nodes, idx, node_id;
    int weight, dest_node;
    int num;
    pnode * head;
    pnode n;
    pedge e, tempE;

    scanf("%c",&chr);
    for(;chr != '\n' && chr != '\0';){
        scanf("%c",&chr);
        
        if (chr == 'A'){ // case A create whole graph (linked list of nodes and ea node hold list of edges)
            deleteGraph_cmd(head);
            scanf("%d",&num_of_nodes);
            scanf("%c",&chr);
            if (num_of_nodes <= 0){
                continue;
            }

            idx = 0;
            while(idx < num_of_nodes){
                scanf("%c",&chr); // start of new node
                scanf("%d",&node_id);
                n = (pnode)malloc(sizeof(node));
                n->node_id = node_id;
                insert_node_cmd(head, n); // add node to the linked list of nodes 

                e = n->edges; // add the edges now.
                while (scanf("%d",&dest_node)){
                    scanf("%d",&weight);
                    if (e == NULL){ // first edge to add
                        e = (edge*)malloc(sizeof(edge));
                        if (e == NULL){
                            deleteGraph_cmd(head);
                            return -1;
                        }
                        n->edges = e;
                    }
                    else { // there is already existing list of edges
                        tempE = e;
                        e = (edge*)malloc(sizeof(edge));
                        if (e == NULL){
                            deleteGraph_cmd(head);
                            return -1;
                        }
                        e->next = tempE; // add in the start of the list
                        n->edges = e;
                    }
                    e->weight = weight;
                    e->endpoint = get_node(head, dest_node); // ATTENTION!!! - if the dest_node number is not exists in the graph, get_node will create and insert orderly a node with dest_node id
                }
            }
        }
        else if (chr == 'B'){ // B case - add specific one node
            if (scanf("%d",&node_id)){ // else, skip.
                n = (pnode)malloc(sizeof(node));
                n->node_id = node_id;

                while (scanf("%d",&dest_node)){
                    scanf("%d",&weight);
                    if (e == NULL){ // first edge to add
                        e = (edge*)malloc(sizeof(edge));
                        if (e == NULL){
                            deleteGraph_cmd(head);
                            return -1;
                        }
                        n->edges = e;
                    }
                    else { // there is already existing list of edges
                        tempE = e;
                        e = (edge*)malloc(sizeof(edge));
                        if (e == NULL){
                            deleteGraph_cmd(head);
                            return -1;
                        }
                        e->next = tempE; // add in the start of the list
                        n->edges = e;
                    }
                    e->weight = weight;
                    e->endpoint = get_node(head, dest_node); // ATTENTION!!! - if the dest_node number is not exists in the graph, get_node will create and insert orderly a node with dest_node id
                }

            }


        }
        else if (chr == 'D'){ // delete node
            scanf("%d",node_id);
            delete_node_cmd(head, node_id);
        }
        else if (chr == 'S'){ // shortest path
            int src, dest;
            scanf("%d",src);
            scanf("%d",dest);
            printf("Dijsktra shortest path: %d\n",shortesPath_cmd(*head, src, dest));
        }
        else if (chr == 'T'){ // TSP - idont know when we ended to get inputs for TSP...
            int size = get_size(*head);
            int * arr = (int*)malloc(size*sizeof(int));
            if (arr == NULL){
                deleteGraph_cmd(head);
                return -1;
            }
            int i = 0;
            while (scanf("%d",&num)){
                arr[i] = num;
                i++;
            }
            realloc(&arr[0], sizeof(i));
            printf("TSP shortest path: %d\n",TSP_cmd(*head, &arr[0]));

            free(arr);
        }
    }
    deleteGraph_cmd(head);
    return 0;
}

    // just notes for tests:
    // pnode n1 = (node*)calloc(1,sizeof(node)); 
    // pnode n2 = (node*)calloc(1,sizeof(node)); 
    // pnode n0 = (node*)calloc(1,sizeof(node)); 
    
    // n1->node_id = 1;
    // n2->node_id = 2;
    // n0-> node_id = 0;
    // n1->next = n2;
    // // n2->next = n3;
        
    // printGraph_cmd(n1);
    // printf("hello! we printed graph!\n\n");

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
    
    // insert_node_cmd(head, n0);
    // printf("hi we added item to the graph!\n\n");
    // printGraph_cmd(*head);
    // printf("printed again^^\n\n");
    // get_node(head, 18);
