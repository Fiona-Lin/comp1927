//An adjacency matrix representation of a directed, weighted graph 

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "Graph.h"
#include "Item.h"
#include "pq.h"

#define NO_EDGE FLT_MAX

typedef struct graphRep GraphRep; 

struct graphRep { 
    int nV; // #vertices 
    int nE; // #adj 
    float **adj; // matrix of booleans (0 or 1)
}; 

static int validV(Graph g, Vertex v) ;

//returns 1 if there is an edge from v to w
//O(1)
int isAdjacent(Graph g, Vertex v, Vertex w){
    assert(g != NULL && validV(g,v) && validV(g,w));
    if(g->adj[v][w] == NO_EDGE) return 0;
    return 1;
}

//returns the number of adjacent vertices
//O(V)
int adjacentVertices(Graph g, Vertex v, Vertex adj[]){
    int counter=0;
    int i=0;
    for(i=0;i<g->nV;i++){
        if(g->adj[v][i] != NO_EDGE){
            adj[counter]=i;
            counter++;
        }
    }
    return counter;
}

int adjacentEdges(Graph g, Vertex v, Edge adj[]){
    int counter=0;
    int i=0;
    for(i=0;i<g->nV;i++){
        if(g->adj[v][i] != NO_EDGE){
            adj[counter]=mkEdge(v,i,g->adj[v][i]);
            counter++;
        }
    }
    return counter;

}

// local checking function 
static int validV(Graph g, Vertex v) { 
    return (v >= 0 && v < g->nV); 
} 

// Create an edge from v to w
// Allows self loops 
Edge mkEdge(Vertex v, Vertex w, float weight) { 
    assert(v >= 0 && w >= 0); 
    Edge e = {v,w,weight}; 
    return e; 
} 

//Initialise a new graph
Graph newGraph(int nV) { 
    assert(nV >= 0); 
    int i, j; 
    Graph g = malloc(sizeof(GraphRep)); 
    assert(g != NULL); 
    g->adj = malloc(nV * sizeof(int *)); 
    assert(g->adj != NULL); 
    for (i = 0; i < nV; i++) { 
        g->adj[i] = malloc(nV * sizeof(int)); 
        assert(g->adj[i] != NULL); 
        for (j = 0; j < nV; j++) g->adj[i][j] = NO_EDGE; 
    } 
    g->nV = nV; 
    g->nE = 0; 
    return g; 
}

//Insert an edge into a graph
void insertE(Graph g, Edge e) { 
    assert(g != NULL && validV(g,e.v) && validV(g,e.w)); 
    if (!g->adj[e.v][e.w]== NO_EDGE) 
        return; 
    g->adj[e.v][e.w] = e.weight; 
    g->adj[e.w][e.v] = e.weight;
    g->nE++; 
} 

// remove an edge from a graph
void removeE(Graph g, Edge e) { 
   assert(g != NULL && validV(g,e.v)&& validV(g,e.w)); 
   if (g->adj[e.v][e.w] == NO_EDGE) 
       return; 
   g->adj[e.v][e.w] = NO_EDGE; 
   g->nE--; 
} 

//Display the graph
void show(Graph g) { 
    assert(g != NULL); 
    printf("V=%d, E=%d\n", g->nV, g->nE); 
    int i, j; 
    for (i = 0; i < g->nV; i++) { 
        int nshown = 0; 
        for (j = 0; j < g->nV; j++) { 
            if (g->adj[i][j] != NO_EDGE) { 
                printf("%d-%d : %lf ",i,j,g->adj[i][j]); 
                nshown++; 
            } 
        } 
        if (nshown > 0) printf("\n"); 
    } 
}

// get all the edges from the graph and put them in the array es
// return the number of edges
int edges(Edge es[], int nE, Graph g) { 
     assert(g != NULL && es != NULL && nE > 0); 
     int i, j, n = 0; 
     for (i = 0; i < g->nV; i++) { 
         for (j = 0; j < g->nV; j++) { 
             if (g->adj[i][j] != NO_EDGE) { 
                 assert(n < nE); 
                 es[n++] = mkEdge(i,j,g->adj[i][j]); 
             } 
         } 
     } 
     return n; 
} 


int numV(Graph g){
    assert(g != NULL);
    return g->nV;
}

int numE(Graph g){
    assert(g != NULL);
    return g->nE;
}

void dijkstra(Graph g,Vertex s,int st[],double dist[]){
    int v,t;
    PriQ pq = initPriQ(g->nV);
    //insert each vertex into the pq
    for(v=0;v< g->nV;v++){
        st[v] = -1;
        dist[v] = NO_EDGE; //represents infinity
        Item i = newItem(dist[v],v);
        insert(pq,i);
    } 
    dist[s] = 0.0; //set start veretex dist to 0 
    decreaseWeight(pq,s,dist[s]); // update pq
    while(!isEmpty(pq)){
         v = value(delMin(pq));
         if(dist[v] != NO_EDGE)
             for(t = 0;t < g->nV;t++){
	         if(g->adj[v][t] != NO_EDGE){
	             if(dist[v] + g->adj[v][t] < dist[t]){                    
	                 dist[t] = dist[v] + g->adj[v][t];
                         decreaseWeight(pq,t,dist[t]);
                         st[t] = v;
	             }
             }
         }
    }
}

void prim(Graph g, int st[], double dist[]){
    Vertex v,i;
    PriQ pq = initPriQ(g->nV);
    int * visited = malloc(sizeof(int)*g->nV);
    for(v=0;v < g->nV;v++){
        visited[v] = -1;
        st[v] = -1;
        dist[v] = NO_EDGE; //infinity
        insert(pq,newItem(dist[v],v));
    }
    
    st[0] = 0; 
    dist[0] = 0;   
    decreaseWeight(pq,0,0);
    while(!isEmpty(pq)){
     
        v = (delMin(pq))->value; 
	visited[v] = 1;
        for(i=0;i<g->nV;i++){
	    if(g->adj[v][i] != NO_EDGE && visited[i] == -1){
	        if(g->adj[v][i] < dist[i]){ 
                       dist[i] = g->adj[v][i];
                       decreaseWeight(pq,i,dist[i]);//
                       st[i] = v;
                }
            }
        }
    }
    free(visited);
}


void printMST(int numV,int st[],double dist[]){
  int i;
  double total = 0;
   for(i=1;i<numV;i++){
     printf("%d %d %f\n",st[i],i,dist[i]);
     total+=dist[i];
   }
   printf("Total %f\n",total);
}

int * pre;
int * st;
int cnt;

//extend dfsR to check if there is a path
static int isPathR(Graph g, Edge e, Vertex goal){
    int t, w = e.w; 
    pre[w] = cnt++; 
    st[w] = e.v;      
    if(w == goal) return 1; 
    for(t=0;t<g->nV; t++){
        if(g->adj[w][t] != NO_EDGE) {//if t is adjacent
            if(pre[t] == -1)
                if (isPathR(g,mkEdge(w,t,g->adj[w][t]),goal)) {
		    return 1;
                } 
        }                
    }
    return 0;
}


int isPath(Graph g,Vertex v, Vertex w){
    assert(g != NULL);
    cnt = 0;
    int t;
    pre = malloc(sizeof(int)*g->nV);
    st = malloc(sizeof(int)*g->nV);
    for(t=0;t<g->nV;t++) {
        pre[t] = -1;
        st[t] = -1;
    }  
   
    return isPathR(g,mkEdge(v,v,0),w);
}

