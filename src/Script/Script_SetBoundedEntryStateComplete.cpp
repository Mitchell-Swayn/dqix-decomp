#include <globaldefs.h>

extern "C" void Script_SetPackedEntryStateAndNotifyPeers(void*, int, unsigned, unsigned);

// Original: arm9/main @ 0x0206E100; symbol: func_0206e100; size: 0x20.
extern "C" ARM void Script_SetBoundedEntryStateComplete(void* owner, int index, unsigned unused, unsigned context) {
    if(index>=204) return;
    if(index<0) return;
    Script_SetPackedEntryStateAndNotifyPeers(owner, index, 3, context);
}
