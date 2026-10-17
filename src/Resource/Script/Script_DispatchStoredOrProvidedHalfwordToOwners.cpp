#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" unsigned char data_02108db0[];extern "C" void Object_AllocateEightByteIdValueEntries(void*,void*,unsigned);
// Original: arm9/main @ 0x02072628; symbol: func_02072628; size: 0x54.
extern "C" int Script_DispatchStoredOrProvidedHalfwordToOwners(Script::Parameter* p){unsigned n=(unsigned short)p->ToInt();if(*(void**)(data_02108db0+4))return 1;if(*(void**)(data_02108db0+8)&&*(unsigned short*)(data_02108db0+2))n=*(unsigned short*)(data_02108db0+2);Object_AllocateEightByteIdValueEntries(*(void**)(data_02108db0+16),*(void**)(data_02108db0+12),n);return 1;}
