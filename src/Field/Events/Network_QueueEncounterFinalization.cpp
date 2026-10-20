#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
extern "C" void Field_FinalizeEncounterParticipants(unsigned short, unsigned, unsigned char, int);
// Original: arm9/ov017 @ 0x021C9C64; symbol: func_ov017_021c9c64; size: 0x4C.
extern "C" void Network_QueueEncounterFinalization(unsigned short first, unsigned char second) {
    unsigned char record[0x14];
    void* object = Network_GetCommandRecordPool();
    record[0] = 0x7c;
    *(unsigned short*)(record + 4) = first;
    record[6] = second;
    Network_QueueOutgoingRecord(object, record, 0);
    Field_FinalizeEncounterParticipants(first, 1, second, -1);
}
