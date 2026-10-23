#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <World/Zone3D.h>
struct RegionTriggerResult { unsigned words[13]; };
extern "C" {
Zone3D* Zone3D_GetMainInstance();
void* GameState_GetSerializedProgressState();
int ZoneFeatures_TestPointInsideEntry(ZoneFeatures::Opcode6aEntry*,const Vector3fix*);
ZoneFeatures::Opcode6aEntry* GameObject_GetActionContextValue(GameObject*);
void GameObject_SetActionContextValue(GameObject*,ZoneFeatures::Opcode6aEntry*);
bool Script_ExecuteFirstSatisfiedTriggerGroup(void*,int,RegionTriggerResult*);
void Script_DispatchResultCommandsToWorld(RegionTriggerResult*);
}
#pragma force_active on
// Original: arm9/ov017 @ 0x0219814C; symbol: func_ov017_0219814c; size: 0x160.
// Dispatches leave and enter scripts when the leader's containing type-three region changes.
extern "C" void Field_DispatchZoneRegionEnterAndLeaveTriggers() {
    GameState* game = GameState::GetInstance();
    Zone3D* zone = Zone3D_GetMainInstance();
    void* progress = GameState_GetSerializedProgressState();
    GameObject* leader = game->GetUnknownGameObject();
    Vector3fix position = leader->obj3D_.position_;
    ZoneFeatures::Opcode6aEntry* current = zone->bFeatures_.GetTypeEntries(3);
    for (; current; current = current->pNext) {
        if (ZoneFeatures_TestPointInsideEntry(current,&position)) break;
    }
    ZoneFeatures::Opcode6aEntry* previous = GameObject_GetActionContextValue(leader);
    RegionTriggerResult result;
    if (previous) {
        if (!current) {
            result.words[1] = previous->unk_2c.type3.unk_0;
            if (Script_ExecuteFirstSatisfiedTriggerGroup(progress,5,&result)) Script_DispatchResultCommandsToWorld(&result);
        } else if (current != previous) {
            result.words[1] = previous->unk_2c.type3.unk_0;
            if (Script_ExecuteFirstSatisfiedTriggerGroup(progress,5,&result)) Script_DispatchResultCommandsToWorld(&result);
            result.words[12] = 0;
            result.words[1] = current->unk_2c.type3.unk_0;
            if (Script_ExecuteFirstSatisfiedTriggerGroup(progress,2,&result)) Script_DispatchResultCommandsToWorld(&result);
        }
    } else if (current) {
        result.words[1] = current->unk_2c.type3.unk_0;
        if (Script_ExecuteFirstSatisfiedTriggerGroup(progress,2,&result)) Script_DispatchResultCommandsToWorld(&result);
    }
    GameObject_SetActionContextValue(leader,current);
}
#pragma force_active off
