#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
// Original: arm9/ov017 @ 0x021A20C0; symbol: func_ov017_021a20c0; size: 0x68.
// Finds an existing object whose signed record identifier marks an unused group slot.
extern "C" int FieldMonster_FindUnusedSlotInGroup(void* self, int group, int count) {
    GameState* game = GameState::GetInstance();
    if (count > 12) count = 12;
    for (int i = 0; i < count; ++i) {
        GameObject* object = game->GetGameObjectByIndex(i + (group * 12 + 0x70));
        if (object && *(short*)((char*)object + 2) < 0) return i + (group * 12 + 0x70);
    }
    return -1;
}
