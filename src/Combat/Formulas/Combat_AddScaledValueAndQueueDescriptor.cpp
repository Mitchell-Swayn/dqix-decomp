#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {unsigned char* _Z16GetCombatantByIDii(int,int);int GameState_AddCombatantValueUpToMaximum(void*,int,unsigned short,unsigned short*);void* Combat_ClearCurrentResultNodeSlot(unsigned char*);void Combat_AppendResultMessage(void*,void*,unsigned short);void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);void Combat_PopulateResultFromCombatantSnapshot(void*,void*,void*,short,short,short,void*,void*,unsigned char);void Combat_AppendActorResultToCategoryList(void*,void*,int);}
// Original: arm9/ov024 @ 0x021E56C0; symbol: Combat_AddScaledValueAndQueueDescriptor; size: 0x100.
// Adds amount divided by eight to combatant value and queues a descriptor with operation bit34.
extern "C" void Combat_AddScaledValueAndQueueDescriptor(unsigned char* self,int index,int unused,int amount){unsigned char* combatant=_Z16GetCombatantByIDii(W(self,16),index);if(!combatant)return;int scaled=amount>>3;if(scaled<=0)return;unsigned short applied=0;int value=((int(*)(void*,int,int,unsigned short*))GameState_AddCombatantValueUpToMaximum)(P(self,16),index,scaled,&applied);H(P(self,8),0x24)=value;void* record=Combat_ClearCurrentResultNodeSlot(P(self,16));if(!record)return;Combat_AppendResultMessage(P(self,16),record,0x214);unsigned long long mask=0;Combat_SetResultMaskFlag(P(self,16),&mask,34);((void(*)(void*,void*,void*,short,int,int,unsigned long long,unsigned char))Combat_PopulateResultFromCombatantSnapshot)(P(self,16),record,combatant,(short)-scaled,H(P(combatant,0x138),0),value,mask,0);Combat_AppendActorResultToCategoryList(P(self,8),record,2);++P(self,16)[0x8e02];}
