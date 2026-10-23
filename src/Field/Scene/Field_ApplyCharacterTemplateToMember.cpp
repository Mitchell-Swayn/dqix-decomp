#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct TemplateStatTriplet { unsigned x:10,y:10,z:10,reserved:2; };
struct CharacterTemplate { char name[18];unsigned char vocation,spell;TemplateStatTriplet stats[3]; };
struct TemplateBaseStats {
    unsigned word:32;
    unsigned short vocation:7,reserved:9;
    unsigned short padding;
    TemplateStatTriplet stats[3];
};
extern "C" {
char* GameObject_GetLinkedIndexedState(GameObject*);
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
int strcmp(const char*,const char*);
int sprintf(char*,const char*,...);
// Original data: arm9/main @ 0x020EF078; symbol: data_020ef078. String-copy format.
extern const char UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant3[];
void CharacterState_SetBaseStatsAndAttributePercentages(void*,const TemplateBaseStats*,const unsigned char*);
void CharacterState_RecalculateOrPreviewDerivedStats(void*,int);
void CharacterState_SelectAndUnlockVocation(char*,unsigned);
void CharacterState_ClearLearnedSkillsAndSpells(void*);
void CharacterState_LearnSpell(void*,unsigned);
}
#pragma force_active on
// Original: arm9/ov017 @ 0x02191508; symbol: func_ov017_02191508; size: 0x25C.
// Copies the character name and packed base statistics, preserving HP when the name matches.
extern "C" void Field_ApplyCharacterTemplateToMember(int member,CharacterTemplate* source) {
    GameObject* object=GameState_GetObjectWithFlag100(GameState::GetInstance(),member);
    if(!object)return;
    char* state=GameObject_GetLinkedIndexedState(object);
    if(!state)return;
    int hp=-1;
    if(!strcmp(state+0x3c,(char*)source))hp=*(unsigned short*)((*(char**)((char*)object+0x130))+4);
    if(source)sprintf(state+0x3c,UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant3,source);
    else sprintf(state+0x3c,UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant3,state+0x3c);
    TemplateBaseStats stats;
    stats.word=0;stats.reserved=0;
    stats.vocation=source->vocation;
    stats.stats[0].x=source->stats[0].x;stats.stats[0].y=source->stats[0].y;stats.stats[0].z=source->stats[0].z;
    stats.stats[1].x=source->stats[1].x;stats.stats[1].y=source->stats[1].y;stats.stats[1].z=source->stats[1].z;
    stats.stats[2].x=source->stats[2].x;stats.stats[2].y=source->stats[2].y;stats.stats[2].z=source->stats[2].z;
    state[0x56a]=11;
    CharacterState_SetBaseStatsAndAttributePercentages(state,&stats,0);
    CharacterState_RecalculateOrPreviewDerivedStats(state,0);
    if(hp>-1)*(unsigned short*)((*(char**)((char*)object+0x130))+4)=hp;
    else *(unsigned short*)((*(char**)((char*)object+0x130))+4)=*(unsigned short*)((*(char**)((char*)object+0x134))+0x30);
    *(unsigned short*)((*(char**)((char*)object+0x130))+6)=*(unsigned short*)((*(char**)((char*)object+0x134))+0x32);
    CharacterState_SelectAndUnlockVocation(state,0);
    CharacterState_ClearLearnedSkillsAndSpells(state);
    *(unsigned short*)(state+0x16c)=source->vocation;
    CharacterState_LearnSpell(state,source->spell);
}
#pragma force_active off
