#include <globaldefs.h>
ARM
struct Object;
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(Object* object,const void* source,short value);
extern "C" void *ReadGlobalValueAt02108844();
struct Payload { unsigned short mode : 2; unsigned short offset : 14; char bytes[14]; };
struct Request { unsigned char type; char pad[3]; Payload payload; };
// Original: arm9/ov017 @ 0x021CDC24; symbol: func_ov017_021cdc24; size: 0xA8.
extern "C" void Network_QueueContextBufferChunk(int mode, unsigned offset) {
    Object *queue = (Object*)ReadGlobalAt02100044();
    Request request;
    unsigned short shortMode = mode;
    unsigned short shortOffset = offset;
    Payload *payload = &request.payload;
    payload->mode = shortMode;
    request.type = 0x92;
    payload->offset = shortOffset;
    char *buffer = (char*)ReadGlobalValueAt02108844();
    int count = 14;
    if (offset + 14 > 253) count = 253 - offset;
    if (count >= 0) {
        memcpy(payload->bytes, buffer + offset, count);
        MoveQueuedRecordAndApplySourceValue(queue, &request, 0);
    }
}
