#include <globaldefs.h>
ARM
extern "C" void* FindReadyRecordByIdBeforeStopIndex(void*,int);extern "C" void Object_SetBooleanMask20AtOffsetC5(void*,int);
// Original: arm9/main @ 0x0205DEF8; symbol: func_0205def8; size: 0x40.
extern "C" void Object_SetSelectedRecordInverseEnabledFlag(unsigned char* p,int enabled,int key){if(!*(void**)(p+152)||!*(void**)(p+156))return;void* item=FindReadyRecordByIdBeforeStopIndex(p,key);if(!item)return;Object_SetBooleanMask20AtOffsetC5(item,enabled==0);}
