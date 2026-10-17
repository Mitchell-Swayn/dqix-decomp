#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct A{unsigned int w[5];unsigned short a,b;short c;unsigned short d,e;};
// Original: arm9/main @ 0x020836E4; symbol: func_020836e4; size: 0x54.
void Copy10RecordFields(A *p,A *q){p->w[0]=q->w[0];p->w[1]=q->w[1];p->w[2]=q->w[2];p->w[3]=q->w[3];p->w[4]=q->w[4];p->a=q->a;p->b=q->b;p->c=q->c;p->d=q->d;p->e=q->e;}
}
