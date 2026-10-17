#include <globaldefs.h>
extern "C" void func_0205b734(void*,int,int,int,int,int);struct Owner{int unused;void** object;};
// Original: arm9/main @ 0x020E23C0; symbol: func_020e23c0; size: 0x34.
extern "C" ARM void Object_DrawSecondTextObjectWithCoordinates(Owner* p,int b,int c,int d,short x,short y){func_0205b734(p->object[1],c,d,x,y,b);}
