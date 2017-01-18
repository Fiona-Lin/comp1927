//Graph.h definitions
// vertices denoted by integers 0..N-1

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "GRAPH.h"


typedef struct graphRep * Graph;
typedef int Vertex;
typedef struct edge Edge;

// edges are pairs of vertices (end-points)
struct edge {
  Vertex v;
  Vertex w;
} ;


