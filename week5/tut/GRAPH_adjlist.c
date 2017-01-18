//This implements an undirected unweighted graph
//This implementation allows parallel edges

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "GRAPH.h"


typedef struct vnode * vlink;
struct vnode {
    Vertex v;
    vlink next;
};

struct graph {
    int V;
    int E;
    vlink **edges; //an array of linked lists
};


Edge EDGE (Vertex v, Vertex w ) {
    Edge e = {v, w};
    return e;
}

int GRAPHvalidEdge(Graph g, Edge e){
    assert(g != NULL);
    return (e.v >= 0 && e.v < g->V &&
            e.w >= 0 && e.w < g->V );
}

//Creates a new node and sets the next link
vlink NEW (Vertex v, vlink next) {
    vlink x = malloc (sizeof *x);

    x->v = v;
    x->next = next;
    return x;
}

//O(V)
Graph GRAPHinit (int V) {
    int v, w;
    Graph G = malloc (sizeof *G);

    G->V = V;
    G->E = 0;

    G->edges = malloc (V * sizeof(vlink));
    for (v = 0; v < V; v++){
        G->edges[v] = malloc ((V - v) * sizeof(vlink));
        for (w = v + 1; w < V; v++){
            G->edges[v][w] = 0;
        }
    }
    return G;
}

void GRAPHdestroy (Graph g) {
    // not implemented yet
}

Graph GRAPHcopy(Graph g){
    //not implemented yet
    return NULL;
}

//Undirected graph. So each edge
//is stored twice - once from v
//and once from w
//O(1)
//This does not check for parallel edges
//To do so would make it O(n)
void GRAPHinsertE(Graph G, Edge e){
    if(GRAPHvalidEdge(G,e) && e.v != e.w){
        int v = e.v;
        int w = e.w;

        G->edges[v][w] = 1;
        G->edges[w][v] = 1;
        G->E++;
    } else {
        printf("Edge not valid ignoring ");
        GRAPHEdgePrint(e);
        printf("\n");
    }
}
//
//int GRAPHisAdjacent(Graph g,Vertex v, Vertex w){
//    int edgesacent = 0;
//    return ;
//}
//
//int GRAPHedgesacentVertices(Graph g, Vertex v, Vertex edges[]){
//    int counter = 0;
//    vlink tmp = g->edges[v];
//    while(tmp != NULL){
//        edges[counter] = tmp->v;
//        counter++;
//        tmp = tmp->next;
//    }
//    return counter;
//}
//
//int GRAPHedges (Edge edges[], Graph g) {
//    int v, E = 0; 
//    vlink t;  
//
//    for (v = 0; v < g->V; v++) {
//        for (t = g->edges[v]; t != NULL; t = t->next) {
//            if (v < t->v) {
//                edges[E++] = EDGE(v, t->v); 
//            }
//        }
//    }
//    return E;
//}
//
//void GRAPHEdgePrint (Edge edge) {
//    printf ("%d -- %d", edge.v, edge.w);
//}
//
//int GRAPHnumV(Graph g){
//    return g->V;
//}
//
//int GRAPHnumE(Graph g){
//    return g->E;
//}
//
//void GRAPHshow(Graph g){
//    printf("V=%d, E=%d\n", g->V, g->E); 
//    int i; 
//    for (i = 0; i < g->V; i++) { 
//        vlink tmp = g->edges[i]; 
//        while (tmp != NULL) { 
//            printf("%d-%d ",i,tmp->v); 
//            tmp = tmp->next; 
//        } 
//        if (g->edges[i] != NULL) 
//            printf("\n"); 
//    }
//    printf("\n"); 
//}
