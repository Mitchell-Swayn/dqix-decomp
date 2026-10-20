#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void *Zone3D_GetMainInstance(void);
struct Object;
extern "C" void Network_QueueOutgoingRecord(Object *, const void *, short);
// Original: arm9/ov017 @ 0x021D24A8; symbol: func_ov017_021d24a8; size: 0x48.
extern "C" void Network_QueuePartyDisplayRequestForCurrentZone(unsigned char value) {
    Object *object = (Object *)Network_GetCommandRecordPool();
    unsigned char record[0x14];
    unsigned char *payload = record + 4;
    record[0] = 0x1e;
    *payload = value;
    *(unsigned int *)(payload + 4) = *(unsigned short *)Zone3D_GetMainInstance();
    Network_QueueOutgoingRecord(object, record, 0);
}
