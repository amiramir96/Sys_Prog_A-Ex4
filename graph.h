#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_id;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

// amir ---
// works:
void deleteGraph_cmd(pnode *head);
void build_graph_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void freeEdges(pedge eHead); // delete and free all the edges in that pointer array of edges
void insert_node_cmd(pnode *head, pnode item);
void delete_node_cmd(pnode *head, int node_id);
pnode get_node(pnode * head, int node_id);
int get_size(pnode head);
// ----

int shortsPath_cmd(pnode head, int src, int dest);
int TSP_cmd(pnode head, pnode tspArr);

#endif
