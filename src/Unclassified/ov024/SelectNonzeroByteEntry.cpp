#include <globaldefs.h>

struct EntryState { unsigned char pad[0x10]; unsigned char entries[0x28]; int selected; int cachedIndex; unsigned char cachedValue; };
#pragma force_active on
// Original: arm9/ov024 @ 0x021FE698; symbol: func_ov024_021fe698; size: 0x1C.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" int SelectNonzeroByteEntry(EntryState* self, int index)
{
    if (!self->entries[index]) return 0; self->selected=index; return 1;
}
