#include <globaldefs.h>
ARM
// Original: arm9/ov017:021cd1ac; Selects the flagged GameState object from record byte +4, applies halfword entries from +6 to its offset-0x150 data, then finalizes the data.
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" void CharacterState_LearnSkill(unsigned char*, int);
extern "C" void CharacterState_RecalculateOrPreviewDerivedStats(void*, int);
extern "C" void PartySync_ApplyLearnedSkills(void* unused, unsigned char* record, void* game) {
    volatile unsigned char* values = record + 4;
    unsigned index = ((unsigned)values[0] << 29) >> 29;
    void* object = GameState_GetObjectWithFlag100(game, index);
    if (object == 0) return;
    unsigned char* data = GameObject_GetLinkedIndexedState(object);
    if (data == 0) return;
    for (int i = 0; i < (int)(((unsigned)values[0] << 26) >> 29); ++i)
        CharacterState_LearnSkill(data, *(unsigned short*)(values + 2 + i * 2));
    CharacterState_RecalculateOrPreviewDerivedStats(data, 0);
}
