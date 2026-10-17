#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView* parameter);
extern "C" void* Util_FindEmptySlotInTable16(unsigned* index);
extern "C" void DispatchNonnegativeStoredIndexWithTwoArguments(void* p, int a, int b);
extern "C" void SetNestedSecondWordForTypeThree(void* output, int value);
extern "C" char data_02108760[];
// Original: arm9/ov001 @ 0x02163860; symbol: func_ov001_02163860; size: 0x6C.
extern "C" int Resource_DispatchScriptIndex(IntegerParameterView* parameter, int mode) {
    int value = ReadScriptParameterAsInteger(parameter);
    if (mode >= 2) {
        unsigned index;
        void* slot = Util_FindEmptySlotInTable16(&index);
        if (slot != 0)
            DispatchNonnegativeStoredIndexWithTwoArguments(data_02108760, value, (int)slot);
        SetNestedSecondWordForTypeThree((char*)parameter + 8, index);
    } else {
        DispatchNonnegativeStoredIndexWithTwoArguments(data_02108760, value, 0);
    }
    return 1;
}
