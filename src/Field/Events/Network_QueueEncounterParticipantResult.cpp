#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021C9B20; symbol: GameState_QueueObjectAndByteRecord57; size: 0x38.
// Temporary record values and callee match semantically, but compiler initializes the stack record before the global read and omits the listed preserved registers. [2026-10-17 11:40 l12e] Builds a 20-byte queued record with tag 0x57, the object’s low halfword, and the supplied byte, then passes it with the global source to the queue mover.
extern "C" void Network_QueueEncounterParticipantResult(void* object, unsigned char value) {
    struct Record { unsigned char tag; unsigned char pad[5]; unsigned short object; unsigned char pad2[2]; unsigned char value; unsigned char pad3[9]; } record;
    void* source = Network_GetCommandRecordPool();
    record.tag = 0x57;
    record.object = (unsigned short)object;
    record.value = value;
    Network_QueueOutgoingRecord(source, &record, 0);
}
