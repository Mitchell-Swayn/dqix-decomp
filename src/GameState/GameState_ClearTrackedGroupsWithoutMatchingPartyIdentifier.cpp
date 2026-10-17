#include <globaldefs.h>
#include "GameState/GameState.h"

ARM

extern "C" GameObject* GameState_GetObjectWithFlag200ByIndex(GameState* state, int index);
extern "C" void GameState_ClearObjectByIndex(GameState* state, int index);
// Returns the word at GameObject+0x158 (selects which identifier field applies).
extern "C" unsigned int ReadWordFieldAtOffset158(GameObject* object);
extern "C" void Object_ResetFlagsAndEmbeddedRecordState(void* group);

// One 0x318-byte group record; only the identifier and the active flag
// (bit 2 of the halfword at +2) are interpreted here.
struct TrackedGroup {
    unsigned short identifier;
    unsigned short unknownFlags0 : 2;
    unsigned short active : 1;
    unsigned short unknownFlags3 : 13;
    unsigned char unknown_004[0x318 - 0x4];
};

// For each active group whose identifier no longer matches any of the first
// four filtered objects, clears its twelve indexed entries and resets it.
// Original: arm9/main @ 0x020288E0; symbol: func_020288e0; size: 0xE4.
extern "C" void GameState_ClearTrackedGroupsWithoutMatchingPartyIdentifier(TrackedGroup* groups)
{
    GameState* state = GameState::GetInstance();
    for (int group = 0; group < 4; group++) {
        TrackedGroup* entry = &groups[group];
        unsigned short identifier = groups[group].identifier;
        if (!entry->active) {
            continue;
        }
        bool found = false;
        for (int i = 0; i < 4; i++) {
            GameObject* object = GameState_GetObjectWithFlag200ByIndex(state, i);
            if (object == NULL) {
                continue;
            }
            if (ReadWordFieldAtOffset158(object) == 0) {
                if (identifier != object->obj3D_.GetField06()) {
                    continue;
                }
            } else if (identifier != *(unsigned int*)((unsigned char*)object + 0x15c)) {
                continue;
            }
            found = true;
            break;
        }
        if (!found) {
            for (int i = 0; i < 12; i++) {
                GameState_ClearObjectByIndex(state, group * 12 + 0x70 + i);
            }
            Object_ResetFlagsAndEmbeddedRecordState(entry);
        }
    }
}
