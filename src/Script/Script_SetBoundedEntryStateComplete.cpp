#include <globaldefs.h>

struct PackedEntryStateOwner;
extern "C" void Script_SetPackedEntryStateAndNotifyPeers(PackedEntryStateOwner*, int, int);

// Original: arm9/main @ 0x0206E100; symbol: func_0206e100; size: 0x20.
extern "C" ARM void Script_SetBoundedEntryStateComplete(void* owner, int index) {
    if(index>=204) return;
    if(index<0) return;
    Script_SetPackedEntryStateAndNotifyPeers((PackedEntryStateOwner*)owner, index, 3);
}
