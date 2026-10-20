#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool(void);
extern "C" void Field_CopyPackedPartyRecoveryDescriptor(unsigned char*, const unsigned char*);
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D2CC0; symbol: func_ov017_021d2cc0; size: 0x40.
extern "C" void Network_QueuePartyRecoveryCommand(const unsigned char* source) {
    void* object = Network_GetCommandRecordPool();
    unsigned char record[0x14];
    record[0] = 0x25;
    Field_CopyPackedPartyRecoveryDescriptor(record + 4, source);
    Network_QueueOutgoingRecord(object, record, 0);
}
