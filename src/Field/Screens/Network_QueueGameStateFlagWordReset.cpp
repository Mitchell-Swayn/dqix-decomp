#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021D3EC8; symbol: Unclassified_ApplyTagA7SourceRecordToGlobalObject; size: 0x28.
// Reads the global object, creates a 0x14-byte local source with leading byte 0xA7, then submits it with value zero.
extern "C" void Network_QueueGameStateFlagWordReset(void) {
    unsigned char local[0x14];
    void *object = Network_GetCommandRecordPool();
    local[0] = 0xa7;
    Network_QueueOutgoingRecord(object, local, 0);
}
