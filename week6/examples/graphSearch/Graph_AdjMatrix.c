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

//returns the number of adjacent vertices
//O(V)
Vertex *  adjacentVertices(Graph g, Vertex v, int *nV){
    //NOT IMPLEMENTED
    return NULL;
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
    assert(nV >= 0); 
    int i, j; 
    Graph g = malloc(sizeof(struct GraphRep)); 
    assert(g != NULL); 
    g->edges = malloc(nV * sizeof(int *)); 
    assert(g->edges != NULL); 
    for (i = 0; i < nV; i++) { 
        g->edges[i] = malloc(nV * sizeof(int)); 
        assert(g->edges[i] != NULL); 
        for (j = 0; j < nV; j++) {
            g->edges[i][j] = 0;
        }
    } 
    g->nV = nV; 
    g->nE = 0; 
    return g; 
}

//Insert an edge into a graph
void insertE(Graph g, Edge e) { 
    assert(g != NULL && validV(g,e.v) && validV(g,e.w) && e.v != e.w); 
    if (! g->edges[e.v][e.w]){ 
        g->edges[e.v][e.w] = 1; 
        g->edges[e.w][e.v] = 1; //remove this line for a directed graph
        g->nE++; 
        
    }
} 

// remove an edge from a graph
void removeE(Graph g, Edge e) { 
   assert(g != NULL && validV(g,e.v)&& validV(g,e.w)); 
   if (g->edges[e.v][e.w]){ 
      g->edges[e.v][e.w] = 0; 
      g->edges[e.w][e.v] = 0; //remove this line for a directed graph
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
Edge * edges(Graph g, int * nE) { 
     //NOT IMPLEMENTED     
     return NULL; 
} 


int numV(Graph g){
    assert(g != NULL);
    return g->nV;
}

int numE(Graph g){
    assert(g != NULL);
    return g->nE;
}



int degree(Graph g, Vertex v){
    //NOT IMPLEMENTED
    return -1;

}
void destroyGraph(Graph g){
  printf("Destroy not done");  
}

/**
This section demonstrates some graph algorithms
They are all based on either depth first search or breadth first search
with slight modifications to acheive a particular task
There is a lot of duplicated code as I wanted to keep each task separate for 
illustrative purposes
**/



int * pre = NULL; //order and visited
Vertex *st = NULL; //parent - path
int count;

//Assume you have done a dfs or bfs starting at Vertex v.
//This would print the path backwards
//Exercise: try to print the path forwards
void printPath(Vertex v, Vertex w){
    Vertex current = w;
    printf("Printing path in reverse order\n");


    while(current != v && current != -1){
        printf("%d ",current);
        current = st[current];
    } 
    printf("%d\n", current);
           


}

//Recursive depth first function
//starting edge: e.v = 0, e.w = 0
static void dfsR(Graph g,Edge e){
    //e.v is the predecessor
    //e.w is the vertex we are visiting
    pre[e.w] = count++;
    st[e.w] = e.v;
 
    printf("Visiting %d\n",e.w);
    Vertex i;
    for(i = 0; i < g->nV; i++){
        if(g->edges[e.w][i] != 0){ //I am adjacent
            if(pre[i] == -1){ //If I have not visited
	            dfsR(g,mkEdge(g,e.w,i));
            } 
        }
    }
    
    printf("No more to visit - backtrack to parent %d\n",e.v);
}

//This function initialises the pre, st and counter and calls
//the dfsR function with a start vertex of 0
void dfSearch(Graph g){
    int i;
    pre = malloc(sizeof(int) * g->nV);
    st = malloc(sizeof(int) * g->nV);
   
    count = 0;
    
    for(i=0; i< g->nV; i++){
        pre[i] = -1;
        st[i] = -1;
      
    }
    //In this implementation we want to visit everything.
    for(i = 0; i < g->nV; i++){
        if(pre[i] == -1){
           dfsR(g,mkEdge(g,i,i));
          
        }
    }
    printf("pre : ");
    for(i=0; i < g->nV; i++){
        printf("%d ",pre[i]);
    }
    printf("\nst: ");

   for(i=0; i < g->nV; i++){
        printf("%d ",st[i]);
    }
    printf("\n");
 
    //We might not want to destroy these yet if we 
    //wanted to use them :)
    free(pre);
    free(st);
}

//A recursive function to label connected components
//Iterative version of dfs using a stack
static void dfs (Graph g, Edge e) {   
    int i;
    Stack s = newStack();
    StackPush (s,e);  
    while (!StackIsEmpty(s)) {
        e = StackPop(s);
        if (pre[e.w] == -1) {
	   printf("Visit %d\n",e.w);
           pre[e.w] = count++;
           st[e.w] = e.v;
           for (i = 0; i < g->nV; i++) {        
              if ((g->edges[e.w][i] == 1)&&(pre[i] == -1)) {	            
		    StackPush (s,mkEdge(g,e.w,i));
              }
           }
        }
     }
     
}    

//The initialisation of variables etc before we call the dfs function
void dfSearchIterative(Graph g){
    printf("\nDFS ITERATIVE\n");
    assert(g != NULL);
    int v;
    count = 0;
                
    pre = malloc(sizeof(int)*g->nV);
    st = malloc(sizeof(int)*g->nV);
    for(v=0;v<g->nV;v++) {
        pre[v] = -1;
        st[v] = -1;
    }
    for(v=0;v < g->nV; v++){
       if(pre[v] == -1){
            dfs(g,mkEdge(g,v,v));
        } 
    }
     int i;
     printf("pre : ");
    for(i=0; i < g->nV; i++){
        printf("%d ",pre[i]);
    }
    printf("\nst: ");
            
   for(i=0; i < g->nV; i++){
        printf("%d ",st[i]);
    }
    printf("\n");
    

    free(pre);
    free(st);
}

// Improved version of bfs where we avoid unecessarily adding items 
// to the queue that are already on the queue.
static void bfs (Graph g, Edge e) {   
    int i;
    Queue q = newQueue();
    QueueJoin (q,e);
    while (!QueueIsEmpty(q)) {
        e = QueueLeave(q);
        printf("Visit %d\n",e.w);
        for (i = 0; i < g->nV; i++)  {    
            if ((g->edges[e.w][i] != 0)&&(pre[i] == -1)) {	    
               QueueJoin (q,mkEdge(g,e.w,i));
               pre[i] = count++;
               st[i] = e.w;
            }
        }
    }
}     


//Simple version of breadth first search where 
//the stack is swapped for a queue
void simpleBfs (Graph g, Edge e) {   
    int i;
    Queue q = newQueue();
    QueueJoin(q,e);
    while (!QueueIsEmpty(q)) {
        e = QueueLeave(q);
        if(pre[e.w] == -1){
            printf("Visit %d\n",e.w);
            pre[e.w] = count++;
            st[e.w] = e.v;
            for (i = 0; i < g->nV; i++){           
                if ((g->edges[e.w][i] != 0)&&
                             (pre[i] == -1)) {	          
                    QueueJoin (q,mkEdge(g,e.w,i));
               }
            }
         }
     }
}     



void bfSearch(Graph g){
    assert(g != NULL);
    int v;
    count = 0;

    pre = malloc(sizeof(int)*g->nV);
    st = malloc(sizeof(int)*g->nV);
    for(v=0;v<g->nV;v++) {
        pre[v] = -1;
        st[v] = -1;
    }
    for(v=0;v < g->nV; v++){
       if(pre[v] == -1){
            bfs(g,mkEdge(g,v,v));
        }
    }
       int i;
     printf("pre : ");
    for(i=0; i < g->nV; i++){
        printf("%d ",pre[i]);
    }
    printf("\nst: ");
        
   for(i=0; i < g->nV; i++){
        printf("%d ",st[i]);
    }
    printf("\n");
               
               
    free(pre);
    free(st);

    
}

static int isCycleR(Graph g, Edge e){

   int i, w = e.w;  
   pre[w] = count++;
   st[w] = e.v;  
   for (i=0; i < g->nV; i++){    
       if ((g->edges[w][i] == 1) && (pre[i] == -1)) {    
           if(isCycleR (g, mkEdge(g,w,i))) 
               return 1;    
       } else if( (g->edges[w][i] == 1) && i != e.v){ 
           //if it is not the predecessor
           return 1;
       }  
   }
   return 0;
}

int isCycle(Graph g){
    int i;
    pre = malloc(sizeof(int) * g->nV);
    st = malloc(sizeof(int) * g->nV);
   
    count = 0;
    
    for(i=0; i< g->nV; i++){
        pre[i] = -1;
        st[i] = -1;
      
    }
    for(i = 0; i < g->nV; i++){
        if(pre[i] == -1){
	  if(isCycleR(g,mkEdge(g,i,i))) return 1;
          
        }
    }
    return 0;
}


void findPath(Graph g, Vertex src,Vertex dest){
    assert(g != NULL);  
    int v;
    count = 0;
   
    pre = malloc(sizeof(int)*g->nV);
    st = malloc(sizeof(int)*g->nV);    
   
    for(v=0;v<g->nV;v++) {
        pre[v] = -1;
        st[v] = -1;
    }
    
    //this would find all paths from src to all possible destinations
    //could rewrite a dfsR to stop when dest was found
    dfsR(g,mkEdge(g,src,src));
    free(pre);
    free(st);
}

void findShortestPath(Graph g, Vertex src,Vertex dest){
    assert(g != NULL);
    int v;
    count = 0;
   
    pre = malloc(sizeof(int)*g->nV);
    st = malloc(sizeof(int)*g->nV);
    for(v=0;v<g->nV;v++) {
        pre[v] = -1;
        st[v] = -1;
    }
    
    bfs(g,mkEdge(g,src,src));
    //this would find all paths from src to all possible destinations
    //could rewrite a bfs to stop when dest was found
    free(pre);
    free(st);

}

//A recursive function to label connected components
//Labels everything connected and visited in a dfs with the same label
static void connectedComps(Graph g,Edge e,int cc[], int * cCount){
    //e.v is the predecessor
    //e.w is the vertex we are visiting
    pre[e.w] = count++;
    st[e.w] = e.v;
    cc[e.w] = *cCount;
    printf("Visiting %d labelling it %d %d\n",e.w,*cCount,cc[e.w]);
    Vertex i;
    for(i = 0; i < g->nV; i++){
        if(g->edges[e.w][i] != 0){
            if(pre[i] == -1){
                    connectedComps(g,mkEdge(g,e.w,i),cc,cCount); 
            } 
        }
    }
    
    printf("No more to visit - backtrack to parent %d\n",e.v);
}


int numConnectedComponents(Graph g){
   int i;
    pre = malloc(sizeof(int) * g->nV);
    st = malloc(sizeof(int) * g->nV);
    int * cc = malloc(sizeof(int) * g->nV);

    count = 0;
    int cCount = 0;
    for(i=0; i< g->nV; i++){
        pre[i] = -1;
        st[i] = -1;
        cc[i] = -1;
    }
    for(i = 0; i < g->nV; i++){
        if(pre[i] == -1){
           connectedComps(g,mkEdge(g,i,i),cc,&cCount);         
           cCount++;
        }
    }
    return cCount;
}


