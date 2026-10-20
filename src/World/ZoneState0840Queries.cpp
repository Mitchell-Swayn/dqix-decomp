#include "World/Zone3DEmbeddedState.h"
#include "System/Memory.h"

// Original: arm9/main @ 0x02098E3C; symbol: _ZN13ZoneState084019ContainsStoredValueEi; size: 0x34.
bool ZoneState0840::ContainsStoredValue(int value)
{
    for (int i = 0; i < 3; ++i)
        if (unknown_1b68[i] == value) return true;
    return false;
}

// Original: arm9/main @ 0x02098E70; symbol: _ZN13ZoneState084019CountEntriesOfKind9Ev; size: 0x3C.
int ZoneState0840::CountEntriesOfKind9()
{
    int count = 0;
    for (int i = 0; i < 30; ++i)
        if (entries[i].flags.kind == 9) ++count;
    return count;
}

// Original: arm9/main @ 0x02098EAC; symbol: _ZN13ZoneState084020CountEntriesOfKind10Ev; size: 0x3C.
int ZoneState0840::CountEntriesOfKind10()
{
    int count = 0;
    for (int i = 0; i < 30; ++i)
        if (entries[i].flags.kind == 10) ++count;
    return count;
}

// Original: arm9/main @ 0x02098EE8; symbol: _ZN13ZoneState084012TakeFlag1b61Ev; size: 0x14.
unsigned char ZoneState0840::TakeFlag1b61()
{
    unsigned char flag = unknown_1b61;
    unknown_1b61 = 0;
    return flag;
}

// Original: arm9/main @ 0x02098EFC; symbol: _ZN13ZoneState084017CopyBytesAtOffsetEiPKvj; size: 0x24.
void ZoneState0840::CopyBytesAtOffset(int offset, const void* source, unsigned int size)
{
    if (!source) return;
    MI_CpuCopy8(source, (char*)this + offset, size);
}
