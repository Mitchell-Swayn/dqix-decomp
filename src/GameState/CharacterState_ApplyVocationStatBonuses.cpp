#include <globaldefs.h>
ARM
#include "GameState/GameState.h"

typedef unsigned int undefined4;

extern "C" GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
extern "C" ARM undefined4 GameObject_GetLinkedIndexedState(int param_1);
extern "C" void CharacterState_RecalculateOrPreviewDerivedStats(void*, void*);

struct PackedTenBitWord {
    unsigned x : 10;
    unsigned y : 10;
    unsigned z : 10;
    unsigned reserved : 2;
};
struct PackedAttributeGroup {
    PackedTenBitWord word[3];
};

// Original: arm9/ov017 @ 0x021CF234; symbol: func_ov017_021cf234; size: 0x18c.
// Writes a selected indexed packed attribute group at linked-state +0x850 and
// recalculates derived stats when record+0x10 bit 11 is set.
extern "C" void CharacterState_ApplyVocationStatBonuses(void* unused, const unsigned char* record, GameState* gameState) {
    GameObject* object = GameState_GetObjectWithFlag100(gameState, (int)(((*(const unsigned*)(record + 0x10)) << 21) >> 29));
    if (!object) {
        return;
    }
    undefined4 dataWord = GameObject_GetLinkedIndexedState((int)object);
    if (!dataWord) {
        return;
    }
    unsigned char* data = (unsigned char*)dataWord;
    unsigned index = (unsigned)((signed)(*(const unsigned*)(record + 0x10)) << 24) >> 24;
    index &= 0xffU;
    const PackedTenBitWord* input = (const PackedTenBitWord*)(record + 4);
    PackedAttributeGroup* output = (PackedAttributeGroup*)(data + 0x850);
    output[index].word[0].x = input[0].x;
    output[index].word[0].y = input[0].y;
    output[index].word[0].z = input[0].z;
    output[index].word[1].x = input[1].x;
    output[index].word[1].y = input[1].y;
    output[index].word[1].z = input[1].z;
    output[index].word[2].x = input[2].x;
    output[index].word[2].y = input[2].y;
    output[index].word[2].z = input[2].z;
    if (((*(const unsigned*)(record + 0x10)) << 20) >> 31) {
        CharacterState_RecalculateOrPreviewDerivedStats(data, 0);
    }
}
