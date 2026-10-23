#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
#include <World/LootableContainer.h>
#include <Filesystem/BackgroundLoader.h>
ARM
struct LootFileName { char text[32]; };
struct LootInteraction {char unknown0[0x2c];unsigned short zoneObject,zonePart,container;};
extern "C" {
Zone3D* Zone3D_GetMainInstance();
char* GameState_GetSerializedProgressState();
void Field_QueueZoneObjectStateReset(int,int,int);
unsigned BitArray_ReadNonnegativeIndexMask(void*,void*,int);
int GameState_ReadProtagonistObjectIndex(GameState*);
ZoneSerializedRecord* ZoneState2754_FindPrimaryRecordByKey(void*,int);
int ZoneSerializedRecord_GetPreferredAttribute(ZoneSerializedRecord*,int);
void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);

void Field_LoadSharedPresentationEffect(void*,SafeAllocator*);
int sprintf(char*,const char*,...);
// Original data: arm9/ov017 @ 0x021D6CA4 and 0x021D7EE8: sprite path templates.
extern LootFileName Field_BeginContainerLootPresentation_TextDataAniDI127Spr;
extern const char Field_BeginContainerLootPresentation_FormatDataAniDC03DSpr[];
// Original data: arm9/main @ 0x02114E20: presentation allocator storage; role partially known.
extern char Main_UnknownRoleZeroInitializedStorage_Variant3[];
}
#pragma force_active on
// Original: arm9/ov017 @ 0x021BF7AC; symbol: func_ov017_021bf7ac; size: 0x1F4.
// Resets the container and queues its loot sprite or the special presentation resource.
extern "C" int Field_BeginContainerLootPresentation(char* self) {
    GameState* game=GameState::GetInstance();
    game->GetUnknownGameObject();
    Zone3D* zone=Zone3D_GetMainInstance();
    LootInteraction* interaction=*(LootInteraction**)(self+0xc);
    BackgroundLoader* loader=BackgroundLoader::GetInstance();
    int object=interaction->zoneObject,part=interaction->zonePart;
    zone->RequestBMDJObjectStateReset(object,part);
    Field_QueueZoneObjectStateReset(zone->currentZoneID_,object,part);
    LootableContainerManager* manager=LootableContainerManager::GetMainInstance();
    char* progress=GameState_GetSerializedProgressState();
    if(!manager || !progress) return 3;
    unsigned short listIndex=0;
    LootableContainerManager::Container* container=manager->GetContainerByID(interaction->container,&listIndex);
    if(container && !BitArray_ReadNonnegativeIndexMask(progress,progress+0x8c,container->uniqueID+0x79e)) {
        Zone3D* current=Zone3D_GetMainInstance();
        ZoneState2754* records=&current->state_2754_;
        *(ZoneContainerRenderPart**)(self+0x10)=current->fragmentParts_+GameState_ReadProtagonistObjectIndex(game);
        (*(ZoneContainerRenderPart**)(self+0x10))->ResetIfFlag0();
        if(container->lootType==1) {
            LootFileName filename=Field_BeginContainerLootPresentation_TextDataAniDI127Spr;
            *(short*)(self+0x14)=loader->QueueLoadFile(filename.text,0);
        } else {
            ZoneSerializedRecord* record=ZoneState2754_FindPrimaryRecordByKey(records,(short)container->itemIDOrRank);
            if(record) {
                if(record->key==0x5617) {
                    *(unsigned char*)(self+0x48)=1;
                    SafeAllocator* allocator=(SafeAllocator*)(self+0x4c);
                    allocator->ResetAllocatorPointer();
                    void* buffer=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,0x4000);
                    allocator->CreateTypeA(buffer,0x4000);allocator->Reset();
                    Field_LoadSharedPresentationEffect(GameResources_GetInstance(),allocator);
                } else {
                    int attribute=ZoneSerializedRecord_GetPreferredAttribute(record,0);
                    char filename[128];
                    sprintf(filename,Field_BeginContainerLootPresentation_FormatDataAniDC03DSpr,(signed char)record->attributes.group,attribute);
                    *(short*)(self+0x14)=loader->QueueLoadFile(filename,0);
                }
            }
        }
    }
    *(short*)(self+8)=300;
    return 3;
}
#pragma force_active off
