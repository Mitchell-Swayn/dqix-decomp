#include <globaldefs.h>
ARM
// Record layout preserved from the canonical copy owner at 0x02086868.

struct Block13 { unsigned words[13]; }; struct Block39 { unsigned words[39]; }; struct Block4 { unsigned words[5]; };
struct Bytes13 {unsigned char data[13];}; struct Bytes27 {unsigned char data[27];}; struct Bytes9 {unsigned char data[9];}; struct Bytes36 {unsigned char data[36];}; struct Bytes12 {unsigned char data[12];};
struct Words14 {unsigned short data[14];}; struct Words96 {unsigned short data[96];};
struct Record {
 signed char a; unsigned char b; Bytes13 name,otherName;
 Block13 block1c; unsigned value50; unsigned short value54,unknown56; Block39 block58;
 unsigned short valuef4; Bytes27 bytesf6; Bytes9 bytes111; Bytes36 bytes11a;unsigned char value13e,value13f; Bytes12 bytes140;
 Block4 block14c; Words14 values160; Words96 values17c;
};

struct SlotHeader {
    signed char slotId : 6;
    unsigned char flag6 : 1;
    unsigned char flag7 : 1;
};
struct SlotRecord { SlotHeader header; unsigned char unknown_001[0x23C - 1]; };
struct SlotRecordTable {
    unsigned char unknown_0000[0xF80];
    SlotRecord records[13];
    unsigned char count;
};
extern "C" Record* PartyRecord_CopySerializedCharacter(Record*, const Record*);

// Original: arm9/main @ 0x02086A04; symbol: func_02086a04; size: 0xE8.
// Removes the first matching signed six-bit stored-character slot and moves
// later serialized characters forward, preserving the two header flag bits.
extern "C" int PartyRoster_RemoveCharacterBySlotIdAndCompact(void* opaqueOwner, int slotId)
{
    SlotRecordTable* owner = (SlotRecordTable*)opaqueOwner;
    if (slotId < 0) return 0;
    unsigned nextOffset;
    int removed = 0;
    {
    SlotRecord* records = owner->records;
    for (unsigned char i = 0; i < owner->count; ++i) {
        SlotHeader* header = &records[i].header;
        if (header->slotId == slotId) {
            header->slotId = -1;
            --owner->count;
            removed = 1;
            break;
        }
    }
    }
    if (removed) {
        for (unsigned char i = 0; i < owner->count; ++i) {
            if (owner->records[i].header.slotId < 0) {
                nextOffset = (i + 1) * sizeof(SlotRecord);
                PartyRecord_CopySerializedCharacter((Record*)(owner->records + i), (Record*)((char*)owner->records + nextOffset));
                ((SlotHeader*)((char*)owner->records + nextOffset))->slotId = -1;
            }
        }
    }
    return removed;
}
