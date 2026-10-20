#include <globaldefs.h>
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
struct Code1CMessage {
    unsigned char tag;
    unsigned char padding[3];
    unsigned word;
    unsigned char tail[12];
};
// The payload word's application meaning is unresolved.
// Original: arm9/ov017 @ 0x021d243c; symbol: func_ov017_021d243c; size: 0x30.
extern "C" void Network_QueueInnRecoveryValue(unsigned word) {
    void* queue = Network_GetCommandRecordPool();
    Code1CMessage message;
    message.tag = 0x1c;
    message.word = word;
    Network_QueueOutgoingRecord(queue, &message, 0);
}
