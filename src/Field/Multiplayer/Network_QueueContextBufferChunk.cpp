#include <globaldefs.h>
ARM
struct Object;
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object* object,const void* source,short value);
extern "C" void *GameState_GetSerializedProgressState();
struct Payload { unsigned short mode : 2; unsigned short offset : 14; char bytes[14]; };
struct Request { unsigned char type; char pad[3]; Payload payload; };
// Original: arm9/ov017 @ 0x021CDC24; symbol: func_ov017_021cdc24; size: 0xA8.
extern "C" void Network_QueueContextBufferChunk(int mode, unsigned offset) {
    Object *queue = (Object*)Network_GetCommandRecordPool();
    Request request;
    unsigned short shortMode = mode;
    unsigned short shortOffset = offset;
    Payload *payload = &request.payload;
    payload->mode = shortMode;
    request.type = 0x92;
    payload->offset = shortOffset;
    char *buffer = (char*)GameState_GetSerializedProgressState();
    int count = 14;
    if (offset + 14 > 253) count = 253 - offset;
    if (count >= 0) {
        memcpy(payload->bytes, buffer + offset, count);
        Network_QueueOutgoingRecord(queue, &request, 0);
    }
}
