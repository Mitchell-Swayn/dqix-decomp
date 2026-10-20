#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct E{unsigned char a,b,c,d;unsigned short e,f,g;unsigned int h;};struct A{unsigned char capacity,pad,count,pad2;E *data;};
// Original: arm9/main @ 0x02028170; symbol: func_02028170; size: 0x68.
void ActorPathGraph_AppendNode(A *p,E *q){unsigned int i=p->count;if(p->capacity<=i)return;E *n=p->data+i;n->a=q->a;n->b=q->b;n->c=q->c;n->d=q->d;n->e=q->e;n->f=q->f;n->g=q->g;n->h=q->h;p->count++;}
}
