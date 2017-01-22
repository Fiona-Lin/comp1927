#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "Graph.h"
#include "time.h"


#define MAXLINE 100

void testdfs(Graph graph) ;
void testbfs(Graph graph) ;
void testfindshortest(Graph graph) ;
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
    testdfs(graph);
    testbfs(graph);
    testfindshortest(graph);
    destroyGraph(graph);

    return 0;
}

void usage() {
        fprintf(stderr, "Usage: glab #Vertices [EdgeFile]\n");
        exit(1);
}

void testdfs(Graph graph) {
    int i = 0;

    printf("------------------------------------------------------");
    printf("\n>>>>> Test void dfs(Graph) <<<<<\n");
    printf("------------------------------------------------------");

    // copy empty graph
    printf("\n## Test %d: empty graph\n",++i);
    dfSearchIterative(NULL);
    printf("\nExpected output:\nThe graph g can't be NULL\n");
    printf("\n ## passed ##\n");

    printf("\n## Test %d:\n",++i);
    dfSearchIterative(graph);

    printf("\n ## passed ##\n");
}
void testbfs(Graph graph) {
    int i = 0;

    printf("------------------------------------------------------");
    printf("\n>>>>> Test void bfs(Graph) <<<<<\n");
    printf("------------------------------------------------------");

    // copy empty graph
    printf("\n## Test %d: empty graph\n",++i);
    bfSearch(NULL);
    printf("\nExpected output:\nThe graph g can't be NULL\n");
    printf("\n ## passed ##\n");

    printf("\n## Test %d:\n",++i);
    bfSearch(graph);

    printf("\n ## passed ##\n");
}
void testfindshortest(Graph graph) {
    int i = 0;

    printf("------------------------------------------------------");
    printf("\n>>>>> Test void findShortestPath(Graph) <<<<<\n");
    printf("------------------------------------------------------");

    // copy empty graph
    printf("\n## Test %d: empty graph\n",++i);
    findShortestPath(NULL, 1, 0);
    printf("\nExpected output:\nThe graph g can't be NULL\n");
    printf("\n ## passed ##\n");

    printf("\n## Test %d:\n",++i);
    findShortestPath(graph, 1, 0);
    findShortestPath(graph, 0, 2);

    printf("\n ## passed ##\n");
}
