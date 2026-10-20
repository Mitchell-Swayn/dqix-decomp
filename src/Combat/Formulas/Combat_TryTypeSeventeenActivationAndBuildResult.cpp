#include <globaldefs.h>
ARM
struct Flags {unsigned char low:7;unsigned char flag:1;};extern "C" {void* _Z16GetCombatantByIDii(void*,int);int Combat_TryActivateMonsterReactionByActionType(void*,int,int,unsigned);void Combat_QueueForcedTargetReaction(void*,int);void* Combat_ClearCurrentResultNodeSlot(void*);void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,int,int,int);}
// Original: arm9/ov024 @ 0x021E0B48; symbol: ClearAndConfigureCurrentCombatantRecord; size: 0xac.
// Finds combatant, optionally activates index and configures cleared record using descriptor high bit.
extern "C" void* Combat_TryTypeSeventeenActivationAndBuildResult(char* self,int party,int index){void* target=_Z16GetCombatantByIDii(*(void**)(self+16),index);if(!target)return 0;if(Combat_TryActivateMonsterReactionByActionType(self,party,index,17))Combat_QueueForcedTargetReaction(*(void**)(self+16),index);void* record=Combat_ClearCurrentResultNodeSlot(*(void**)(self+16));if(!record)return 0;int flag=((Flags*)(*(char**)(self+12)+28))->flag?1:0;Combat_PopulateResultWithCurrentHealthAndMagic(*(void**)(self+16),record,target,0,0,0,flag);return record;}
