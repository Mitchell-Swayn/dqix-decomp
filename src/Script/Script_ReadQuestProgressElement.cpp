#include <globaldefs.h>

extern "C" int Quest_GetGlobalOrderState();
extern "C" int Script_ReadParameterAsInteger(int);
extern "C" int Quest_FindActiveEntryById(int, int);
extern "C" void Script_WriteIntegerReferenceOutput(int, unsigned short);

// Original: arm9/main @ 0x0209D334; symbol: func_0209d334; size: 0x58.
extern "C" int Script_ReadQuestProgressElement(unsigned char* self) {
    int table = Quest_GetGlobalOrderState();
    if (table == 0) {
        return 0;
    }
    int index = Script_ReadParameterAsInteger((int)self);
    int entry = Quest_FindActiveEntryById(table, index);
    if (entry == 0) {
        return 0;
    }
    int offset = Script_ReadParameterAsInteger((int)(self + 8));
    unsigned short value = *(unsigned short*)(entry + offset * 2 + 10);
    Script_WriteIntegerReferenceOutput((int)(self + 0x10), value);
    return 1;
}
