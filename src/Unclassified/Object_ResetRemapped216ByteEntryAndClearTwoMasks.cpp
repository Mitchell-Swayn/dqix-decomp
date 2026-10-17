#pragma opt_common_subs off
#include <globaldefs.h>
extern "C" void Object_ClearD4ByteDisplayEntryAndSetDefaults(void*);
// Original: arm9/main @ 0x020D7334; symbol: func_020d7334; size: 0x58.
extern "C" ARM void Object_ResetRemapped216ByteEntryAndClearTwoMasks(char* state,int index) { if(index>=192) index-=188; int offset=index*216; Object_ClearD4ByteDisplayEntryAndSetDefaults(state+offset); *(unsigned*)(state+offset+212)=0; unsigned mask=~(1u<<index); *(unsigned short*)(state+0xa24)&=mask; *(unsigned short*)(state+0xa26)&=mask; }
