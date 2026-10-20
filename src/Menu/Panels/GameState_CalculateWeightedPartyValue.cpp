#include <globaldefs.h>
ARM
extern "C" {
float _ffltu(unsigned); void* _ZN9GameState11GetInstanceEv();void* Network_GetConnectionManager();char* GameState_GetObjectWithFlag100(void*,int);int GameObject_HasLinkedStatusNibble(char*);unsigned GameObject_GetLinkedIndexedState(char*);
// Original data: arm9/ov023 @ 0x21ffefc; symbol: data_ov023_021ffefc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
unsigned PartySelection_GetMemberMask(void*,unsigned char);unsigned GameObject_GetCombatTrackingCounterOrZero(char*);unsigned GameObject_GetCurrentVocationLevel(char*);int Network_IsSessionActive(void*);int Network_IsMemberActive(void*,int);int CharacterState_TestActiveMappedModifierBit16(void*);int ExperienceAdjustment_GetLevelBiasForReward(void*,int,int);extern char* BattleResultsInitializeContext_UnknownRoleZeroInitializedStorage;
}
// Original: arm9/ov023 @ 0x021F4098; symbol: func_ov023_021f4098; size: 0x3A0.
extern "C" int GameState_CalculateWeightedPartyValue(char* self,int index,unsigned overrideValue){
 void* state=_ZN9GameState11GetInstanceEv();void* connection=Network_GetConnectionManager();char* member=GameState_GetObjectWithFlag100(state,index);
 if(!member||GameObject_HasLinkedStatusNibble(member))return 0;if(!GameObject_GetLinkedIndexedState(member))return 0;
 float amount=(float)*(unsigned*)(self+0x58c0);_ffltu(*(unsigned short*)(self+0x58cc));
 float level[4]={};float weight[4]={};
 for(int i=0;i<4;i++)if(PartySelection_GetMemberMask(*(void**)(self+0x2a0),(unsigned char)i)){
 char* p=GameState_GetObjectWithFlag100(state,i);if(p&&!GameObject_HasLinkedStatusNibble(p)){weight[i]=(float)GameObject_GetCombatTrackingCounterOrZero(p);level[i]=(float)GameObject_GetCurrentVocationLevel(p);}}
 float count=1.0f;if(Network_IsSessionActive(connection)){count=0;for(int i=0;i<4;i++)if(PartySelection_GetMemberMask(*(void**)(self+0x2a0),(unsigned char)i)&&Network_IsMemberActive(connection,i))count+=1.0f;}
 if(overrideValue)amount=(float)overrideValue;
 int bonus=ExperienceAdjustment_GetLevelBiasForReward(BattleResultsInitializeContext_UnknownRoleZeroInitializedStorage+0xf4,(int)(amount*(1.0f+(count-1.0f)/10.0f)),4);
 float t3=weight[3]*(level[3]+(float)bonus);float t2=weight[2]*(level[2]+(float)bonus);float t0=weight[0]*(level[0]+(float)bonus);float t1=weight[1]*(level[1]+(float)bonus);
 float total=t3+(t2+(t0+t1));if(0.0f==total)total=1.0f;
 float adjusted=amount*(1.0f+(count-1.0f)/10.0f);float result=adjusted*((((float)bonus+level[index])*weight[index])/total);
 if(CharacterState_TestActiveMappedModifierBit16(*(void**)(member+0x150)))result*=1.05f;
 if(0.0f<result-(float)(int)result)result+=1.0f;
 if(!overrideValue)for(int i=0;i<4;i++)if(PartySelection_GetMemberMask(*(void**)(self+0x2a0),(unsigned char)i))GameState_GetObjectWithFlag100(state,i);
 return (int)result;
}
