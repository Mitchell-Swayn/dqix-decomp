#include <globaldefs.h>
struct Flags { unsigned char low:2; unsigned char rest:6; }; struct Object { unsigned char pad[0xc1]; Flags flags; unsigned char pad2[0x190]; unsigned char a,b; }; extern "C" int ReadByteFieldAtOffset26C(void *); extern "C" void ShiftCurrentByteValueToPreviousAndRefresh(void *,int);
// Original: arm9/main @ 0x020397CC; symbol: func_020397cc; size: 0x54.
 extern "C" void Object_ClearTwoStateFieldsAndOptionallyResetAnimation(Object *p,int reset) { if(reset && p->a && !ReadByteFieldAtOffset26C(p) && !(p->flags.low&2)) ShiftCurrentByteValueToPreviousAndRefresh(p,0); p->b=0;p->a=0; }
