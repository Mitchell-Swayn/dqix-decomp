#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" GameObject* GameState_FindIndexedObjectWithFlag400(GameState*, int);
extern "C" int Combat_IsCombatantExcludedFromSelection(char*);
extern "C" bool GameObject_IsDead(int);
struct GroupRecord { unsigned char unknown[2]; unsigned char indices[8]; unsigned char count:4; unsigned char unknownBits:4; unsigned char tail[13]; };
struct GroupCount { unsigned char unknown:4; unsigned char count:2; unsigned char upper:2; };
// Original: arm9/ov000 @ 0x02153E78; symbol: Combat_CollectMonsterTargetsInGroup; size: 0x120.
// Collects grouped object IDs matching byte 0x17c and optional nested flags.
// Group and category meanings remain unknown.
extern "C" int Combat_CollectMonsterTargetsInGroup(unsigned char* self, short* output, int capacity, int category, int flags) {
    GameState* state = GameState::GetInstance();
    int count = 0;
    GroupRecord* groups = (GroupRecord*)(self + 0x81b4);
    for (int group = 0; group < ((GroupCount*)(self + 0x81b1))->count; ++group) {
        GameObject* object;
        unsigned char* indices = (groups + group)->indices;
        int item;
        GroupRecord* record = groups + group;
        for (item = 0; item < record->count; ++item) {
            object = GameState_FindIndexedObjectWithFlag400(state, indices[item] + 0xc0);
            if (object && category == ((unsigned char*)object)[0x17c]) {
                if ((flags & 0x10) || !Combat_IsCombatantExcludedFromSelection((char*)object)) {
                    if (!(flags & 1) || !GameObject_IsDead((int)object)) {
                        output[count] = indices[item] + 0xc0;
                        ++count;
                        if (count == capacity) return count;
                    }
                }
            }
        }
    }
    return count;
}
