#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma force_active on
ARM
struct State { int pad[12]; int count; };
struct DynamicRegion {
    unsigned short identifier;
    short angle;
    Vector3fix position;
    int scale;
    Vector3fix bounds;
    char unknown_20[12];
    DynamicRegion* next;
};
extern "C" void* GameState_GetSerializedProgressState();
extern "C" int Bounds3D_ContainsPointWithInverseYaw(const Vector3fix*, const Vector3fix*, int, const Vector3fix*, int);
extern "C" bool Script_ExecuteFirstSatisfiedTriggerGroup(void*, int, State*);
extern "C" void Script_DispatchResultCommandsToWorld(State*);
// Original: arm9/ov017 @ 0x02198E30; symbol: func_ov017_02198e30; size: 0x140.
// Dispatches leave/enter trigger groups when the leader's containing dynamic region changes.
extern "C" void Field_DispatchDynamicRegionEnterAndLeaveTriggers(void* context)
{
    unsigned char* owner = (unsigned char*)context;
    GameState* game = GameState::GetInstance();
    unsigned char* progress = (unsigned char*)GameState_GetSerializedProgressState();
    DynamicRegion* region = *(DynamicRegion**)(progress + 0x494);
    GameObject* actor = game->GetUnknownGameObject();
    while (region) {
        if (Bounds3D_ContainsPointWithInverseYaw((Vector3fix*)((unsigned char*)actor + 0x44), &region->bounds, region->angle, &region->position, region->scale)) break;
        region = region->next;
    }
    int previous = *(signed char*)(progress + 0x491);
    if (!region) {
        if (previous > -1) {
            State result;
            result.pad[1] = previous;
            if (Script_ExecuteFirstSatisfiedTriggerGroup(progress, 5, &result)) Script_DispatchResultCommandsToWorld(&result);
            *(signed char*)(progress + 0x491) = -1;
        }
    } else if (region->identifier != previous) {
        State result;
        if (previous > -1) {
            result.pad[1] = previous;
            if (Script_ExecuteFirstSatisfiedTriggerGroup(progress, 5, &result)) Script_DispatchResultCommandsToWorld(&result);
            result.pad[1] = -1;
            result.count = 0;
        }
        owner[0x4446] = region->identifier;
        result.pad[1] = region->identifier;
        if (Script_ExecuteFirstSatisfiedTriggerGroup(progress, 2, &result)) Script_DispatchResultCommandsToWorld(&result);
        int identifier = region->identifier;
        ((unsigned char*)GameState_GetSerializedProgressState())[0x491] = identifier;
    }
}
