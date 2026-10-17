#include <globaldefs.h>
ARM
extern "C" int TestIndexedObjectPackedMode(void* object, int index, int value, int mode);
// Original: arm9/ov024 @ 0x021D8C90; symbol: func_ov024_021d8c90; size: 0x44.
extern "C" int Resource_ConvertValueForPackedMode(void** object, int arg1, int index, int arg3, int arg4, int value) {
    if (!TestIndexedObjectPackedMode(*object, (short)index, 1, 0))
        return value;
    return (int)((float)value * 1.5f);
}
