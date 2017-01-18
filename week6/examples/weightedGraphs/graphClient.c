#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"
#include <time.h>
#include <float.h>

Graph graphScan(){
    int v,w;
    int V;
    float weight;
    scanf("%d",&V);
    Graph g = newGraph(V);
    while(scanf("%d %d %f",&v,&w,&weight) == 3)
        insertE(g,mkEdge(v,w,weight));
    return g;
}

int main(int argc, char * argv[]){
       
    Graph g = graphScan();
    show(g);
    int * st = malloc(numV(g) * sizeof(int));
    double * dist = malloc(numV(g) * sizeof(double));
    
    dijkstra(g,1,st,dist);
    
    int i;
    printf("dist array\n");
    for(i=0;i<numV(g);i++){
      printf("%f ",dist[i]);
   
    }
    printf("\n");

    printf("st array\n");
    for(i=0;i<numV(g);i++){
      printf("%d ",st[i]);
    }

    printf("\n");

    for(i=0;i<numV(g);i++){
      printf("Cost from 0 to %d is %f\n",i,dist[i]);

      printf("Path is\n");
      int v = i;
      while(v != -1){
	    printf("%d <- ",v);
        v = st[v];
      }
      
      printf("0\n");
    }
    free(dist);
    free(st);

    return 0;
}
