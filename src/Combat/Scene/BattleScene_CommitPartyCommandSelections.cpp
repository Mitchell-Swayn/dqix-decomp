#include <globaldefs.h>
#include "GameState/GameState.h"
ARM
#pragma opt_common_subs off
#pragma opt_arithtransformation off
#pragma opt_propagation off
#pragma always_inline on
extern "C" {
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
int GameObject_GetCombatTrackingRecord(int);
unsigned PartySelection_GetMemberMask(unsigned char*,unsigned);
void Util_CopyFourSlotRecordSummary(char*,int,signed char*);
void* BattleMenu_FindItemByEquipmentKey(char*,int);
void* BattleMenu_GetEnemyTargetGroupKey(void*,int);
void* BattleMenu_GetEnemyTargetObjectId(void*,int);
void CombatantMotion_SetPrimaryTargetIndex(int,unsigned char);
}
inline int IsPartyIndex(int id) {return id>=0 && id<=3;}
inline char* FindSelectionRecord(char* self,int id) {
 if(IsPartyIndex(id))for(int i=0;i<4;i++)if(*(int*)(self+0x4104+i*0x448)==id)return self+0x40b8+i*0x448;
 return 0;
}
// Original: arm9/ov000 @ 0x02169850; symbol: func_ov000_02169850; size: 0x1F0.
// Negated conjunction retains the two mode comparisons and predicated command writes.
// Derives command IDs and linked target bytes from each enabled party member's selection summary.
extern "C" void BattleScene_CommitPartyCommandSelections(char* arg) {
 char* self=arg;
 GameState* game=GameState::GetInstance();
 for(int i=0;i<4;i++) {
 if(!PartySelection_GetMemberMask(*(unsigned char**)(self+0x2a0),(unsigned char)i))continue;
 GameObject* object=GameState_GetObjectWithFlag100(game,i);if(!object)continue;
 unsigned char* command=(unsigned char*)GameObject_GetCombatTrackingRecord((int)object);if(!command)continue;
 char* record=FindSelectionRecord(self,i);if(!record)continue;
 signed char summary[12];Util_CopyFourSlotRecordSummary(self,i,summary);
 unsigned id=1;
 if((unsigned char)summary[1]==0){}
 else if((unsigned char)summary[1]==1)id=*(unsigned short*)(summary+8);
 else if((unsigned char)summary[1]==2)id=3;
 else if((unsigned char)summary[1]==3)id=*(unsigned short*)(summary+8);
 else if((unsigned char)summary[1]==4) {char* entry=(char*)BattleMenu_FindItemByEquipmentKey(record,*(short*)(summary+6));if(entry)id=*(unsigned short*)(entry+0x16);}
 else if((unsigned char)summary[1]==5)id=*(unsigned short*)(summary+8);
 else if((unsigned char)summary[1]==6) {int mode=*(unsigned char*)(self+0x5950);if(!(mode!=3 && mode!=4)) {id=0;command[4]|=1;}else id=0x1f6;}
 *(unsigned short*)command=id;
 int partyId=*(signed char*)(record+0x2e);unsigned slot=*(unsigned char*)(record+0x1d);
 if(IsPartyIndex(partyId)) {command[3]=0;command[2]=partyId;}
 else if(slot>=8) {command[3]=0;command[2]=0;}
 else {command[3]=(unsigned)BattleMenu_GetEnemyTargetGroupKey(self+0x3760,slot);command[2]=(unsigned)BattleMenu_GetEnemyTargetObjectId(self+0x3760,slot);}
 CombatantMotion_SetPrimaryTargetIndex((int)object,(unsigned char)command[2]);
 }
}
