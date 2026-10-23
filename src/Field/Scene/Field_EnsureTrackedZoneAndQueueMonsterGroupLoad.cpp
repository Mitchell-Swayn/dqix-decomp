#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
ARM
bool IsGrottoZone(int);
struct TrackedZone {
    unsigned short identifier;
    unsigned short group:2,unknown:2,groupValue:12;
    int unknown4,loadState;
    unsigned char unknownC;
    signed char grottoIndex;
    char unknownE[10];
    char entries[0x1c];
    int entryCount;
};
struct ZoneLoadCommand { unsigned short unknown0;unsigned char active,unknown3;unsigned unknown4;TrackedZone* zone;unsigned char unknownC[5];unsigned char mode;unsigned short value;unsigned char tail[4]; };
struct ZoneGroupValue {unsigned short identifier,value;};
extern "C" {
void* Network_GetConnectionManager(); void* ZoneState_GetTrackedZoneCache(); Zone3D* Zone3D_GetMainInstance();
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
int Network_GetLocalMemberId(void*); void GameState_ClearTrackedGroupsWithoutMatchingPartyIdentifier(void*);
void GameState_ResetAndHideUnflaggedFieldMonsterGroups(void*);
bool GameState_AllocateIndexedObjectGroup(void*,int);
void FieldMonster_CloneModelsForTrackedZoneOnHost(void*,int);
TrackedZone* ZoneState_FindTrackedZoneByIdentifier(void*,int);
int FindNearestEntryToFixedPointPosition(void*,const Vector3fix*);
void ZoneEncounterLoader_InitializeCommand(ZoneLoadCommand*);
void Filesystem_RemoveBackgroundTaskAndClearId(ZoneLoadCommand*);
void LinkedQueue_AppendAndMarkActive(void*,ZoneLoadCommand*);
void LinkedQueue_RemoveNodeAndResetStatus(void*,ZoneLoadCommand*);
}
#pragma force_active on
// Original: arm9/ov017 @ 0x0219DC90; symbol: func_ov017_0219dc90; size: 0x1E0.
// Ensures a tracked zone and queues its monster group, consuming any pending group override.
extern "C" void Field_EnsureTrackedZoneAndQueueMonsterGroupLoad(char* self,int member,int identifier,int mode,unsigned short value) {
    GameState* game=GameState::GetInstance();
    void* connection=Network_GetConnectionManager();
    void* cache=ZoneState_GetTrackedZoneCache();
    Zone3D_GetMainInstance();
    GameObject* object=GameState_GetObjectWithFlag100(game,member);
    if(Network_GetLocalMemberId(connection)) return;
    GameState_ClearTrackedGroupsWithoutMatchingPartyIdentifier(cache);
    GameState_ResetAndHideUnflaggedFieldMonsterGroups(self);
    if(!object) return;
    bool allocated=GameState_AllocateIndexedObjectGroup(cache,identifier);
    FieldMonster_CloneModelsForTrackedZoneOnHost(self,identifier);
    TrackedZone* zone=ZoneState_FindTrackedZoneByIdentifier(cache,identifier);
    ZoneGroupValue* pending=(ZoneGroupValue*)(self+0x44b4);
    if(zone) {
        int entry=zone->entryCount ? FindNearestEntryToFixedPointPosition(zone->entries,&object->obj3D_.position_) : 0;
        *(short*)((char*)object+0xb8)=entry;
        GrottoStruct* grotto=game->GetGrottoStruct();
        if(IsGrottoZone(identifier) && allocated) zone->grottoIndex=*(signed char*)((char*)grotto+8);
        zone->loadState=0;
        if(allocated) {
            if(pending->identifier==identifier) {
                zone->groupValue=pending->value;
                pending->identifier=0;pending->value=0;
            }
            ZoneLoadCommand* command=(ZoneLoadCommand*)(self+0x3a9c)+zone->group;
            if(!command->active) {
                ZoneEncounterLoader_InitializeCommand(command);
                command->zone=zone;command->mode=mode;command->value=value;
                LinkedQueue_AppendAndMarkActive(*(void**)(self+0x3704),command);
            } else {
                Filesystem_RemoveBackgroundTaskAndClearId(command);
                LinkedQueue_RemoveNodeAndResetStatus(*(void**)(self+0x3704),command);
                ZoneEncounterLoader_InitializeCommand(command);
                command->zone=zone;command->mode=mode;command->value=value;
                LinkedQueue_AppendAndMarkActive(*(void**)(self+0x3704),command);
            }
        } else *((unsigned char*)object+0xc2)|=0x40;
    }
    if(pending->identifier==identifier) {pending->identifier=0;pending->value=0;}
}
#pragma force_active off
