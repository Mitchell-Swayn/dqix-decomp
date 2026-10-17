#include <globaldefs.h>
ARM
extern "C" void InitializeRecordKind4BAndDefaultByte(void*);extern "C" void AppendLinkedNodeAndMarkActive(void*,void*);
// Original: arm9/main @ 0x020DAC40; symbol: func_020dac40; size: 0x28.
extern "C" void Object_UpdateTwoAttachedResourcesAtOffsets36FCAnd3BC4(unsigned char* p){InitializeRecordKind4BAndDefaultByte(*(void**)(p+0x3bc4));AppendLinkedNodeAndMarkActive(*(void**)(p+0x36fc),*(void**)(p+0x3bc4));}
