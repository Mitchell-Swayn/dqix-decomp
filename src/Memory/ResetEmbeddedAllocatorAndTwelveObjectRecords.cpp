#include <globaldefs.h>
ARM
#pragma opt_common_subs off

#include <Memory/SafeAllocator.h>
extern "C" void Object_ClearD4ByteDisplayEntryAndSetDefaults(void*);
// Original: arm9/main @ 0x020D6F44; symbol: func_020d6f44; size: 0x58.
extern "C" void ResetEmbeddedAllocatorAndTwelveObjectRecords(unsigned char* object){((SafeAllocator*)(object+0xa28))->Reset();for(int i=0;i<12;i++){int offset=i*0xd8;Object_ClearD4ByteDisplayEntryAndSetDefaults(object+offset);*(unsigned*)(object+offset+0xd4)=0;}*(unsigned short*)(object+0xa24)=0;*(unsigned short*)(object+0xa26)=0;}
