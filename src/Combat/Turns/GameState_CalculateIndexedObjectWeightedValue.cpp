#include <globaldefs.h>
ARM
struct GameState { static GameState* GetInstance(); void* GetCombatantByIndex(int); };
extern "C" {
int Combat_ClassifySpecialEncounterSpecies(unsigned char*);
void* GameState_GetObjectWithFlag100(void*,int);
char* GameState_GetValidObjectByIndex(void*,int);
unsigned char* GameObject_GetLinkedIndexedState(void*);
float CharacterState_GetEquipmentRateBonusFromPayloadC(void*);
int GameState_SumTypeDependentFlags48And88(void*);
int CharacterState_GetLearnedSkillMask(unsigned char*,int);
float Combat_GetHealthRatio(void*);
void* MonsterBattleData_FindEntryById(void*,int);
float Combat_GetMonsterAttributeWeightOrZero(int);
int Combat_HasEvasionModifier(const void*);
int Combat_HasFixedReactionChanceStatus(void*);
}
struct Record {char pad[16];unsigned a:13,kind:3,b:16;};
// Original: arm9/ov000 @ 0x02156270; symbol: func_ov000_02156270; size: 0x17C.
extern "C" float GameState_CalculateIndexedObjectWeightedValue(unsigned char* self,int index){
if(Combat_ClassifySpecialEncounterSpecies(self))return 0;
GameState* gs=GameState::GetInstance();
void* obj=GameState::GetInstance()->GetCombatantByIndex(index);
if(!obj)return 0;
float value;
int valid;if(index>=0 && index<=3)valid=1;else valid=0;
if(valid){
void* o=GameState_GetObjectWithFlag100(gs,index);if(!o)return 0;
unsigned char* data=GameObject_GetLinkedIndexedState(o);if(!data)return 0;
float two=2.0f;
float weighted=CharacterState_GetEquipmentRateBonusFromPayloadC(data);
float sum=(float)GameState_SumTypeDependentFlags48And88(data);
float base=two+weighted;
value=sum+base;
if(CharacterState_GetLearnedSkillMask(data,0xa6) && Combat_GetHealthRatio(obj)<0.08f)value*=two;
}else{
char* o=GameState_GetValidObjectByIndex(gs,index);if(!o)return 0;
Record* record=(Record*)MonsterBattleData_FindEntryById(*(char**)(self+0x8e18)+0x684,*(short*)(o+2));
signed char kind=record->kind;
value=Combat_GetMonsterAttributeWeightOrZero(kind);
}
if(Combat_HasEvasionModifier(obj))value=2.0f*value;
if(Combat_HasFixedReactionChanceStatus(obj))return 50.0f;
return value;
}
