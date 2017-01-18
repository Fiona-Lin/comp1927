// An interface for a weighted graph!

// vertices denoted by integers 0..N-1 
typedef int Vertex; 

// edges are pairs of vertices (end-points) 
typedef struct { 
    Vertex v; 
    Vertex w; 
    float weight;
} Edge; 

Edge mkEdge(Vertex, Vertex, float); 

// graph representation is hidden 
typedef struct graphRep *Graph; 

// operations on graphs 
Graph newGraph(int nV); // #vertices 
void insertE(Graph g, Edge e); 
void removeE(Graph g, Edge e); 

//returns 1 if there is ad adge from v to w
int isAdjacent(Graph g,Vertex v, Vertex w);
int adjacentVertices(Graph g, Vertex v, Vertex adj[]);
int adjacentEdges(Graph g, Vertex v, Edge adj[]);

// returns #vertices & array of edges int
int edges(Edge es[], int nE, Graph g); 

int numV(Graph g);
int numE(Graph g);

Graph copy(Graph g); 
void destroy(Graph g); 
void show(Graph g); 

int isPath(Graph g,Vertex v, Vertex w);

//Shortest path algorithm
void dijkstra(Graph g,Vertex s,int st[],double dist[]);

//MST algorithms
void prim(Graph g, int st[],double dist[]);
void printMST(int nV,int st[], double dist[]);

void kruskal(Graph g,Graph mst);
