#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
namespace {
struct CombatActionState { char prefix[8]; char* command; char padding[4]; unsigned char* combat; };
}
extern "C" int CombatStatus_CanRaiseTension(char*);
extern "C" void CombatStatus_EnterSuperHighTension(unsigned char*);
extern "C" void CombatStatus_SetOrdinaryTensionStage(char*,int);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
extern "C" void Combat_AppendActorResultToCategoryList(char*,void*,int);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E5EC4; symbol: func_ov024_021e5ec4; size: 0x19c.
// Raises the actor's tension, queues its transition result and marks a super-high transition on the command.
extern "C" void Combat_RaiseTensionOneStageAndQueueResult(CombatActionState* self,int actorId,void* unusedAction)
{
    GameObject* actor = GetCombatantByID((int)self->combat, actorId);
    if (!actor) return;
    if (!CombatStatus_CanRaiseTension((char*)actor->currentStats_)) return;
    int stage = ((unsigned char*)actor->currentStats_)[0x24];
    int message = 0;
    switch (stage + 1) {
    case 1: message = 0x31; break;
    case 2: message = 0x32; break;
    case 3: message = 0x33; break;
    case 4: message = 0x34; break;
    }
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return;
    unsigned long long mask = 0;
    if (stage + 1 >= 4) {
        CombatStatus_EnterSuperHighTension((unsigned char*)actor->currentStats_);
        Combat_SetResultMaskFlag(self->combat, &mask, 7);
        Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, actor, 0, mask, 0);
        Combat_AppendActorResultToCategoryList(self->command, result, 2);
        self->combat[0x8e02]++;
        self->command[0x2d] = 1;
    } else {
        CombatStatus_SetOrdinaryTensionStage((char*)actor->currentStats_, stage + 1);
        Combat_SetResultMaskFlag(self->combat, &mask, 35);
        Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, actor, (short)(stage + 1), mask, 0);
        Combat_AppendActorResultToCategoryList(self->command, result, 2);
        self->combat[0x8e02]++;
    }
    Combat_AppendResultMessage(self->combat, result, (unsigned short)message);
}
#pragma force_active reset
