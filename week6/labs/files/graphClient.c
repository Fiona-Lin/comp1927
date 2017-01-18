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
    // ADD Code to test graph search algorithms
    
    printf("\n");
    destroyGraph(graph);
   
    return 0;
}

void usage()
{
        fprintf(stderr, "Usage: glab #Vertices [EdgeFile]\n");
        exit(1);
}
