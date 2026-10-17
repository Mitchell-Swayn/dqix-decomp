#include <globaldefs.h>
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D035C; symbol: func_ov017_021d035c; size: 0x44.
extern "C" void Resource_QueueRecordFromThreeBytePayload(unsigned char first, unsigned char second, unsigned char third) {
    unsigned char packet[0x14];
    void* object = ReadGlobalAt02100044();
    packet[0] = 0x96;
    unsigned char* output = packet + 4;
    output[0] = first;
    output[1] = second;
    output[2] = third;
    MoveQueuedRecordAndApplySourceValue(object, packet, 0);
}
