#include <globaldefs.h>
ARM
extern "C" void* data_ov001_02165880;
extern "C" int ReadScriptParameterAsInteger(void*);
extern "C" void* Object_GetGlobalThirtyTwoEntryContainer(void);
extern "C" unsigned* GetBoundedSlotUnlessFlag8000(unsigned**, unsigned);
// Original: arm9/ov001 @ 0x0215D0F4; symbol: func_ov001_0215d0f4; size: 0x40.
extern "C" int ClearSelectedBoundedSlotField(void* parameter) {
    int index = ReadScriptParameterAsInteger(parameter);
    unsigned** container = (unsigned**)Object_GetGlobalThirtyTwoEntryContainer();
    unsigned* entries = *(unsigned**)((char*)&data_ov001_02165880 + 4);
    unsigned key = *(unsigned*)((char*)entries + index * 16 + 4);
    unsigned* slot = GetBoundedSlotUnlessFlag8000(container, key);
    if (!slot)
        return 0;
    slot[4] = 0;
    return 1;
}
