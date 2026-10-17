#include <globaldefs.h>

extern "C" int Object_GetGlobalRequestQueue();
extern "C" int ReadScriptParameterAsInteger(int);
extern "C" int Object_FindBoundedIdEntryThrough204(int, int);
extern "C" void SetNestedSecondWordForTypeThree(int, unsigned short);

// Original: arm9/main @ 0x0209D334; symbol: func_0209d334; size: 0x58.
extern "C" int CopyIndexedTableHalfwordIntoOutputContext(unsigned char* self) {
    int table = Object_GetGlobalRequestQueue();
    if (table == 0) {
        return 0;
    }
    int index = ReadScriptParameterAsInteger((int)self);
    int entry = Object_FindBoundedIdEntryThrough204(table, index);
    if (entry == 0) {
        return 0;
    }
    int offset = ReadScriptParameterAsInteger((int)(self + 8));
    unsigned short value = *(unsigned short*)(entry + offset * 2 + 10);
    SetNestedSecondWordForTypeThree((int)(self + 0x10), value);
    return 1;
}
