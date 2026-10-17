#include <globaldefs.h>

extern "C" int ReadWordAtOffset0(void);
extern "C" int ReadScriptParameterAsInteger(void*);
extern "C" int ReadScriptParameterAsFloat(void*);
extern "C" void Object_FilterSixtyFourByteRecordsByThreshold(int, int, int, int);

// Original: arm9/main @ 0x0209D554; symbol: func_0209d554; size: 0x54.
extern "C" int Script_InvokeStateWithMixedResolvedTriple(void* object, int, int, int arg3)
{
    int target = ReadWordAtOffset0();
    if (target == 0) return 0;
    int value0 = ReadScriptParameterAsInteger(object);
    int value1 = ReadScriptParameterAsFloat((char*)object + 8);
    int value2 = ReadScriptParameterAsInteger((char*)object + 16);
    Object_FilterSixtyFourByteRecordsByThreshold(target, value0, value1, value2);
    return 1;
}
