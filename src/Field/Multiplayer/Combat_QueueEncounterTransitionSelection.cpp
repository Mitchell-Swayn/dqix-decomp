#include <globaldefs.h>
ARM
extern "C" void Combat_QueueEncounterBattleSlotAssignments(void);
extern "C" void* Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CBC48; symbol: func_ov017_021cbc48; size: 0x78.
extern "C" void Combat_QueueEncounterTransitionSelection(const unsigned char* record) {
    unsigned char copy[0x14];
    Combat_QueueEncounterBattleSlotAssignments();
    void* destination = Network_GetCommandRecordPool();
    copy[0] = 0x64;
    *(unsigned short*)(copy + 4) = *(const unsigned short*)(record + 0);
    *(unsigned short*)(copy + 6) = *(const unsigned short*)(record + 2);
    *(unsigned*)(copy + 8) = *(const unsigned*)(record + 4);
    copy[0xc] = record[8];
    copy[0xd] = (unsigned char)*(const signed char*)(record + 9);
    copy[0xe] = record[10];
    copy[0xf] = record[11];
    copy[0x10] = record[12];
    *(short*)(copy + 0x12) = *(const short*)(record + 0xe);
    Network_QueueOutgoingRecord(destination, copy, 0);
}
