#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned int GameState_ReadAttributeBits12To19(void* state, int identifier);
extern "C" int CharacterState_GetLearnedSkillMask(void* object, int identifier);
// Original data: arm9/main @ 0x20e8c00; symbol: data_020e8c00.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 21000000860000000000000003000000010000000d000000020000001b00000005000000460000000600000071000000070000007d00000008000000b5000000 ...; full span in module reference.
// Observed span: 88 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const unsigned int ReadDescriptorDependentStateValue_UnknownRoleInitializedBytes[];

// Original: arm9/main @ 0x02085AB8; symbol: func_02085ab8; size: 0xD0.
extern "C" unsigned int ReadDescriptorDependentStateValue(unsigned char* object, unsigned char* descriptor)
{
    void* state = GameState::GetInstance();
    if (((*(unsigned int*)(descriptor + 0x18) << 16) >> 28) == 2) {
        if ((object[0x8f8] & 0x80) == 0) return 0;
        return GameState_ReadAttributeBits12To19(state, 0x67);
    }
    unsigned int key = 0x21;
    if (*(short*)(object + 0x2ac) > 0)
        key = (*(unsigned int*)(object + 0x29c) << 23) >> 27;
    const unsigned int* map = ReadDescriptorDependentStateValue_UnknownRoleInitializedBytes;
    int identifier = -1;
    while (*map != 0xffffffff) {
        if (*map == key) {
            identifier = (short)map[1];
            break;
        }
        map += 2;
    }
    unsigned int result = 0;
    if (identifier != -1 && CharacterState_GetLearnedSkillMask(object, identifier) != 0)
        result += GameState_ReadAttributeBits12To19(state, identifier);
    return result;
}
