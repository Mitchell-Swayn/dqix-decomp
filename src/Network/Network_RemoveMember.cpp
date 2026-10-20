#include <globaldefs.h>

extern "C" unsigned int Network_FindWirelessSlotByMemberId(void);
extern "C" unsigned int Network_FindPreviousWirelessSlotByMemberId(int, unsigned int);
extern "C" void Network_ClearMemberHostTrackingFlag(int, unsigned int);
extern "C" void Network_UpdateMemberCountAndSessionTime(int);

// Original: arm9/main @ 0x0202C21C; symbol: func_0202c21c; size: 0x6C.
extern "C" void Network_RemoveMember(int state, unsigned int value) {
    unsigned int index=Network_FindWirelessSlotByMemberId();
    if ((int)index < 0 && (int)(index=Network_FindPreviousWirelessSlotByMemberId(state,value)) < 0)
        return;
    *(unsigned char *)(state+0x100c) &= ~(1 << index);
    Network_ClearMemberHostTrackingFlag(state,value);
    Network_UpdateMemberCountAndSessionTime(state);
    *(unsigned char *)(state+index+0x1038)=0;
}
