#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0216F414; symbol: func_ov003_0216f414; size: 0x60.
extern "C" void* Resource_FindRecordBySignedId(char* self, int id) {
    char* records = *(char**)(self + 8);
    if (records == 0)
        return 0;
    unsigned short count = *(unsigned short*)(self + 0x14);
    if (count == 0)
        return 0;
    for (unsigned short i = 0; i < count; i++) {
        char* record = records + i * 0x18;
        if (*(short*)record == id)
            return record;
    }
    return 0;
}
