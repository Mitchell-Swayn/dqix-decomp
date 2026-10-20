#include <globaldefs.h>
extern "C" {
struct A{char pad[28];unsigned char lo:4;unsigned char hi:4;};
// Original: arm9/main @ 0x0205D594; symbol: func_0205d594; size: 0x24.
void Window_ReadResourceFormatAndLayer(A *p,unsigned char *a,unsigned char *b){*a=p->lo;*b=p->hi;}
}
