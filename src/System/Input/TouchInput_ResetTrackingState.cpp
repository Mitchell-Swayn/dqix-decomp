#include <globaldefs.h>
ARM
extern "C" void ClearFourByteFieldsAtOffset50(void*);
struct State { unsigned char pad[0x30]; int a,b; unsigned char pad38[8]; int c,d,e; unsigned char pad4c[10]; unsigned char f; unsigned char pad57; int g; unsigned char pad5c; unsigned char h; unsigned char pad5e; unsigned char i; };
// Original: arm9/main @ 0x0201289C; symbol: func_0201289c; size: 0x3C.
extern "C" void TouchInput_ResetTrackingState(State* p){p->a=p->b=-1;ClearFourByteFieldsAtOffset50(p);p->e=0;p->c=0;p->d=0;p->f=0;p->g=0;p->h=0;p->i=0;}
