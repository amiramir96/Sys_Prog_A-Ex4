#include <stdio.h>
#include <stdlib.h>

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

void printGraph_cmd(pnode head){
    pnode p = head;
    pedge e;
    while(p){
        e = p->edges;
        printf("node id: %d out_edges: ",p->node_num);
        while(e){
            printf("(to %d, weight %d) ",e->endpoint, e->weight);
            e = e->next;
        }
        p = p->next;
        printf("\n");
    }
}


void deleteGraph_cmd(pnode *head){
    pnode* p = head;
    pedge e;
    pnode toFreeNode;
    pedge toFreeEdge;

    while(*p)
    {
        toFreeNode = *p;
        e = toFreeNode->edges;
        while (e){
            toFreeEdge = e;
            e = e->next;
            free(toFreeEdge);
        }
        p = &((*p)->next);
        free(toFreeNode);
    }
    return;
}

void build_graph_cmd(pnode *head){
    if (*head){
        deleteGraph_cmd(&head[0]);
    }
}

void insert_node_cmd(pnode *head, pnode item){
    if ((*head)->node_num > item->node_num){
        item->next = *head;
        return;
    }

    pnode* p = head;
    pnode next = (*p)->next;
    while(next){
        if(next->node_num > item->node_num){
            (*p)->next = item;
            item->next = next;
            return;
        }
        next = next->next;
        p = &((*p)->next);
    }
    
    (*p)->next = item;
    item->next = NULL;
    return;
}

void delete_node_cmd(pnode *head, int node_id);





