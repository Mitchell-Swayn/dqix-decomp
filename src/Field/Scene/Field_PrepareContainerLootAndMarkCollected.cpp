#include <globaldefs.h>
ARM
#include <World/Zone3D.h>
#include <World/LootableContainer.h>
struct ContainerLootAction {
    unsigned char unknown00, complete; char unknown02[0x10-2];
    unsigned short containerIndex, lootValue; char unknown14[8];
    void* object; char unknown20[4]; LootableContainerManager::Container* container; char unknown28[4];
    Vector3i position; char unknown38[4]; void* context;
};
struct ResetContainerAllocator : SafeAllocator { ResetContainerAllocator() { ResetAllocatorPointer(); } };
struct ContainerLootRequest { ResetContainerAllocator allocator; ZoneState2754 state; ZoneState2754* source; unsigned unknown30,unknown34; };
extern "C" {
Zone3D* Zone3D_GetMainInstance();
char* GameState_GetSerializedProgressState();
int BitArray_ReadNonnegativeIndexMask(void*,const void*,int);
void GameObject_RequestMovementInputEnable(void*);
void Memory_DestroyTwoAllocatorsAndRestoreGameFlags(ContainerLootAction*);
void World_ResetZoneStateAndClearThreeWords(ContainerLootRequest*);
void Text_FormatModeDependentKeyResourceResult(ContainerLootRequest*,int,int,void*,int);
void Field_MarkContainerBrokenAndLootCollected(int,int,int);
void Field_QueueContainerLootFlags(int,int,int);
void* GameResources_GetInstance();
void GameResources_SetSecondaryFlags(void*,unsigned);
}
#pragma force_active on
// Original: arm9/ov017 @ 0x021B5AEC; symbol: func_ov017_021b5aec; size: 0x19C.
// Looks up uncollected container loot, prepares its result and records collection flags.
extern "C" int Field_PrepareContainerLootAndMarkCollected(ContainerLootAction* action) {
    Zone3D* zone = Zone3D_GetMainInstance();
    char* progress = GameState_GetSerializedProgressState();
    LootableContainerManager* manager = LootableContainerManager::GetMainInstance();
    ZoneContainerRenderEntry* entry = zone->GetContainerRenderEntry(action->containerIndex);
    if (!manager || !progress || !entry) {
        GameObject_RequestMovementInputEnable(action->object);
        Memory_DestroyTwoAllocatorsAndRestoreGameFlags(action);
        action->complete=1;
        return 6;
    }
    action->position.x=entry->mainPart.position.x;
    action->position.y=entry->mainPart.position.y;
    action->position.z=entry->mainPart.position.z;
    int collected=1;
    int prepared=0;
    int identifier=0;
    unsigned short listPosition=0;
    LootableContainerManager::Container* container=manager->GetContainerByID(entry->containerID,&listPosition);
    if (container) {
        identifier=container->uniqueID;
        collected=BitArray_ReadNonnegativeIndexMask(progress,progress+0x8c,identifier+0x79e);
        if (!collected) {
            action->container=container;
            if (container->lootType) {
                prepared=1;
                ContainerLootRequest request;
                World_ResetZoneStateAndClearThreeWords(&request);
                World_ResetZoneStateAndClearThreeWords(&request);
                request.source=&zone->state_2754_;
                Text_FormatModeDependentKeyResourceResult(&request,container->lootType,container->itemIDOrRank,action->context,1);
                action->lootValue=container->itemIDOrRank;
            }
        }
    }
    Field_MarkContainerBrokenAndLootCollected(zone->currentZoneID_,action->containerIndex,identifier);
    Field_QueueContainerLootFlags(zone->currentZoneID_,action->containerIndex,identifier);
    if (!collected && prepared) {
        GameResources_SetSecondaryFlags(GameResources_GetInstance(),0x40);
        return 1;
    }
    GameObject_RequestMovementInputEnable(action->object);
    Memory_DestroyTwoAllocatorsAndRestoreGameFlags(action);
    action->complete=1;
    return 6;
}
#pragma force_active off
