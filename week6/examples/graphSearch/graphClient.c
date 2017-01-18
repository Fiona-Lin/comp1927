#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "Graph.h"
#include "time.h"


#define MAXLINE 100

void usage(void);

int randV(Graph g){
    return numV(g) *(rand()/(RAND_MAX + 1.0));
}

Graph randomGraph(int V, int E){
    Graph g = newGraph(V);
    while(numE(g) < E){
        int v = randV(g);
        int w = randV(g);
        if(v != w){
	       insertE(g,mkEdge(g,v,w));
        }
    }
    return g;
}

Graph graphScan(char * edgeFile){
    int N;
    char line[MAXLINE];
    Vertex v1, v2;
    FILE *in;
    if ((in = fopen(edgeFile,"r")) == NULL) {
        fprintf(stderr,"Can't open edge file\n");
        usage();
    }
    // first line contains #vertices
    fgets(line,MAXLINE,in);
    sscanf(line,"%d",&N);
    Graph graph = newGraph(N);
    // rest of lines contain edges
    while (fgets(line,MAXLINE,in) != NULL) {
        if (sscanf(line,"%d %d",&v1,&v2) != 2)
            fprintf(stderr,"Bad edge (%d,%d)\n",v1,v2);
        else
            insertE(graph, mkEdge(graph,v1,v2));
    }
    return graph;
}



int main(int argc, char * argv[]){
    
    srand(time(NULL));

    Graph graph;
    int N; char *edgeFile;
    char line[MAXLINE];
    Vertex v1, v2;
    int n;

    // collect command-line params
    if (argc < 2) usage();
    if (isdigit(argv[1][0])){ 
        N = atoi(argv[1]); edgeFile = NULL;
         
    } else { 
        N = 0; edgeFile = argv[1]; 
    }

    //build graph
    if (edgeFile == NULL)
        graph = randomGraph(N,(N*(N-1))/3);
    else {
        graph = graphScan(edgeFile);
    }
    
    showGraph(graph);
    printf("\n> ");
    while (fgets(line,MAXLINE,stdin) != NULL) {
        switch (line[0]) {
        case 'a':
            if (sscanf(line,"a %d %d",&v1,&v2) != 2)
                printf("Usage: a v1 v2\n");
            else if (isAdjacent(graph,v1,v2))
                printf("Adjacent %d %d\n",v1,v2);
            else
                printf("Not adjacent %d %d\n",v1,v2);
            break;
       case 'p':
            if (sscanf(line,"p %d %d",&v1,&v2) != 2)
                printf("Usage: p v1 v2\n");
            else if (isPath(graph,v1,v2))
                printf("Path %d %d\n",v1,v2);
            else
                printf("No path %d %d\n",v1,v2);
            break; 
        case 'f': 
	    if (sscanf(line,"f %d %d",&v1,&v2) != 2) //complete
                printf("Usage: f v1 v2\n");
            else {
                findPath(graph,v1,v2);
                printPath(v1,v2);
            }
            break;
        case 's': 
	    if (sscanf(line,"s %d %d",&v1,&v2) != 2) //complete
                printf("Usage: f v1 v2\n");
            else{
                findShortestPath(graph,v1,v2);
                printPath(v1,v2);
            }
            break;
        case 'd':
            dfSearch(graph);
            dfSearchIterative(graph);
            break;
        case 'b':
            bfSearch(graph);
            break;
        case 'c':
	  if(isCycle(graph)){ //THIS CODE HAD A BUG
	    printf("Graph contains a cycle\n");
          } else {
	    printf("Graph has no cycles\n");
          }
	    
          break;
         case 'n':
            
            n = numConnectedComponents(graph); 
            printf("There are %d connected components\n",n);    
            break;


        case 'q':
            destroyGraph(graph);
            return 0;    
        default:
	    printf("Try again...");
             break;
        }

        printf("\n");
        showGraph(graph);
        printf("\n> ");
    }
    
    printf("\n");
    destroyGraph(graph);
   
    return 0;
}

void usage()
{
        fprintf(stderr, "Usage: glab #Vertices [EdgeFile]\n");
        exit(1);
}
