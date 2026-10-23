#include <globaldefs.h>
ARM
struct Descriptor {unsigned unknown[11];unsigned pad:10,index:4,rest:18;};
struct HandlerOwner {typedef void(HandlerOwner::*Handler)(int,Descriptor*,int);};
struct Slot {HandlerOwner::Handler handler;};
struct HandlerTable {Slot entries[11];};
extern "C" {
extern unsigned CombatDispatchSecondaryEffectHandler_UnknownRoleZeroInitializedStorage[2];
extern Slot ShopUpdateInterface_UnknownRoleInitializedBytes;
extern HandlerTable CombatDispatchPostActionEffectHandler_UnknownRoleProcedureReferenceRecords;
}
// Original: arm9/ov024 @ 0x021E6060; symbol: Combat_DispatchPostActionEffectHandler; size: 0xA4.
extern "C" void Combat_DispatchPostActionEffectHandler(HandlerOwner* self,int actor,Descriptor* action,int amount){
if(!(CombatDispatchSecondaryEffectHandler_UnknownRoleZeroInitializedStorage[1]&1)){
 Slot temporary=ShopUpdateInterface_UnknownRoleInitializedBytes;
 CombatDispatchPostActionEffectHandler_UnknownRoleProcedureReferenceRecords.entries[0]=temporary;
 CombatDispatchPostActionEffectHandler_UnknownRoleProcedureReferenceRecords.entries[7]=temporary;
 CombatDispatchSecondaryEffectHandler_UnknownRoleZeroInitializedStorage[1]|=1;
}
unsigned index=action->index;
if(index<11&&CombatDispatchPostActionEffectHandler_UnknownRoleProcedureReferenceRecords.entries[index].handler)
 (self->*CombatDispatchPostActionEffectHandler_UnknownRoleProcedureReferenceRecords.entries[index].handler)(actor,action,amount);
}
