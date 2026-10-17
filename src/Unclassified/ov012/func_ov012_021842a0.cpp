#include <globaldefs.h>
extern "C" void* FindReadyRecordByIdBeforeStopIndex(void*), *GetCurrentRecordUnlessIdentifierAlreadyExists(void*, int);
extern "C" void WriteFieldD8Bit0AndResetProgress(void*, int),SetMaskedFlagsAtOffsetD9(void*, unsigned char),Object_SetElement218AndSetElement216To2(void*, unsigned char);
// Configure an existing or newly obtained screen element. Zero height disables it.
// Original: arm9/ov012 @ 0x021842A0; symbol: func_ov012_021842a0; size: 0x8C.
extern "C" void func_ov012_021842a0(unsigned char* screen, int id, int width, int height) {
    void* element = FindReadyRecordByIdBeforeStopIndex(screen + 0xac);
    if (!element) {
        element = GetCurrentRecordUnlessIdentifierAlreadyExists(screen + 0xac, id);
        if (!element) return;
    }
    if (height) {
        WriteFieldD8Bit0AndResetProgress(element, 1);
        SetMaskedFlagsAtOffsetD9(element, (unsigned char)width);
        Object_SetElement218AndSetElement216To2(element, (unsigned char)height);
    } else {
        WriteFieldD8Bit0AndResetProgress(element, 0);
        SetMaskedFlagsAtOffsetD9(element, 0);
        Object_SetElement218AndSetElement216To2(element, 0);
    }
}
