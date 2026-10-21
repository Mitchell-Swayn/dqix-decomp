#include <globaldefs.h>
ARM
#include "GameState/GameState.h"

typedef unsigned int undefined4;

extern "C" GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
extern "C" ARM undefined4 GameObject_GetLinkedIndexedState(int param_1);
extern "C" void CharacterState_RecalculateOrPreviewDerivedStats(void*, void*);

struct PackedTenBitTriple {
    unsigned x : 10;
    unsigned y : 10;
    unsigned z : 10;
    unsigned reserved : 2;
};

// Original: arm9/ov017 @ 0x021CE8AC; symbol: func_ov017_021ce8ac; size: 0x180.
// Copies packed ten-bit triples from the incoming record into the linked character
// state at 0x91c/0x920/0x924 and the low field at 0x928, then recalculates derived stats.
extern "C" void CharacterState_ApplyBaseStatsAndRecalculate(void* unused, const unsigned char* record, GameState* gameState) {
    unsigned indexWord = *(const unsigned*)(record + 0x10);
    GameObject* object = GameState_GetObjectWithFlag100(gameState, (int)((indexWord << 19) >> 29));
    if (!object) {
        return;
    }
    undefined4 dataWord = GameObject_GetLinkedIndexedState((int)object);
    if (!dataWord) {
        return;
    }
    unsigned char* data = (unsigned char*)dataWord;
    const PackedTenBitTriple* input = (const PackedTenBitTriple*)(record + 4);
    PackedTenBitTriple* output = (PackedTenBitTriple*)(data + 0x91c);
    output[0].x = input[0].x;
    output[0].y = input[0].y;
    output[0].z = input[0].z;
    output[1].x = input[1].x;
    output[1].y = input[1].y;
    output[1].z = input[1].z;
    output[2].x = input[2].x;
    output[2].y = input[2].y;
    output[2].z = input[2].z;
    output[3].x = input[3].x;
    CharacterState_RecalculateOrPreviewDerivedStats(data, 0);
}
