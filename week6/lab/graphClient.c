#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "Graph.h"
#include "time.h"


#define MAXLINE 100

void testdfs() ;
void testbfs() ;
void testfindshortest();
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
      fclose(in);
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
   fclose(in);
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
   destroyGraph(graph);

   printf("\n");
   testdfs();
   testbfs();
   testfindshortest();

   return 0;
}

void usage() {
   fprintf(stderr, "Usage: glab #Vertices [EdgeFile]\n");
   exit(1);
}

void testdfs() {
   int v1, v2, v, i = 0;
   Graph g = NULL;
   printf("------------------------------------------------------");
   printf("\n>>>>> Test void dfs(Graph) <<<<<\n");
   printf("------------------------------------------------------");

   // copy empty graph
   printf("\n## Test %d: empty graph\n",++i);
   dfSearchIterative(g);
   printf("\nExpected output:\nThe graph g can't be NULL\n");
   printf("\n ## passed ##\n");

   v = 3;
   g = newGraph(v);
   for (v1 = 0; v1 < v/2; v1++) {
      for(v2 = v1 + 1; v2 < v; v2++) {
         insertE(g,mkEdge(g, v1, v2));
      }
   }

   // 3 vertices graph
   printf("\n## Test %d: %d vertices graph\n",++i, v);
   showGraph(g);
   dfSearchIterative(g);
   destroyGraph(g);
   printf("\n ## passed ##\n");

   v = 6;
   g = newGraph(v);

   for (v1 = 0; v1 < v/2; v1++) {
      for(v2 = v-1; v2 > v1 + 2; v2--) {
         insertE(g,mkEdge(g, v1, v2));
      }
   }
   showGraph(g);
   dfSearchIterative(g);
   destroyGraph(g);
   printf("\n ## passed ##\n");
}
void testbfs() {
   int v1, v2, v, i = 0;

   Graph g = NULL;
   printf("------------------------------------------------------\n");
   printf(">>>>> Test void bfs(Graph) <<<<<\n");
   printf("------------------------------------------------------\n");

   // copy empty graph
   printf("\n## Test %d: empty graph\n",++i);
   bfSearch(g);
   printf("\nExpected output:\nThe graph g can't be NULL\n");
   printf("\n ## passed ##\n");
   v = 3;
   g = newGraph(v);
   for (v1 = 0; v1 < v/2; v1++) {
      for(v2 = v1 + 1; v2 < v; v2++) {
         insertE(g,mkEdge(g, v1, v2));
      }
   }

   // 3 vertices graph
   printf("\n## Test %d: %d vertices graph\n",++i, v);
   showGraph(g);
   bfSearch(g);
   destroyGraph(g);
   printf("\n ## passed ##\n");

   v = 6;
   g = newGraph(v);
   for (v1 = 0; v1 < v/2; v1++) {
      for(v2 = v-1; v2 > v1 + 2; v2--) {
         insertE(g,mkEdge(g, v1, v2));
      }
   }
   showGraph(g);
   bfSearch(g);
   destroyGraph(g);
   printf("\n ## passed ##\n");
}

void testfindshortest() {
   int i = 0;
   int v1, v2, v;
   Graph g = NULL;

   printf("------------------------------------------------------\n");
   printf(">>>>> Test void findShortestPath(Graph) <<<<<\n");
   printf("------------------------------------------------------\n");
   v = 3;
   g = newGraph(v);
   for (v1 = 0; v1 < v/2; v1++) {
      for(v2 = v1 + 1; v2 < v; v2++) {
         insertE(g,mkEdge(g, v1, v2));
      }
   }

   // 3 vertices graph
   printf("\n## Test %d: %d vertices graph\n",++i, v);
   showGraph(g);

   printf("\n## Find path in a NULL graph\n");
   v1 = 0;
   v2 = 2;
   findShortestPath(NULL, v1, v2);
   printf("\nExpected output:\nThe graph g can't be NULL\n");
   printf("\n ## passed ##\n");

   v1 = 1;
   v2 = 0;
   printf("\n## Find path from %d to %d\n", v1, v2);
   findShortestPath(g, v1, v2);
   printf("\nExpected output:\n0<-1\n");
   printf("\n ## passed ##\n");

   v1 = 0;
   v2 = 2;
   printf("\n## Find path from %d to %d\n", v1, v2);
   findShortestPath(g, v1, v2);
   printf("\nExpected output:\n2<-0\n");
   printf("\n ## passed ##\n");

   destroyGraph(g);

   v = 6;
   g = newGraph(v);
   for (v1 = 0; v1 < v/2; v1++) {
      for(v2 = v-1; v2 > v1 + 2; v2--) {
         insertE(g,mkEdge(g, v1, v2));
      }
   }

   // 6 vertices graph
   printf("\n## Test %d: %d graph\n",++i, v);
   showGraph(g);

   v1 = 5;
   v2 = 3;
   printf("\n## Find path from %d to %d\n", v1, v2);
   findShortestPath(g, v1, v2);
   printf("\nExpected output:\n3<-0<-5\n");
   printf("\n ## passed ##\n");
   destroyGraph(g);
}
