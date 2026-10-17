#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" unsigned FindReadyRecordByIdBeforeStopIndex(char*,unsigned char);
// Original: arm9/main @ 0x0205D8C4; symbol: func_0205d8c4; size: 0x40.
extern "C" unsigned Object_GetSelectedRecordWhenBuffersEnabled(char* p){
    if(!*(unsigned*)(p+0x98))return 0;
    if(!*(unsigned*)(p+0x9c))return 0;
    if(!*(unsigned char*)(p+0xb4))return 0;
    return FindReadyRecordByIdBeforeStopIndex(p,*(unsigned char*)(p+0xb0));
}
