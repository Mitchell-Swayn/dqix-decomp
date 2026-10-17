#include <globaldefs.h>

struct EntryState { unsigned char pad[0x10]; unsigned char entries[0x28]; int selected; int cachedIndex; unsigned char cachedValue; };
#pragma force_active on
// Original: arm9/ov024 @ 0x021FE6B4; symbol: func_ov024_021fe6b4; size: 0x14.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" void CacheSelectedByteEntry(EntryState* self, int index)
{
    self->cachedIndex=index; self->cachedValue=self->entries[index];
}
