// Clears the byte flag after invoking the overlay pop helper when it is set.
extern "C" void GameState_ClearPartyObjectFlagsAndReleaseTask(void*);
extern "C" void OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(int);
// Original: arm9/ov004 @ 0x0216FA48; symbol: func_ov004_0216fa48; size: 0x2C.
extern "C" void ClearFlagAndPopOverlaySlot(unsigned char* object) {
    GameState_ClearPartyObjectFlagsAndReleaseTask(object);
    if (object[0xF] != 0) {
        OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(1);
        object[0xF] = 0;
    }
}
