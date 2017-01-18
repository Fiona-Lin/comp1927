#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Stack.h"
#include "Queue.h"

//An implementation of an undirected, unweighted graph.
//This demonstrates the use of some graph algorithms

struct GraphRep { 
    int nV;        // #vertices 
    int nE;        // #edges 
    int **edges;   // matrix of booleans (0 or 1)
}; 



static int validV(Graph g, Vertex v) ;

//returns 1 if there is an edge from v to w
//O(1)
int isAdjacent(Graph g, Vertex v, Vertex w){

    assert(g != NULL && validV(g,v) && validV(g,w));
    return g->edges[v][w];
}

//returns the adjacent vertices and sets *nV to the number
//of adjacent vertices returned.
//O(V)
Vertex *  adjacentVertices(Graph g, Vertex v, int *nV){
    Vertex * adj = malloc(g->nV * sizeof(Vertex));
    int i;
    int counter = 0;
    for(i = 0; i < g->nV; i++){
        if(g->edges[v][i] == 1){
            adj[counter++] = i;
        }
    }

    *nV = counter;
    return adj;
}

// local checking function 
static int validV(Graph g, Vertex v) { 
    return (v >= 0 && v < g->nV); 
} 

// Create an edge from v to w 
Edge mkEdge(Graph g, Vertex v, Vertex w) { 
    assert(validV(g,v) && validV(g,w));
    Edge e = {v,w}; 
    return e; 
} 

//Initialise a new graph
Graph newGraph(int nV) { 
    int i,j;
   
    assert(nV >= 0); 
    Graph g = malloc(sizeof(struct GraphRep));
    assert(g != NULL);
    
    g->edges = malloc(nV *sizeof(int *));
    for(i=0; i < nV; i++){
        g->edges[i] = malloc(nV * sizeof(int));
        for(j=0; j < nV; j++){
            g->edges[i][j] = 0;
        }
    }
    g->nV = nV;
    g->nE = 0;
    return g; 
}

//Insert an edge into a graph
//O(1)
void insertE(Graph g, Edge e) { 
    assert(g != NULL && validV(g,e.v) && validV(g,e.w) && e.v != e.w); 
    Vertex v1 = e.v;
    Vertex v2 = e.w;
   
    if(g->edges[v1][v2] == 0){
       g->edges[v1][v2] = 1;
       g->edges[v2][v1] = 1;
       g->nE++;     
    }

} 

// remove an edge from a graph
void removeE(Graph g, Edge e) { 
   assert(g != NULL && validV(g,e.v)&& validV(g,e.w)); 
   

   if(g->edges[e.v][e.w] == 1){
       g->edges[e.v][e.w] = 0;
       g->edges[e.w][e.v] = 0;
       g->nE--; 

   }
} 


//Display the graph
void showGraph(Graph g) { 
    assert(g != NULL); 
    printf("V=%d, E=%d\n", g->nV, g->nE); 
    int i, j; 
    for (i = 0; i < g->nV; i++) { 
        int nshown = 0; 
        for (j = 0; j < g->nV; j++) { 
            if (g->edges[i][j] != 0) { 
                printf("%d-%d ",i,j); 
                nshown++; 
            } 
        } 
        if (nshown > 0) {
           printf("\n"); 
        }
    } 
}

// get all the edges from the graph and put them in the array
// return the number of edges
Edge *edges(Graph g, int * nE) { 
     Edge *e = malloc(g->nE*sizeof(Edge));
     *nE = g->nE;
     int v,w,i;
     for (v=0; v<=g->nV; v++) {
        for (w=v+1; w < g->nV; w++) {
           if (g->edges[v][w]) 
              e[i++] = mkEdge(g,v,w);
        }
     }
     return e;
} 


int numV(Graph g){
    assert(g != NULL);
    return g->nV;
}

int numE(Graph g){
    assert(g != NULL);
    return g->nE;
}

//O(V)
int degree(Graph g, Vertex v){
    int d = 0;
    int i;
    
    for(i=0;i < g->nV; i++){
        if(g->edges[v][i] == 1){
            d++;
        }
    }
    return d;
}

void destroyGraph(Graph g){
  printf("Destroy not done");  
}

