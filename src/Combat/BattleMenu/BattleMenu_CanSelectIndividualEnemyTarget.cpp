#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" char* GameObject_GetLinkedActionDataWhenEnabled(char*);
extern "C" int BattleMenu_CountEnemyTargetGroups(void*);
struct Flags { unsigned a:1; unsigned b:1; unsigned rest:30; };
// Original data: arm9/ov000 @ 0x2184294; symbol: data_ov000_02184294.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov000 @ 0x0217C2A0; symbol: HasLinkedObjectOrGlobalOverride; size: 0x8c.
// Tests linked object's two status bits and the global override word.
extern "C" int BattleMenu_CanSelectIndividualEnemyTarget(char* p) {
 int result=0;
 char* obj=(char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),*(int*)(p+0x4c));
 if(obj) {
  char* linked=GameObject_GetLinkedActionDataWhenEnabled(obj);
  if(linked && *(short*)(linked+0x18)>0) {
   Flags* flags=(Flags*)(*(char**)(obj+0x150)+0x2f4);
   if (flags->b) result=1;
   else if (flags->a) { if(BattleMenu_CountEnemyTargetGroups(*(void**)(BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage+8))==1) result=1; }
  }
  if(*(int*)BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage==1) result=1;
 }
 return result;
}
