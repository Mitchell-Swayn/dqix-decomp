#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
struct Vertex{unsigned char id,pad,count,unknown;unsigned a,b;Vertex**links;};struct Edge{Vertex*a,*b;};struct Graph{unsigned short unknown;unsigned char vertices,edges;Vertex*nodes;Edge*pairs;char pad[16];unsigned ready;};
// Original: arm9/main @ 0x02028214; symbol: func_02028214; size: 0x138.
extern "C" ARM void AllocateGraphAdjacencyListsFromEdges(Graph*g,SafeAllocator*allocator){for(int i=0;i<g->vertices;i++){Vertex*v=g->nodes+i;v->count=0;for(int j=0;j<g->edges;j++){Edge*e=g->pairs+j;if(e->a->id==v->id || e->b->id==v->id)v->count++;}}for(int i=0;i<g->vertices;i++){Vertex*v=g->nodes+i;v->links=(Vertex**)allocator->Allocate(v->count*4);unsigned n=0;if(!v->links)v->count=n;else {int j;for(j=n;j<g->edges;j++){Edge*e=g->pairs+j;unsigned char id=v->id;Vertex*a=e->a;if(a->id==id){v->links[n]=e->b;n++;}else if(e->b->id==id){v->links[n]=a;n++;}if(n==v->count)break;}v->count=(unsigned char)n;}}g->ready=1;}
