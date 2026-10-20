#include <globaldefs.h>
#pragma optimization_level 4
struct ThreeHalfwordRecord { unsigned short fields[3]; };
struct RecordCollection { unsigned short count; unsigned short padding; ThreeHalfwordRecord *records; };
// Original: arm9/main @ 0x0205B008; symbol: func_0205b008; size: 0xD0.
// Clears mask bits and inserts shifted value into one halfword of every record.
// The owner argument is unused; record count and pointer are at offsets 0 and 4.
// Returns 1 for null collection or invalid field, otherwise 0.
// Proposed name: ReplaceSelectedHalfwordBitsInRecordCollection.
extern "C" int Graphics_ReplaceCellOamAttributeBits(void *owner, RecordCollection *collection, unsigned int field, unsigned int mask, unsigned short shift, unsigned int value)
{
    if (!collection) return 1;
    if (field >= 3) return 1;
    // Preserve the original repeated null check.
    if (!collection) return 1;
    value = (unsigned short)(value << shift);
    unsigned int inverse = ~mask;
    for (unsigned short i = 0; i < collection->count; ++i) {
        ThreeHalfwordRecord *record = &collection->records[i];
        unsigned int bits;
        switch (field) {
        case 0: bits = record->fields[0]; break;
        case 1: bits = record->fields[1]; break;
        case 2: bits = record->fields[2]; break;
        }
        bits = (unsigned short)(bits & inverse) | value;
        switch (field) {
        case 0: record->fields[0] = bits; break;
        case 1: record->fields[1] = bits; break;
        case 2: record->fields[2] = bits; break;
        }
    }
    return 0;
}
