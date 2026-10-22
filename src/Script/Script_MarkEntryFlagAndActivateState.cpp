#include <globaldefs.h>
ARM

struct PackedEntryStateOwner { unsigned char unknown[0x2cc]; unsigned char packedEntryStates[102]; };
extern "C" void Script_SetPackedEntryStateAndNotifyPeers(PackedEntryStateOwner*, int, int);

// Original: arm9/main @ 0x0206E218; symbol: func_0206e218; size: 0x48.
extern "C" void Script_MarkEntryFlagAndActivateState(void *object, int index) {
    if (index >= 0xCC || index < 0) {
        return;
    }
    int remainder = index % 2;
    int half = index / 2;
    PackedEntryStateOwner* owner = (PackedEntryStateOwner*)object;
    owner->packedEntryStates[half] |= remainder ? 0x40 : 4;
    Script_SetPackedEntryStateAndNotifyPeers(owner, index, 1);
}
