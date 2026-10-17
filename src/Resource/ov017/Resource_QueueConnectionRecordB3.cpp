#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalConnectionState();
extern "C" bool TestInactiveOrPrimaryIndexState(unsigned*);
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D1C2C; symbol: func_ov017_021d1c2c; size: 0x58.
extern "C" void Resource_QueueConnectionRecordB3(unsigned char first, unsigned char second) {
    if (!TestInactiveOrPrimaryIndexState((unsigned*)Object_GetGlobalConnectionState())) return;
    char* state = (char*)ReadGlobalValueAt020FB3F0() + 0x2700;
    *(unsigned short*)(state + 0xb4) = first;
    *(unsigned short*)(state + 0xb6) = second;
    unsigned char record[0x14];
    void* object = ReadGlobalAt02100044();
    record[0] = 0xb3;
    record[4] = first;
    record[5] = second;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
