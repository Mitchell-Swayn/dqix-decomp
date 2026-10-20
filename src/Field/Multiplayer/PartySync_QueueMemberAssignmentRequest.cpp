#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CC340; symbol: func_ov017_021cc340; size: 0x48.
extern "C" void PartySync_QueueMemberAssignmentRequest(unsigned char a, unsigned char b, unsigned char c) {
    void *object = Network_GetCommandRecordPool();
    unsigned char record[20];
    record[0] = 7;
    record[6] = a;
    record[9] = b;
    record[5] = 1;
    record[4] = c;
    Network_QueueOutgoingRecord(object, record, 0);
}
