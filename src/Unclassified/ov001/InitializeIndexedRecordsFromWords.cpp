#include <globaldefs.h>
ARM
extern "C" unsigned data_ov001_021658b8[];
extern "C" unsigned OV017_ReadWordField04(void*);
extern "C" void func_ov001_0215ec94(unsigned, unsigned);
// Original: arm9/ov001 @ 0x0215ED2C; symbol: func_ov001_0215ed2c; size: 0x48.
extern "C" int InitializeIndexedRecordsFromWords(void* records, int count) {
    int index = 0;
    data_ov001_021658b8[0x22] = 0;
    for (; index < count; ++index) {
        unsigned value = OV017_ReadWordField04(records);
        records = (char*)records + 8;
        func_ov001_0215ec94(value, (unsigned)index);
    }
    return 1;
}
