#include "World/Zone3DEmbeddedState.h"
#include "System/Memory.h"

bool ZoneState0840::ContainsStoredValue(int value)
{
    for (int i = 0; i < 3; ++i)
        if (unknown_1b68[i] == value) return true;
    return false;
}

int ZoneState0840::CountEntriesOfKind9()
{
    int count = 0;
    for (int i = 0; i < 30; ++i)
        if (entries[i].flags.kind == 9) ++count;
    return count;
}

int ZoneState0840::CountEntriesOfKind10()
{
    int count = 0;
    for (int i = 0; i < 30; ++i)
        if (entries[i].flags.kind == 10) ++count;
    return count;
}

unsigned char ZoneState0840::TakeFlag1b61()
{
    unsigned char flag = unknown_1b61;
    unknown_1b61 = 0;
    return flag;
}

void ZoneState0840::CopyBytesAtOffset(int offset, const void* source, unsigned int size)
{
    if (!source) return;
    VectorizedInvertedMemcpy(source, (char*)this + offset, size);
}
