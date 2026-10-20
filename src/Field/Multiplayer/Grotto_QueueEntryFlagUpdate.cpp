#include <globaldefs.h>
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsClientSession(void*);
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
struct CodeA2Message { unsigned char tag; unsigned char pad[3]; unsigned char value; unsigned char tail[15]; };
// The message byte's meaning is unresolved.
// Original: arm9/ov017 @ 0x021cfc74; symbol: func_ov017_021cfc74; size: 0x40.
extern "C" void Grotto_QueueEntryFlagUpdate(unsigned char value) {
    void* connection = Network_GetConnectionManager();
    if (Network_IsClientSession(connection)) return;
    void* queue = Network_GetCommandRecordPool();
    CodeA2Message message;
    message.tag = 0xa2;
    message.value = value;
    Network_QueueOutgoingRecord(queue, &message, 0);
}
