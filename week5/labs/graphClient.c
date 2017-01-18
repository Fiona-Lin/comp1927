#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "GRAPH.h"
#include "time.h"

#define MAXV 5
#define MAXE 10

void testGraphDegree() ;
void testGraphCopy() ;

int eqE(Edge a, Edge b) {
    return (a.v == b.v && a.w == b.w)
            || (a.v=b.w && a.w == b.v);
}

int randV(Graph g){
    return GRAPHnumV(g) *(rand()/(RAND_MAX + 1.0));
}

Graph randomGraph(int V, int E){
    Graph g = GRAPHinit(V);
    while(GRAPHnumE(g) < E){
        int v = randV(g);
        int w = randV(g);
        if(v != w){
            GRAPHinsertE(g,EDGE(v,w));
        }
    }
    return g;
}

Graph graphScan(){
    int v,w;
    int V;
    printf("Enter num vertices : ");
    scanf("%d",&V);
    printf("Enter pairs of vertices between 0 and %d\n",V-1);
    Graph g = GRAPHinit(V);
    while(scanf("%d %d",&v,&w) == 2){
        GRAPHinsertE(g,EDGE(v,w));
    }
    return g;
}

int main(int argc, char * argv[]){
    srand(time(NULL));
    Graph randG = randomGraph(MAXV,MAXE);
    printf("Here is my random graph\n");
    GRAPHshow(randG);
 //   testGraphCopy() ;
    testGraphDegree() ;
//

    Graph g1 = graphScan();
    printf("\nHere is my scanned graph\n");
    GRAPHshow(g1);
    GRAPHdestroy(randG);
    GRAPHdestroy(g1);
    return 0;
}
void testGraphCopy() {
    int i = 0;
    Graph g = NULL;

    printf("------------------------------------------------------");
    printf("\n>>>>> Test Graph GRAPHcopy(Graph) <<<<<\n");
    printf("------------------------------------------------------");

    // copy empty graph
    printf("\n## Test %d: empty tree\n",++i);
    Graph cpy = GRAPHcopy(NULL);
    assert(cpy == NULL);
    printf("\n ## passed ##\n");

    // 2 ways to check.
    // either print and compare visually - show function already
    // implemented ORRRR Compare each node's value iterating through it
    // However, need to check if order's important

    // copy isolated 1 vertex graph
    printf("\n## Test %d: copy isolated 1 vertex graph\n",++i);
    g = randomGraph(1, 0);
    printf("Original Graph:\n");
    GRAPHshow(g);
    cpy = GRAPHcopy(g);
    //check number of vertices
    assert(GRAPHnumV(cpy) == GRAPHnumV(g));
    //check number of edges
    assert(GRAPHnumE(cpy) == GRAPHnumE(g));
    printf("Copied Graph:\n");
    GRAPHshow(cpy);
    GRAPHdestroy(g);
    GRAPHdestroy(cpy);
    printf("\n ## passed ##\n");

    // copy 2 vertices disconnected graph
    printf("\n## Test %d: copy 2 vertices disconnected graph\n",++i);
    g = randomGraph(2, 0);
    printf("Original Graph:\n");
    GRAPHshow(g);
    cpy = GRAPHcopy(g);
    assert(GRAPHnumV(cpy) == GRAPHnumV(g));
    assert(GRAPHnumE(cpy) == GRAPHnumE(g));
    printf("Copied Graph:\n");
    GRAPHshow(cpy);
    GRAPHdestroy(g);
    GRAPHdestroy(cpy);
    printf("\n ## passed ##\n");


    // copy 2 vertices connected graph
    printf("\n## Test %d:  copy 2 vertices connected graph\n",++i);
    g = randomGraph(2, 1);
    printf("Original Graph:\n");
    GRAPHshow(g);
    cpy = GRAPHcopy(g);
    assert(GRAPHnumV(cpy) == GRAPHnumV(g));
    assert(GRAPHnumE(cpy) == GRAPHnumE(g));
    printf("Copied Graph:\n");
    GRAPHshow(cpy);
    GRAPHdestroy(cpy);
    GRAPHdestroy(g);
    printf("\n ## passed ##\n");


    // copy a multi node 2subgaph graph
    printf("\n## Test %d: copy a multi node 2subgaph graph\n",++i);
    g = GRAPHinit(4);
    GRAPHinsertE(g,EDGE(0,1));
    GRAPHinsertE(g,EDGE(3,2));
    printf("Original Graph:\n");
    GRAPHshow(g);
    cpy = GRAPHcopy(g);
    assert(GRAPHnumV(cpy) == GRAPHnumV(g));
    assert(GRAPHnumE(cpy) == GRAPHnumE(g));
    printf("Copied Graph:\n");
    GRAPHshow(cpy);
    GRAPHdestroy(cpy);
    GRAPHdestroy(g);
    printf("\n ## passed ##\n");

    // copy a multi node connected graph
    printf("\n## Test %d: copy a connected graph with max edges\n",++i);
    g = randomGraph(4, 6);
    printf("Original Graph:\n");
    GRAPHshow(g);
    cpy = GRAPHcopy(g);
    assert(GRAPHnumV(cpy) == GRAPHnumV(g));
    assert(GRAPHnumE(cpy) == GRAPHnumE(g));
    printf("Copied Graph:\n");
    GRAPHshow(cpy);
    GRAPHdestroy(cpy);
    GRAPHdestroy(g);
    printf("\n ## passed ##\n");

}

void testGraphDegree() {
    int i = 0;
    int d = 0;
    Graph g = NULL;

    printf("------------------------------------------------------");
    printf("\n>>>>> Test int GRAPHdegree(Graph g, Vertex v) <<<<<\n");
    printf("------------------------------------------------------");

//    // test empty graph, this should stop program
//    printf("\n## Test %d: empty graph\n",++i);
//    Graph cpy = GRAPHcopy(g);
//    assert(cpy == NULL);
//    printf("\n ## passed ##\n");

    // test isolated 1 vertex graph, 0 degree
    printf("\n## Test %d: isolated 1 vertex graph, 0 degree\n",++i);
    g = randomGraph(1, 0);
    GRAPHshow(g);
    d = GRAPHdegree(g, 0);
    assert(d == 0);
    GRAPHdestroy(g);
    printf("\n ## passed ##\n");


    // test 2 vertices disconnected graph, 0 degree
    printf("\n## Test %d:2 vertices disconnected graph,0 degree\n",++i);
    g = randomGraph(2, 0);
    GRAPHshow(g);
    d = GRAPHdegree(g, 0);
    assert(d == 0);
    GRAPHdestroy(g);
    printf("\n ## passed ##\n");


    // test 2 vertices connected graph, 1 degree
    printf("\n## Test %d:2 vertices connected graph, 1 degree\n",++i);
    g = randomGraph(2, 1);
    GRAPHshow(g);
    d = GRAPHdegree(g, 0);
    assert(d == 1);
    GRAPHdestroy(g);
    printf("\n ## passed ##\n");


    // test a 4 vertices disconnected graph, 0 degree
    printf("\n##Test %d:4 vertices disconnected graph,0 degree\n",++i);
    g = GRAPHinit(4);
    GRAPHinsertE(g,EDGE(0,1));
    GRAPHinsertE(g,EDGE(0,2));
    GRAPHshow(g);
    d = GRAPHdegree(g, 3);
    assert(d == 0);
    GRAPHdestroy(g);
    printf("\n ## passed ##\n");

    // test a 4 vertices disconnected graph, 1 degree
    printf("\n##Test %d:4 vertices disconnected graph,1 degree\n",++i);
    g = GRAPHinit(4);
    GRAPHinsertE(g,EDGE(0,1));
    GRAPHinsertE(g,EDGE(3,2));
    GRAPHshow(g);
    d = GRAPHdegree(g, 3);
    assert(d == 1);
    GRAPHdestroy(g);
    printf("\n ## passed ##\n");


    // test a 4 vertices disconnected graph, 2 degree
    printf("\n##Test %d:4 vertices disconnected graph,2 degree\n",++i);
    g = GRAPHinit(4);
    GRAPHinsertE(g,EDGE(0,1));
    GRAPHinsertE(g,EDGE(0,2));
    GRAPHshow(g);
    d = GRAPHdegree(g, 0);
    assert(d == 2);
    GRAPHdestroy(g);
    printf("\n ## passed ##\n");


    // test a 4 vertices disconnected graph, 3 degree
    printf("\n##Test %d:4 vertices connected graph,3 degree\n",++i);
    g = GRAPHinit(4);
    GRAPHinsertE(g,EDGE(0,1));
    GRAPHinsertE(g,EDGE(0,2));
    GRAPHinsertE(g,EDGE(0,3));
    GRAPHshow(g);
    d = GRAPHdegree(g, 0);
    assert(d == 3);
    GRAPHdestroy(g);
    printf("\n ## passed ##\n");


}

