#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Stack.h"
#include "Queue.h"

// local checking function
static int validV(Graph g, Vertex v);

typedef struct VList *VList;
struct VList {
   Vertex v;
   VList next;
};

struct GraphRep {
   int nV; // #vertices
   int nE; // #edges VList
   VList *edges; // array of lists
};

int numV(Graph g) {
   assert(g != NULL);
   return g->nV;
}

int numE(Graph g) {
   assert(g != NULL);
   return g->nE;
}

static VList NEW (Vertex v, VList head) {
   VList x = malloc (sizeof *x);
   if (x != NULL) {
      x->v = v;
      x->next = NULL;
      if (head == NULL) {
         head = x;
      } else {
         VList cur = head;
         VList pre = NULL;
         while (cur != NULL && cur -> v < v) {
            printf("cur -> %d < %d", cur->v, v);
            pre = cur;
            cur = cur -> next;
         }
         if (pre == NULL) {
            x -> next = head;
            head = x;
         } else if (pre != NULL && cur == NULL) {
            pre -> next = x;
         } else {
            x -> next = cur;
            pre -> next = x;
         }
      }
   } else {
      printf("System hasn't enough memory.\n");
   }
   return head;
}
// Does not allow self-loops
Edge mkEdge(Graph g, Vertex v, Vertex w) {
   //assert(v != w);
   assert(validV(g,v) && validV(g,w));
   Edge e = {v,w};
   return e;
}

// local checking function
static int validV(Graph g, Vertex v) {
   return (v >= 0 && v < g->nV);
}


//O(V) - Hmmmm O(E) since we allow multiple edges
int isAdjacent(Graph g,Vertex v, Vertex w) {
   assert(g!= NULL && validV(g,v) && validV(g,w));
   VList curr = g->edges[v];
   while(curr != NULL) {
      if(curr->v == w) return 1;
      curr= curr->next;
   }
   return 0;
}

//O(V)
int adjacentVertices(Graph g, Vertex v, Vertex adj[]) {
   int counter = 0;
   assert(g!=NULL && validV(g,v));
   VList tmp = g->edges[v];
   while(tmp != NULL) {
      adj[counter] = tmp->v;
      counter++;
      tmp = tmp->next;
   }
   return counter;
}
//
////Inserts a vertex at the beginning of the list
////returns the new beginning ofthe list
//static VList insertVList(Vertex v,VList list) {
//   VList newNode = malloc(sizeof(struct VList));
//   newNode->v = v;
//   newNode->next = list;
//   return newNode;
//}
//
//e.v e.w //2,1
void insertE(Graph g, Edge e) {
   assert(g != NULL && e.v < g->nV && e.w < g->nV);
   g->edges[e.v] = NEW(e.w,g->edges[e.v]);
   g->edges[e.w] = NEW(e.v,g->edges[e.w]);
   g->nE++;
}

Graph newGraph(int nV) {
   int i;
   Graph g = malloc(sizeof(struct GraphRep));
   assert(g != NULL);
   g->edges = malloc(nV* sizeof(VList));
   assert(g->edges != NULL);
   for(i=0; i<nV; i++) {
      g->edges[i] = NULL;
   }
   g->nV = nV;
   g->nE = 0;
   return g;
}


void showGraph(Graph g) {
   assert(g != NULL);
   printf("V=%d, E=%d\n", g->nV, g->nE);
   int i;
   for (i = 0; i < g->nV; i++) {
      VList n = g->edges[i];
      while (n != NULL) {
         printf("%d-%d ",i,n->v);
         n = n->next;
      }
      if (g->edges[i] != NULL)
         printf("\n");
   }
}

Graph copyGraph(Graph g) {
   Graph cpy = NULL;
   if (g != NULL) {
      int v;
      VList s;
      // create copy Graph
      cpy = newGraph(g -> nV);
      assert(cpy != NULL);
      // set copy Graph edge number
      cpy -> nE = g -> nE;
      // loop the adjacent list array
      for (v = 0; v < g -> nV; v++) {
         // traversal g -> edges[v]
         for (s = g -> edges[v]; s != NULL; s = s -> next) {
            // prepend the adj vertex to the list
            cpy -> edges[v] = NEW(s -> v, cpy -> edges[v]);
         }
      }
   } else {
      printf("The graph g can't be NULL\n");
   }
   return cpy;
}

void destroyGraph(Graph g) {
   int i;
   if(g != NULL) {
      int nV = g -> nV;
      VList t, f;
      for (i = 0; i < nV; i++) {
         t = g -> edges[i];
         while (t != NULL) {
            f = t;
            t = t -> next;
            free(f);
         }
      }
      free(g -> edges);
   }
   free(g);
}

//O(V) - O(E) since we allow multiple edges
int degree(Graph g, Vertex v) {
   int d = -1;
   if (g == NULL) {
      printf("The graph g can't be NULL\n");
   }
   if (!validV(g, v)) {
      printf("Invalid vertev %d, must less than %d\n", v, g -> nV);
   }
   if (g!= NULL && validV(g,v)) {
      VList cur = g -> edges[v];
      while(cur != NULL) {
         d++;
         cur = cur -> next;
      }
   }
   return d;
}

int * pre = NULL; //order and visited
Vertex *st = NULL; //parent - path
int count=0;
static void printSearch(int count) {
   int i;
   printf("\ni\t");
   for (i = 0; i < count; i++)
      printf("%d\t", i);
   printf("\nst[i]\t");
   for (i = 0; i < count; i++)
      printf("%d\t", st[i]);
   printf("\npre[i]\t");
   for (i = 0; i < count; i++)
      printf("%d\t", pre[i]);
   printf("\n");

}

static VList getNth(VList head, int index) {
   int i = 0;
   VList res = head;
   while (head != NULL && i < index) {
      res = res -> next;
      i++;
   }
   return res;
}


// dfSearch using Stack
//The initialisation of variables etc before we call the dfs function
void dfSearchIterative(Graph g) {
   int i, count = 0;
   Edge e = {};
   VList t = NULL;
   if (g == NULL) {
      printf("The graph g can't be NULL\n");
      return;
   }
   //make a pre and st(paret) arrary;
   pre = calloc(sizeof(int), g -> nE);
   st = calloc(sizeof(int), g -> nE);
   //init both arrays value -1
   for (i = 0; i < g -> nV; i ++) {
      pre[i] = -1;
      st[i] = -1;
   }
   //make a stack and push the 1st edge
   st[e.v] = count;
   Stack stk = newStack();
   StackPush(stk, mkEdge(g, 0, 0));
   while (!StackIsEmpty(stk)) {
      e = StackPop(stk);
      printf("pop %d %d",e.v, e.w);
      for (i = degree(g, e.w); i >= 0; i--) {
         t = getNth(g -> edges[e.w], i);
         if (pre[t -> v] != -1) continue;
            StackPush(stk, mkEdge(g, e.w, t -> v));
            printf("push %d %d",e.w, t->v);
      }
      if (pre[e.w] != -1) continue;
      st[e.w] = e.v;
      pre[e.w] = count++;
   }
   printSearch(count);
   free(pre);
   free(st);
}

// dfSearch using Queue
void bfSearch(Graph g) {
   int i, count = 0;
   Edge e = {};
   VList t = NULL;
   if (g == NULL) {
      printf("The graph g can't be NULL\n");
      return;
   }
   //make a pre and st(paret) arrary;
   pre = calloc(sizeof(int), g -> nV);
   st = calloc(sizeof(int), g -> nV);
   //init both arrays value -1
   for (i = 0; i < g -> nV; i ++) {
      pre[i] = -1;
      st[i] = -1;
   }

   //make a stack and push the 1st edge
   e = mkEdge(g, 0, 0);
   st[e.v] = e.w;
   Queue q = newQueue();
   QueueJoin(q, e);
   pre[e.w] = count++;
   st[e.w] = e.v;
   while (!QueueIsEmpty(q)) {
      e = QueueLeave(q);
      for (t = g -> edges[e.w]; t != NULL; t = t -> next) {
         if (pre[t -> v] != -1) continue;
         QueueJoin(q, mkEdge(g, e.w, t -> v));
         st[t -> v] = e.w;
         pre[t -> v] = count++;
      }
   }
   printSearch(count);
   free(pre);
   free(st);
}

void findShortestPath(Graph g, Vertex src,Vertex dest) {
   int i, count = 0, isFound = 0;
   Edge e = {};
   VList t = NULL;
   if (g == NULL) {
      printf("The graph g can't be NULL\n");
      return;
   }
   //make a pre and st(paret) arrary;
   pre = calloc(sizeof(int), g -> nV);
   st = calloc(sizeof(int), g -> nV);
   //init both arrays value -1
   for (i = 0; i < g -> nV; i ++) {
      pre[i] = -1;
      st[i] = -1;
   }

   //make a stack and push the 1st edge
   e = mkEdge(g, src, src);
   st[e.v] = e.w;
   Queue q = newQueue();
   QueueJoin(q, e);
   pre[e.w] = count++;
   while (!QueueIsEmpty(q) && !isFound) {
      e = QueueLeave(q);
      for (t = g -> edges[e.w]; t != NULL; t = t -> next) {
         st[t -> v] = e.w;
         
         if (pre[t -> v] != -1) continue;
         QueueJoin(q, mkEdge(g, e.w, t -> v));
         pre[t -> v] = count++;
      }
   }
   printSearch(count);
   free(pre);
   free(st);
}


