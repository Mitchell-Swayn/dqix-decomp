#include <globaldefs.h>
ARM
extern "C" void *ReceiveGlobalQueueValueWithFlags(unsigned int);
// Original: arm9/ov031 @ 0x02205134; symbol: InitializeCallbackRecordForByteKey; size: 0x40.
// Obtains a record by byte key and stores the callback value, object pointer, signed object byte +0x73, and key.
extern "C" void Network_AllocateSocketCommand(unsigned int a, void *object, unsigned char value) {
    void *record = ReceiveGlobalQueueValueWithFlags(value);
    if (record == 0) return;
    *(unsigned int *)record = a;
    *(void **)((char *)record + 4) = object;
    *(unsigned int *)((char *)record + 8) = 0;
    *((unsigned char *)record + 0xc) = *(signed char *)((char *)object + 0x73);
    *((unsigned char *)record + 0xd) = value;
}
