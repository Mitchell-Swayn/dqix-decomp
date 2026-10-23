#include <globaldefs.h>
ARM
#pragma force_active on

extern "C" void BattleHud_AdvanceSelectedSlotPulse(unsigned char*, int);
extern "C" void BattleMenu_UpdatePartyFlashPaletteColor(unsigned char*, int);

// Original data: arm9/ov000 @ 0x021833F8 and 0x02183408.
// Initialized animation tables: {0, 0, -2, 0} and {-2, 0, 0, 0}.
extern "C" const int BattleMenuAdvancePartyPanelFlashAnimations_UnknownRoleInitializedBytes[];
extern "C" const int BattleMenuAdvancePartyPanelFlashAnimations_UnknownRoleInitializedBytes_Variant2[];

struct FlashAnimationState {
    unsigned char prefix[0x93c];
    int tick;
    int firstAnimationValue;
    int secondAnimationValue;
};

// Original: arm9/ov000 @ 0x02175024; symbol: func_ov000_02175024; size: 0xC0.
// Advances valid party-slot pulses, then updates the two values of a 16-tick animation.
extern "C" void BattleMenu_AdvancePartyPanelFlashAnimations(unsigned char* self, int step) {
    unsigned char* record;
    int i = 0;
    for (; i < 4; ++i) {
        record = self + 0x958 + *(signed char*)(self + 0x6c + i) * 0x448;
        int index = *(int*)(record + 0x4c);
        int valid = (index >= 0 && index <= 3) ? 1 : 0;
        if (valid) {
            BattleHud_AdvanceSelectedSlotPulse(record, step);
            if (record[0x24] & 8) BattleMenu_UpdatePartyFlashPaletteColor(self, index);
        }
    }

    FlashAnimationState* animation = (FlashAnimationState*)self;
    animation->tick = (unsigned)animation->tick + (unsigned)step;
    animation->tick &= 15;
    int frame = animation->tick >> 2;
    animation->firstAnimationValue = BattleMenuAdvancePartyPanelFlashAnimations_UnknownRoleInitializedBytes[frame];
    animation->secondAnimationValue = BattleMenuAdvancePartyPanelFlashAnimations_UnknownRoleInitializedBytes_Variant2[frame];
}
