#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int main(){

    char chr, in;
    int num_of_nodes, idx, node_id;
    int weight, dest_node;
    int num;
    int flag;
    pnode * head;
    pnode n;
    pedge e;

    scanf("%c",&chr);
    for(;chr != '\n' && chr != '\0';){
        if (chr == 'A'){ // i dont know how to find out if we ended the A phase...
            // deleteGraph_cmd(head);
            // scanf("%d",&num_of_nodes);
            // scanf("%c",&chr);
            // idx = 0;

            // flag = 0;
            // while(idx < num_of_nodes){
            //     scanf("%c");
            //     scanf("%d",&node_id);
            //     n = (pnode)malloc(sizeof(node));
            //     n->node_id = node_id;
                
                
            //     scanf("%c",&chr);
            //     scanf("%d");
            //     if(chr == 'n'){
            //         flag = 1;    
            //     }   
            //     else if(flag == 1){ // input for edges

            //     }
            //     else if(flag == 0){ // input for node_id

            //     }

            // }

        }
        else if (chr == 'B'){ // same as with A
            // scanf("%d",node_id);
            // n = get_node(*head, node_id);
            // if (n == NULL){
            //     n = (pnode)malloc(sizeof(node));
            //     if (n == NULL){
            //         printf("couldnt allocate memory.. RIP\n");
            //         return -1;
            //     }
            // }
            // else {
            //     freeEdges(n->edges);
            // }
            // scanf("%c",&chr);
            // while (chr)

        }
        else if (chr == 'D'){ // delete node
            scanf("%d",node_id);
            delete_node_cmd(head, node_id);

            scanf("%c",&chr);
        }
        else if (chr == 'S'){ // shortest path
            int src, dest;
            scanf("%d",src);
            scanf("%d",dest);
            printf("Dijsktra shortest path: %d\n",shortsPath_cmd(*head, src, dest));

            scanf("%c",&chr);
        }
        else if (chr == 'T'){ // TSP - idont know when we ended to get inputs for TSP...
            int size = get_size(*head);
            int * arr = (int*)malloc(size*sizeof(int));
            int i = 0;
            scanf("%d",&num);
            while (isdigit(num) != 0){
                arr[i] = (int)chr;
                i++;
                //
                scanf("%d",&num); // even if we know its not a digit...... we cant xfer it to char ...
                //
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
    // get_node(*head, 18);
