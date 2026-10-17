#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void*, int, unsigned);
extern "C" unsigned long long func_ov031_02212d20(unsigned);
extern "C" void func_ov031_02211678(void*, unsigned, unsigned);
extern "C" void SetObjectFlagBitZero(unsigned*);
// Original: arm9/ov031 @ 0x022114FC; symbol: func_ov031_022114fc; size: 0x70.
extern "C" void Protocol_InitializeSWCARecord(void* record, unsigned value) {
    unsigned char* bytes = (unsigned char*)record;
    VectorizedMemset(record, 0, 0x40);
    *(unsigned*)record = 0x40;
    unsigned long long pair = func_ov031_02212d20(0x40);
    func_ov031_02211678(bytes + 4, (unsigned)pair, (unsigned)(pair >> 32));
    func_ov031_02211678(bytes + 0x10, 0, 0);
    *(unsigned*)(bytes + 0x1c) = 0;
    *(unsigned*)(bytes + 0x24) = value;
    *(unsigned*)(bytes + 0x28) = 0x41435753;
    *(unsigned*)(bytes + 0x2c) = 0x10000;
    SetObjectFlagBitZero((unsigned*)record);
}
