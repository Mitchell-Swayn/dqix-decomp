#include <globaldefs.h>
extern "C" int Script_FindOrderedLookupIndex(int, int, int, int);
extern "C" void BitArray_SetIndexedBoolean(int, int, int, int);
// Original: arm9/main @ 0x0206E348; symbol: func_0206e348; size: 0x3C.
extern "C" void Script_SetMappedUpperEntryFlag(int object, int value, int arg3, int arg4) {
    int index=Script_FindOrderedLookupIndex(object, (short)value, arg3, arg4);
    int threshold = index - 0x11;
    if(threshold < 0) return;
    BitArray_SetIndexedBoolean(object, object + 0x8C, index + 0xBF1, arg3);
}
