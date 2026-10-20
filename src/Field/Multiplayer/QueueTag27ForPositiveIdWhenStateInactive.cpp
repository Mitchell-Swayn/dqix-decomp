#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool();
extern "C" void *Network_GetConnectionManager();
extern "C" int Network_IsParentOrOffline(unsigned *);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CE400; symbol: QueueTag27ForPositiveIdWhenStateInactive; size: 0x58.
// When the connection-state predicate passes and the first value is positive, queues tag 0x27 with the two halfwords and source value zero.
extern "C" void QueueTag27ForPositiveIdWhenStateInactive(int a, unsigned short b) {
    void *queue = Network_GetCommandRecordPool();
    int active = Network_IsParentOrOffline((unsigned int *)Network_GetConnectionManager());
    if (active && a > 0) {
        unsigned char source[0x14];
        source[0] = 0x27;
        *(unsigned short *)(source + 4) = a;
        *(unsigned short *)(source + 6) = b;
        Network_QueueOutgoingRecord(queue, source, 0);
    }
}
