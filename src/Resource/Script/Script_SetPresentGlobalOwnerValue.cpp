#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);extern "C" void AppendClearedThirtyTwoByteRecordWithinSixEntryLimit(void*,int);extern "C" unsigned char* data_02109bb0;
// Original: arm9/main @ 0x0209BB1C; symbol: func_0209bb1c; size: 0x50.
extern "C" int Script_SetPresentGlobalOwnerValue(const void* parameter){if(!*(void**)(data_02109bb0+20))return 1;int value=_ZNK6Script9Parameter5ToIntEv(parameter);AppendClearedThirtyTwoByteRecordWithinSixEntryLimit(*(void**)data_02109bb0,value);*(int*)(data_02109bb0+24)=value;return 1;}
