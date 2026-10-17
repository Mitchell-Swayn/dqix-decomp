#include <globaldefs.h>
extern "C" {
struct A{unsigned short a;unsigned char b,c;};
// Original: arm9/main @ 0x020643E0; symbol: func_020643e0; size: 0x1C.
void CopyThreeScalarFields(A *p,A *q){p->a=q->a;p->b=q->b;p->c=q->c;}
}
