#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x02157368; symbol: func_ov006_02157368; size: 0x60.
extern "C" char* Resource_FindIndexedRecordByHalfword(void* list, int value) {
    short* records = *(short**)((char*)list + 8);
    if (records == 0) return 0;
    unsigned short count = *(unsigned short*)((char*)list + 0x14);
    if (count == 0) return 0;
    for (unsigned short i = 0; i < count; ++i) {
        char* record = (char*)records + (unsigned)i * 0x18;
        if (*(short*)record == value) return record;
    }
    return 0;
}
