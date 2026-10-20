#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
struct Object;
extern "C" void Network_QueueOutgoingRecord(Object *, const void *, short);
// Original: arm9/ov017 @ 0x021CA174; symbol: Object_QueueRecordType59WithInputShort; size: 0x30.
// Creates a stack record with type byte 0x59 and the input short at +4, then queues it against the global object.
extern "C" void Network_QueueSignedControlValue(short value) {
    unsigned char record[0x14];
    Object *object = (Object *)Network_GetCommandRecordPool();
    record[0] = 0x59;
    *(short *)(record + 4) = value;
    Network_QueueOutgoingRecord(object, record, 0);
}
