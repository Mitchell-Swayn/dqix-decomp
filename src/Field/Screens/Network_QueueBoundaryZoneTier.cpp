#include <globaldefs.h>
ARM
extern "C" void *Network_GetConnectionManager(void);
extern "C" bool Network_IsClientSession(unsigned int *p);
extern "C" void *Network_GetCommandRecordPool(void);
struct Object;
extern "C" void Network_QueueOutgoingRecord(Object *, const void *, short);
// Original: arm9/ov017 @ 0x021D3E3C; symbol: func_ov017_021d3e3c; size: 0x40.
extern "C" void Network_QueueBoundaryZoneTier(unsigned char value) {
    unsigned int *state = (unsigned int *)Network_GetConnectionManager();
    if (Network_IsClientSession(state)) return;
    Object *object = (Object *)Network_GetCommandRecordPool();
    unsigned char record[0x14];
    record[0] = 0xba;
    record[4] = value;
    Network_QueueOutgoingRecord(object, record, 0);
}
