struct Pair{int a,b;};struct S{unsigned char pad,capacity,pad2,count;int unused;Pair* records;};
// Original: arm9/main @ 0x020281D8; symbol: func_020281d8; size: 0x3C.
extern "C" void ActorPathGraph_AppendEdge(S* p,Pair* values){unsigned int i=p->count;if(p->capacity<=i)return;Pair* dest=p->records+i;dest->a=values->a;dest->b=values->b;++p->count;}
