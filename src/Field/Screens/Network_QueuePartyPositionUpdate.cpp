#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021D2AD0; symbol: func_ov017_021d2ad0; size: 0x54.
extern "C" void Network_QueuePartyPositionUpdate(unsigned char a, unsigned int b, unsigned int c, unsigned int d, unsigned char e) {
    void *object = Network_GetCommandRecordPool();
    unsigned char source[0x14];
    unsigned char *fields = source + 4;
    source[0] = 0x23;
    fields[0] = a;
    *(unsigned int *)(fields + 4) = b;
    *(unsigned int *)(fields + 8) = c;
    *(unsigned int *)(fields + 0xc) = d;
    fields[1] = e;
    Network_QueueOutgoingRecord(object, source, 0);
}
