#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D1C2C; symbol: func_ov017_021d1c2c; size: 0x58.
extern "C" void Network_QueueZoneTransitionParameters(unsigned char first, unsigned char second) {
    if (!Network_IsParentOrOffline((unsigned*)Network_GetConnectionManager())) return;
    char* state = (char*)Zone3D_GetMainInstance() + 0x2700;
    *(unsigned short*)(state + 0xb4) = first;
    *(unsigned short*)(state + 0xb6) = second;
    unsigned char record[0x14];
    void* object = Network_GetCommandRecordPool();
    record[0] = 0xb3;
    record[4] = first;
    record[5] = second;
    Network_QueueOutgoingRecord(object, record, 0);
}
