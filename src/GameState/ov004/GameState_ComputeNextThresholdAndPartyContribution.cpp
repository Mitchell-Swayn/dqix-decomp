#include <globaldefs.h>
ARM
struct GameState; struct Owner;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState* state);
extern "C" short SumIndexedValuesAcrossPresentPartyIds(Owner* self,int index);
struct Threshold { short value,pad; };
extern "C" Threshold data_ov004_02170010[];
// Original: arm9/ov004 @ 0x0216794C; symbol: func_ov004_0216794c; size: 0xC0.
extern "C" void GameState_ComputeNextThresholdAndPartyContribution(short *current, short *contribution, short *next, unsigned char *reached, int * volatile tier) {
    int *tierOut = tier;
    *current = *(int*)((char*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv()) + 0xf74);
    *contribution = SumIndexedValuesAcrossPresentPartyIds((Owner*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv()),0x5617);
    *reached = 0;
    int value = *current;
    int i;
    for (i = 0; i < 10; i++) {
        if (data_ov004_02170010[i].value > value) goto found;
    }
    i = -1;
    found:
    *tierOut = i;
    if (i >= 0) {
        *next = data_ov004_02170010[i].value;
        if (*current + *contribution >= *next) *reached = 1;
    } else {
        *next = 0;
        *reached = 0;
    }
}
