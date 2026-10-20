#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CFDE0; symbol: func_ov017_021cfde0; size: 0x44.
extern "C" void Field_QueueContainerLootFlags(unsigned short a, unsigned short b, unsigned short c) {
    void *object = Network_GetCommandRecordPool();
    unsigned char source[0x14];
    unsigned char *payload = source + 4;
    source[0] = 0xA5;
    *(unsigned short *)payload = a;
    *(unsigned short *)(payload + 2) = b;
    *(unsigned short *)(payload + 4) = c;
    Network_QueueOutgoingRecord(object, source, 0);
}
