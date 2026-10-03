#pragma once

namespace Ov006Selection {
struct Entry {
    short id;
    unsigned short flag0 : 1;
    unsigned short flag1 : 1;
    unsigned short otherFlags : 14;
};
struct Record {
    short unknown0[2];
    short ids[3];
    unsigned short quantity0 : 4;
    unsigned short quantity1 : 4;
    unsigned short quantity2 : 4;
    unsigned short unknownQuantity : 4;
    unsigned int unknownC;
    unsigned int flags;
};
// Layout shared with RequirementSelection.cpp; names retain unresolved meaning.
struct State {
    void* records;
    short** categoryIds;
    unsigned char** categoryQuantities;
    unsigned short* categoryCounts;
    Record* record;
    short indices[3];
    signed char categories[3];
    Entry* entries;
    unsigned short entryCount;
};
}
