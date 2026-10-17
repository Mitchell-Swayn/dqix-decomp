#include <globaldefs.h>
#include "Resource/Script.h"

extern "C" unsigned char data_02109be0[];
extern "C" void AllocatePositiveWordArrayAndStoreByteCount(void* result, int value);

// Original: arm9/main @ 0x0209CB74; symbol: func_0209cb74; size: 0x20.
extern "C" int Script_AllocateGlobalListByIntegerParameter(Script::Parameter* parameter)
{
    int value = parameter->ToInt();
    AllocatePositiveWordArrayAndStoreByteCount(data_02109be0, value);
    return 1;
}
