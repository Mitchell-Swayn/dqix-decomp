#include <globaldefs.h>

ARM

// Byte 0 of a record: signed 6-bit slot id and two flags.
struct SlotHeader {
    signed char slotId : 6;
    unsigned char flag6 : 1;
    unsigned char flag7 : 1;
};

// 0x23c-byte record. The remaining contents are copied by func_02086868 and
// not interpreted here.
struct SlotRecord {
    SlotHeader header;
    unsigned char unknown_001[0x23c - 1];
};

// Owner holding up to 13 records at +0xf80 and their count at +0x2c8c.
struct SlotRecordTable {
    unsigned char unknown_0000[0xf80];
    SlotRecord records[13];
    unsigned char count;
};

// Copies input into output (returns output).
extern "C" SlotRecord* PartyRecord_CopySerializedCharacter(SlotRecord* output, const SlotRecord* input);

// Assigns the lowest slot id (0..15) unused by the table's records to record,
// stores the two flags, and appends a copy. Returns 0 if every id is in use.
// Original: arm9/main @ 0x02086778; symbol: func_02086778; size: 0xF0.
extern "C" int SlotRecordTable_AssignUnusedSlotIDAndAppendRecord(SlotRecordTable* table, SlotRecord* record, unsigned char flag6, unsigned char flag7)
{
    signed char freeId = -1;
    for (signed char id = 0; id < 16; id++) {
        int used = 0;
        for (unsigned char i = 0; i < table->count; i++) {
            if (id == table->records[i].header.slotId) {
                used = 1;
                break;
            }
        }
        if (!used) {
            freeId = id;
            break;
        }
    }
    if (freeId < 0) {
        return 0;
    }
    record->header.slotId = freeId;
    record->header.flag6 = flag6;
    record->header.flag7 = flag7;
    PartyRecord_CopySerializedCharacter(&table->records[table->count], record);
    table->count++;
    return 1;
}
