#include <globaldefs.h>
extern "C" char* FindFourSlotRecordByIndex(char*, int);
// Original: arm9/ov000 @ 0x02174FC0; symbol: func_ov000_02174fc0; size: 0x64.
extern "C" void Object_UpdateFourRecordType65Offsets(char* self) {
    for (int i = 0; i < 4; ++i) {
        char* record = FindFourSlotRecordByIndex(self, *(signed char*)(self + 0x6c + i));
        if (record != 0) {
            signed char offset = *(signed char*)(record + 0x18);
            int value = 0;
            int saved = *(volatile int*)(record + 0x48);
            if (*(signed char*)(record + offset + 0x10) == 0x65) value = -8;
            *(int*)(record + 0x44) = value;
            *(volatile int*)(record + 0x48) = saved;
        }
    }
}
