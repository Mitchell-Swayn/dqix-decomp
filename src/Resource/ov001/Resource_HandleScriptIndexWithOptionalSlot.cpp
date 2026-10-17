#include <globaldefs.h>
ARM

struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" void *Util_FindEmptySlotInTable16(unsigned int *index);
extern "C" void DispatchNonnegativeStoredIndexWithTwoArguments(void *p, int a, int b);
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char *p, int a, void *b);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
extern "C" unsigned char data_02108760[];

// Original: arm9/ov001 @ 0x02163564; symbol: func_ov001_02163564; size: 0x6C.
extern "C" int Resource_HandleScriptIndexWithOptionalSlot(IntegerParameterView *parameter, int mode) {
    int value = ReadScriptParameterAsInteger(parameter);
    if (mode >= 2) {
        unsigned int index;
        void *slot = Util_FindEmptySlotInTable16(&index);
        if (slot != 0) DispatchNonnegativeStoredIndexWithTwoArguments(data_02108760, value, (int)slot);
        SetNestedSecondWordForTypeThree((char *)parameter + 8, index);
    } else {
        DispatchStoredHalfwordIndexWithTwoArguments((char *)data_02108760, value, 0);
    }
    return 1;
}
