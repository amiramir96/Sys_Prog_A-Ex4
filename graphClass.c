#include <stdio.h>
#include <stdlib.h>

typedef struct GRAPH_NODE_ *pnode; // shall be declared before struct edge since we hold node pointer inside the edge

typedef struct edge_ { // edge struct
    int weight;
    pnode endpoint;
    struct edge_* next;
} edge, *pedge;

typedef struct GRAPH_NODE_ { // node struct
    int node_id;
    pedge edges;
    struct GRAPH_NODE_* next;
} node, *pnode;

void printGraph_cmd(pnode head){
    /*print graph, loop over the whole list of nodes, and print node_id then all its edges details*/
    // init vars
    pnode p = head;
    pedge e;
    while(p){
        // loop over all the node "linked list"
        e = p->edges;
        printf("node id: %d out_edges: ",p->node_id);
        while(e){
            // loop over all the edges of specific node
            printf("(to %d, weight %d) ",e->endpoint->node_id, e->weight);
            e = e->next;
        }
        p = p->next;
        printf("\n");
    }
}

void freeEdges(pedge eHead){
    /* loop over all the edges of specific node and delete them -> means, free those edges */
    pedge toFreeEdge;
    while (eHead){
        toFreeEdge = eHead;
        eHead = eHead->next;

        free(toFreeEdge);
    }
}


void deleteGraph_cmd(pnode* head){
    /* delete the whole graph, shall free every node and edge structs*/
    // init vars
    pnode* p = head;
    pedge e;
    pnode toFreeNode;
    pedge toFreeEdge;
    
    while(*p)
    // loop over all the node "linked list"
    {
        toFreeNode = *p;
        e = toFreeNode->edges;
        if (e != NULL){
            freeEdges(e);    
        }
        p = &((*p)->next);
        free(toFreeNode);
    }
    return;
}

void build_graph_cmd(pnode * head){
    if (*head){
        deleteGraph_cmd(&head[0]);
    }
}

void insert_node_cmd(pnode * head, pnode item){
    /* insert node item via node_id order 
    3 scenrios:
        1- item shall be added as the new head of the list
        2- item shall be added somewhere in the middle of the list
        3- item shall be added as the last item of the list
         */
    // case 1:
    if ((*head)->node_id > item->node_id){
        item->next = *head;
        *head = item;
        return;
    }
    
    // init vars
    pnode* p = head;
    pnode next = (*p)->next;
    
    // case 2:
    while(next){
    // loop over all the node "linked list"
        if(next->node_id > item->node_id){
            (*p)->next = item;
            item->next = next;
            return;
        }
        next = next->next;
        p = &((*p)->next);
    }
    
    // case 3:
    (*p)->next = item;
    item->next = NULL;
    return;
}

void delete_node_cmd(pnode * head, int node_id){
    /*
    stages:
        1- find the node along the list
        2- remove(and free) all his IN_EDGES from the other nodes (they OUT_EDGES at the other nodes)
        3- remove(and free) the node and his outEdges
    */
    // stage 1:
    pnode node_to_del;
    pnode p = *head;
    if (p->node_id == node_id){ // node to delete is first in the linked list
        node_to_del = p;
        *head = p->next;
    }
    else { // not the first -> shall loop over the list and get it.
        pnode prevNode;   
        while (p != NULL){
            prevNode = p;
            if(p->next->node_id == node_id){
                node_to_del = p->next; // save the node we gonna delete
                prevNode->next = node_to_del->next;  // change his prevNode.next to point on the next of the delete_node
                break;
            }   
            p = p->next;
        }
    }
    // stage 2:
    p = *head;
    pedge eHead;
    pedge prev;
    pedge toDeleteEdge;
    while (p != NULL){
        pedge eHead = p->edges;
        /* loop over all the edges of specific node and delete them -> means, free those edges */
        if (eHead != NULL && eHead->endpoint->node_id == node_id){
            toDeleteEdge = eHead;
            eHead = eHead->next;
            free(toDeleteEdge);
            p->edges = eHead;
            eHead = NULL; // found the relevant edge to remove and deleted it.
        }
        while (eHead != NULL){
            prev = eHead;
            if (eHead->next != NULL && eHead->next->endpoint->node_id == node_id){
                toDeleteEdge = eHead->next;
                prev->next = toDeleteEdge->next;
                free(toDeleteEdge);
                eHead = NULL; // found the relevant edge to remove and deleted it.
                // ^ kinda like break
            }
            else {
                eHead = eHead->next;
            }
        }    
        p = p->next;
    }
    // stage 3:
    freeEdges(node_to_del->edges);
    free(node_to_del);           
}

pnode get_node(pnode head, int node_id){
    pnode p = head;
    while (p){
        if (p->node_id == node_id){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int get_size(pnode head){
    pnode p = head;
    int size = 0;
    while (p){
        size++;
        p = p->next;
    }
    return size;
}

int main(){
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
    printf("printed again^^\n\n");
    get_node(*head, 18);

    char chr, in;
    int flag;
    pnode * head;
    pnode n;
    pedge e;

    for(;;){
        scanf("%c",&chr);
        if (chr == 'A'){
            flag = 0;
            while(1){
                scanf("%c",&chr);
                if(chr == 'n'){
                    flag = 1;    
                }   
                else if(flag == 1){ // input for edges

                }
                else if(flag == 0){ // input for node_id

                }

            }

        }


    }




}




// void removeDestNodeFromEdges(pedge eHead, int node_id){
//     /* loop over all the edges of specific node and delete them -> means, free those edges */
//     pedge toDeleteEdge;
//     pedge prev;
//     prev = eHead;
//     if (eHead->endpoint->node_id == node_id){
//         toDeleteEdge = eHead;
//         eHead = eHead->next;
//         free(toDeleteEdge);
//         return; // found the relevant edge to remove and deleted it.
//     }
//     pedge p = eHead;
//     prev = p;
//     while (p){
//         p = p->next;
//         if (p->endpoint->node_id == node_id){
//             toDeleteEdge = p;
//             p = p->next;
//             prev->next = p;
//             free(toDeleteEdge);
//             return; // found the relevant edge to remove and deleted it.
//         }
//     }
// }