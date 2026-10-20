#include <globaldefs.h>

ARM

// Pad state block at 0x02114e30 (first halfword is a button mask consumed by
// func_02012430 "held" and func_02012444 "newly pressed" tests).
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
extern "C" bool Input_TestKeyMask(unsigned short* pad, unsigned short mask);
extern "C" bool Input_IsKeyMaskNewlyPressed(unsigned short* pad, unsigned short mask);

// Shared key/event slot: event 0 = none, 1 = initial press, 2 = auto-repeat.
struct RepeatKeySlot {
    unsigned short key;
    unsigned char event;
};

// Auto-repeat tracker. Fields 0x4-0x5 are not referenced here.
struct KeyRepeater {
    RepeatKeySlot* slot;
    unsigned char unknown_04[2];
    signed char initialDelay;
    signed char repeatInterval;
    signed char countdown;
};

// Four candidate buttons tested in priority order (data at 0x020e8a84).
struct RepeatKeyList {
    unsigned short keys[4];
};
// Original data: arm9/main @ 0x20e8a84; symbol: data_020e8a84.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 4000800020001000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" RepeatKeyList KeyRepeaterUpdate_UnknownRoleInitializedBytes;

extern "C" void KeyRepeater_Reset(KeyRepeater* repeater);

// Updates the repeater by elapsed ticks and returns the event for this frame.
// Original: arm9/main @ 0x02081F20; symbol: func_02081f20; size: 0x11C.
extern "C" unsigned char KeyRepeater_Update(KeyRepeater* repeater, int elapsed)
{
    if (repeater->slot == NULL) {
        return 0;
    }
    repeater->slot->event = 0;
    if (repeater->slot->key == 0) {
        RepeatKeyList list = KeyRepeaterUpdate_UnknownRoleInitializedBytes;
        for (int i = 0; i < 4; i++) {
            unsigned short key = list.keys[i];
            if (Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, key)) {
                repeater->slot->key = key;
                repeater->countdown = repeater->initialDelay;
                repeater->slot->event = 1;
                break;
            }
        }
    } else if (repeater->slot->key != 0) {
        if (Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, repeater->slot->key)) {
            repeater->countdown -= (signed char)elapsed;
            if (repeater->countdown < 0) {
                repeater->countdown += repeater->repeatInterval;
                repeater->slot->event = 2;
            }
        } else {
            KeyRepeater_Reset(repeater);
        }
    }
    return repeater->slot->event;
}
