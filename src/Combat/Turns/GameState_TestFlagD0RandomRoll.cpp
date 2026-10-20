#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
extern "C" int CharacterState_GetLearnedSkillMask(unsigned char* state,int bit);
// Original data: arm9/ov000 @ 0x2182ac5; symbol: data_ov000_02182ac5.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000c20200c1018080c102018100000.
// Observed span: 15 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char GameStateTestFlagD0RandomRoll_UnknownRoleInitializedBytes[];
// Original: arm9/ov000 @ 0x021564CC; symbol: func_ov000_021564cc; size: 0x8C.
extern "C" bool GameState_TestFlagD0RandomRoll(void *random, int index) {
    void *state = _ZN9GameState11GetInstanceEv();
    int valid;
    if (index >= 0 && index <= 3) valid = 1;
    else valid = 0;
    if (!valid) return 0;
    char *object = (char*)GameState_GetObjectWithFlag100(state, index);
    if (!object) return 0;
    int enabled = CharacterState_GetLearnedSkillMask(*(unsigned char**)(object + 0x150), 0xd0);
    if (enabled == 0) return 0;
    unsigned char *values = *(unsigned char**)(object + 0x150);
    return _Z13NextRandomMaxP6Randomi(random, GameStateTestFlagD0RandomRoll_UnknownRoleInitializedBytes[*(unsigned*)(values + 0x950)]) == 1;
}
