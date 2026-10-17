#include <globaldefs.h>
extern "C" void func_0205c96c(void*,unsigned);
// Original: arm9/main @ 0x02044530; symbol: func_02044530; size: 0x2C.
extern "C" ARM void Object_UpdateEnabledOffset90RecordInStateSix(unsigned char* p,unsigned value){if(*(int*)(p+0x9a0)!=6)return;if(!p[0x19ba])return;func_0205c96c(p+0x90,value);}
