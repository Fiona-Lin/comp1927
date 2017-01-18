#ifndef GRAPH_H
#define GRAPH_H

// vertices denoted by integers 0..N-1 
typedef int Vertex; 

// edges are pairs of vertices (end-points) 
typedef struct edge{ 
    Vertex v; 
    Vertex w; 
} Edge; 

// graph representation is hidden 
typedef struct GraphRep *Graph; 


Edge mkEdge(Graph g, Vertex v, Vertex w); 
int numV(Graph g);
int numE(Graph g);

// operations on graphs 
Graph newGraph(int nV); // #vertices 
void insertE(Graph g, Edge e); 
void removeE(Graph g, Edge e); 

//returns 1 if there is ad adge from v to w
int isAdjacent(Graph g,Vertex v, Vertex w);
int adjacentVertices(Graph g, Vertex v, Vertex adj[]);
int degree(Graph, Vertex v);

Graph copyGraph(Graph g); 
void destroyGraph(Graph g); 
void showGraph(Graph g); 

//Algorithms on graphs

// dfSearch using Stack
void dfSearchIterative(Graph g);
// dfSearch using Queue
void bfSearch(Graph g);

void findShortestPath(Graph g, Vertex src,Vertex dest);
#endif
