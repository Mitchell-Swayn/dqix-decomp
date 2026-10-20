#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct PackedRecord{char pad[32];unsigned lo:20;unsigned first:10;unsigned hi:2;unsigned second:10;unsigned third:10;unsigned fourth:10;unsigned spare:2;};struct ByteFlags{char pad[28];unsigned char low:7;unsigned char enabled:1;};extern "C" char* _Z16GetCombatantByIDii(void*,int);extern "C" int CombatantState_CanApplyFatalDamageProtection(void*);extern "C" void CombatantState_ActivateFatalDamageProtection(void*);extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,unsigned,unsigned);extern "C" void* Combat_ClearCurrentResultNodeSlot(void*);extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,int,int,int);
// Original: arm9/ov024 @ 0x021DEFF8; symbol: Combat_AddIndexedEntryAfterSettingByte67Flag; size: 0xF8.
extern "C" void* Combat_ApplyAlmaMaterAndBuildResult(char* self,int unused,int index,char* record,int unused5,int unused6,unsigned char enabled){char* target=_Z16GetCombatantByIDii(P(self,16),index);if(!target)return 0;void* object;unsigned short id;if(CombatantState_CanApplyFatalDamageProtection(P(target,0x138))&&enabled){CombatantState_ActivateFatalDamageProtection(P(target,0x138));id=Combat_SelectMessageForPartyOrMonster(index,((PackedRecord*)record)->first,((PackedRecord*)record)->second);}else{id=Combat_SelectMessageForPartyOrMonster(index,((PackedRecord*)record)->third,((PackedRecord*)record)->fourth);}object=Combat_ClearCurrentResultNodeSlot(P(self,16));if(!object)return 0;Combat_AppendResultMessage(P(self,16),object,id);int flag=((ByteFlags*)P(self,12))->enabled?1:0;Combat_PopulateResultWithCurrentHealthAndMagic(P(self,16),object,target,0,0,0,flag);return object;}
