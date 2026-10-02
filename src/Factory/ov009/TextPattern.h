#ifndef FACTORY_OV009_TEXT_PATTERN_H
#define FACTORY_OV009_TEXT_PATTERN_H

#include "std_library_functions.h"

union TextTableReference {
    unsigned int offset;
    const char* pointer;
};

struct TextPatternRecord {
    TextTableReference references[7];
    unsigned char unknown_1c[2];
    unsigned char referenceCount;
    unsigned char unknown_1f;
};

struct TextPatternTable {
    unsigned int flagsAndCount;
    TextPatternRecord* records;
    const char* referenceBase;
};

// Resource table loaded by 020e0280, initialized by 020dfc40. Its trailing
// fields are not used by the reconstructed ov009 functions; retain their layout
// without claiming their meaning. This is a distinct table from patternTable.
struct TextResourceTable {
    unsigned int flagsAndCount;
    void* records;
    const char* referenceBase;
    short unknown_0c;
    unsigned short unknown_0e;
    int unknown_10;
    void* unknown_14;
};

// Embedded at owner + 0xfc. 021847ec initializes the separate pattern table
// and all fifteen syntax bytes. 02189a4c loads the resource table and text data.
struct TextPatternContext {
    TextResourceTable resourceTable;
    TextPatternTable patternTable;
    const unsigned char* textData;
    unsigned short textDataSize;
    unsigned char syntax[15];
};

typedef char TextPatternRecordSizeCheck[sizeof(TextPatternRecord) == 0x20 ? 1 : -1];
typedef char TextResourceTableSizeCheck[sizeof(TextResourceTable) == 0x18 ? 1 : -1];
typedef char TextPatternTableSizeCheck[sizeof(TextPatternTable) == 0xc ? 1 : -1];
typedef char TextPatternSyntaxOffsetCheck[offsetof(TextPatternContext, syntax) == 0x2a ? 1 : -1];

#endif
