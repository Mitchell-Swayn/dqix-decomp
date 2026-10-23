#include <globaldefs.h>
typedef unsigned undefined4;
#pragma opt_propagation off
#include <GameState/GameState.h>
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" unsigned GameObject_GetLinkedIndexedState(int);
extern "C" void CharacterState_RecalculateOrPreviewDerivedStats(void*,void*);
extern "C" void Text_SetupCenteredSelectedPartLabel(char*,int,int,int,unsigned char,int,int);
extern "C" void CharacterStatus_PopulateVocationSkillLines(void*,unsigned,const unsigned char*);
extern "C" void CharacterStatus_SetDisplayedStatistics(void*,const int*);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
struct StatWord {unsigned first:10,second:10,third:10,remaining:2;};
struct LowBit {unsigned char flag:1,remaining:7;};
// Original: arm9/ov003 @ 0x02167B34; symbol: func_ov003_02167b34; size: 0x168.
// Recalculates the selected character and fills the active status panel fields.
extern "C" void CharacterStatus_PopulateActiveCharacterDetails(char* self){
 GameObject* object=GameState_GetObjectWithFlag100(GameState::GetInstance(),*(signed char*)(self+0x76));
 if(!object)return;
 unsigned char* stats=(unsigned char*)GameObject_GetLinkedIndexedState((int)object);
 CharacterState_RecalculateOrPreviewDerivedStats(stats,0);
 int vocation=*(int*)(stats+0x950);
 int text=*(int*)((char*)object+0x134);
 Text_SetupCenteredSelectedPartLabel(self,text,((LowBit*)(stats+0x49c))->flag,(unsigned char)vocation,(stats+vocation)[0x186],*(unsigned short*)(stats+0x16c+vocation*2),*(int*)(stats+0x138+vocation*4));
 CharacterStatus_PopulateVocationSkillLines(self,(unsigned char)*(int*)(stats+0x950),stats+0x464);
 int values[12];StatWord* packed=(StatWord*)stats;
 values[0]=packed[0].first;values[1]=packed[0].second;values[2]=packed[0].third;
 values[3]=packed[1].first;values[4]=packed[1].second;values[5]=packed[1].third;
 values[6]=packed[2].first;values[7]=packed[2].second;values[8]=packed[2].third;
 values[9]=*(unsigned short*)(*(unsigned char**)((char*)object+0x134)+0x34);values[10]=*(unsigned short*)(*(unsigned char**)((char*)object+0x134)+0x36);values[11]=packed[3].first;
 CharacterStatus_SetDisplayedStatistics(self,values);
 TextCanvas_CreateAndConfigureDisplayPart(*(char**)(self+0x10),0);
}
