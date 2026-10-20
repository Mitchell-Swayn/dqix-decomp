#include <globaldefs.h>
ARM
extern "C" void MoveQueuedRecordWithResourceByteQuad();
extern "C" void GameState_CreateMissingFlaggedPartyObjects(void*);
// Original: arm9/ov017 @ 0x021B0224; symbol: Object_ValidateActiveSlotFlagsAndRecover; size: 0x64.
// Checks active slot bytes against their corresponding bits in the flag byte; returns object status on failure or runs the recovery helpers and returns 4.
extern "C" int Field_WaitForPartyJoinRosterAcknowledgments(unsigned char* object) {
    int valid = 1;
    for (int slot = 1; slot < 4; ++slot) {
        unsigned char* entry = object + slot;
        if (entry[0x1b] == 1 && (object[0x1f] & (1 << slot)) == 0) {
            valid = 0;
            break;
        }
    }
    if (!valid) return object[0xa];
    MoveQueuedRecordWithResourceByteQuad();
    GameState_CreateMissingFlaggedPartyObjects(object);
    return 4;
}
