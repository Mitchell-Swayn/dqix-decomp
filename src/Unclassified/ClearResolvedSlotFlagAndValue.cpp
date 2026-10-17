#include <globaldefs.h>

extern "C" unsigned int Object_FindSignedByteKeyInSixteenEntries(void);
extern "C" unsigned int FindSignedByteValueInSixteenSlots(int, unsigned int);
extern "C" void ClearResolvedBitInByteField100FUnlessActive(int, unsigned int);
extern "C" void UpdateEnabledMemberCountAndTimestampOnTransition(int);

// Original: arm9/main @ 0x0202C21C; symbol: func_0202c21c; size: 0x6C.
extern "C" void ClearResolvedSlotFlagAndValue(int state, unsigned int value) {
    unsigned int index=Object_FindSignedByteKeyInSixteenEntries();
    if ((int)index < 0 && (int)(index=FindSignedByteValueInSixteenSlots(state,value)) < 0)
        return;
    *(unsigned char *)(state+0x100c) &= ~(1 << index);
    ClearResolvedBitInByteField100FUnlessActive(state,value);
    UpdateEnabledMemberCountAndTimestampOnTransition(state);
    *(unsigned char *)(state+index+0x1038)=0;
}
