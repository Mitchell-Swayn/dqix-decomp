#include <globaldefs.h>
ARM
// Tried ten variants including direct byte offsets, a field pointer, volatile stores, a local struct, register qualifier, signed argument types and optimization level 4. Record is kind 0x8C with a halfword at +4 and byte at +6; submits to MoveQueuedRecordAndApplySourceValue. Near match differs only in scratch register selection and order of record stores.
// Original: arm9/ov017 @ 0x021D0AA8; symbol: QueueType8CRecordWithHalfwordAndByte; size: 0x3c.
extern "C" void* Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
extern "C" void FieldNetwork_QueueSlotFlagUpdate(short value, unsigned char flag) {
    void* object = Network_GetCommandRecordPool();
    unsigned char record[20];
    unsigned char* fields = record + 4;
    record[0] = 0x8C;
    *(short*)fields = value;
    fields[2] = flag;
    Network_QueueOutgoingRecord(object, record, 0);
}
