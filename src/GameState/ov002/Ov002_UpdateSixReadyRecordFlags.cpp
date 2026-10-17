#include <globaldefs.h>
extern "C" unsigned char data_ov002_0216c984[];
extern "C" void* FindReadyRecordByIdBeforeStopIndex(void*, unsigned);
extern "C" void func_ov002_0215b9a4(void*, unsigned, unsigned);
// Original: arm9/ov002 @ 0x0215B648; symbol: func_ov002_0215b648; size: 0x78.
extern "C" ARM void Ov002_UpdateSixReadyRecordFlags(void* owner) {
    unsigned char* p = (unsigned char*)owner;
    if (!p[0x1cc4]) return;
    for (int i = 0; i < 6; ++i) {
        unsigned char id = data_ov002_0216c984[i];
        void* record = FindReadyRecordByIdBeforeStopIndex(p + 0xec8, id);
        if (record) {
            unsigned flag = *(unsigned short*)((char*)record + 0xc2) != 0;
            func_ov002_0215b9a4(owner, id, flag);
        }
    }
}
