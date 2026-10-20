#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(int,int);extern "C" int CombatantState_CanApplyEerieLight(char*);extern "C" void CombatantState_ActivateEerieLight(unsigned char*);extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);extern "C" void Combat_SuppressMessageForExceptionalOutcome(void*,void*,unsigned short*);extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,int,int,int);
struct Packed{unsigned a:10;unsigned b:10;unsigned c:10;unsigned d:2;};struct Flag{unsigned char low:7;unsigned char enabled:1;};
// Original: arm9/ov024 @ 0x021E1218; symbol: Combat_CreateLinkedRecordUsingConditionalAction; size: 0x110.
extern "C" void* Combat_ApplyEerieLightAndBuildResult(char* self,int unused,int index,char* entry,int unused4,int unused5,unsigned char update){
char* object=_Z16GetCombatantByIDii(*(int*)(self+16),index);if(!object)return 0;unsigned short id=0;
if(CombatantState_CanApplyEerieLight(*(char**)(object+0x138))&&update){CombatantState_ActivateEerieLight(*(unsigned char**)(object+0x138));id=Combat_SelectMessageForPartyOrMonster(index,((Packed*)(entry+32))->c,((Packed*)(entry+36))->a);}else id=Combat_SelectMessageForPartyOrMonster(index,((Packed*)(entry+36))->b,((Packed*)(entry+36))->c);
void* record=Combat_ClearCurrentResultNodeSlot(*(unsigned char**)(self+16));if(!record)return 0;Combat_SuppressMessageForExceptionalOutcome(self,*(void**)(self+12),&id);Combat_AppendResultMessage(*(void**)(self+16),record,id);bool flag=((Flag*)(*(char**)(self+12)+28))->enabled;Combat_PopulateResultWithCurrentHealthAndMagic(*(void**)(self+16),record,object,0,0,0,flag);return record;
}
