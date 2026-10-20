#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int CombatantState_CanApplyMistMe(void*);
extern "C" void CombatantState_ApplyMistMe(void*);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,unsigned,unsigned);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(int,void*,void*,int,int,int,bool);
struct PackedMessages {unsigned char pad[32];unsigned low:20;unsigned first:10;unsigned hi:2;unsigned second:10;unsigned fallback1:10;unsigned fallback2:10;unsigned end:2;};
// Original: arm9/ov024 @ 0x021E0A50; symbol: Combat_CreateRecordAfterSetFlag200000AndClear100000; size: 0xf8.
// Tests and optionally mutates combatant descriptor state, then creates a record with selected packed message.
extern "C" void* Combat_ApplyExclusiveConditionBitTwentyOneAndBuildResult(char *self,int unused,int id,PackedMessages* messages,int unused5,int unused6,unsigned char apply){
 char *object=_Z16GetCombatantByIDii(*(int*)(self+16),id);if(!object)return 0;
 unsigned short message;
 if(CombatantState_CanApplyMistMe(*(void**)(object+0x138))&&apply){CombatantState_ApplyMistMe(*(void**)(object+0x138));message=Combat_SelectMessageForPartyOrMonster(id,messages->first,messages->second);}
 else message=Combat_SelectMessageForPartyOrMonster(id,messages->fallback1,messages->fallback2);
 void *record=Combat_ClearCurrentResultNodeSlot(*(unsigned char**)(self+16));if(!record)return 0;
 Combat_AppendResultMessage(*(void**)(self+16),record,message);
 bool flag=(((unsigned)*(unsigned char*)(*(char**)(self+12)+28)<<24)>>31)!=0;
 Combat_PopulateResultWithCurrentHealthAndMagic(*(int*)(self+16),record,object,0,0,0,flag);return record;
}
