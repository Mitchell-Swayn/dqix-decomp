#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
#include <World/ZonePredicates.h>
ARM
extern "C" {
void* ZoneState_GetTrackedZoneCache();
char* GetBoundedEntryAtStride318(void*,int);
char* ZoneState_FindTrackedZoneByIdentifier(void*,int);
void* Network_GetConnectionManager();
int Network_IsParentOrOffline(void*);
int Network_IsSessionActive(void*);
Zone3D* Zone3D_GetMainInstance();
void FieldMonster_UpdateTimersAndBehavior(GameObject*);
void Object3D_InitializeExtendedMovementStateDefaults(GameObject*);
void Field_QueueMonsterHideRequest(int,int,int,int);
Vector3fix GameObject_GetAuthorityPosition(GameObject*);
bool Bounds3D_ContainsPoint(const Vector3fix*,const void*);
}
struct CullZoneHeader {unsigned short id;unsigned short group:2,active:1,reserved:13;};
struct MonsterCullBounds {Vector3fix maximum,minimum;};
#pragma always_inline on
static inline int IsDistantFromAllMembers(int index) {
    GameState* game=GameState::GetInstance();
    GameObject* monster=game->GetMaybeFieldMonsterByIndex(index);
    if(!monster)return 0;
    Vector3fix point=monster->obj3D_.position_;
    for(int i=0;i<4;++i) {
        GameObject* object=game->GetMaybeWanderingMonsterByIndex(i);
        if(object && object->obj3D_.GetField06()==monster->obj3D_.GetField06()) {
            Vector3fix position=GameObject_GetAuthorityPosition(object);
            MonsterCullBounds bounds;
            bounds.maximum=position;
            bounds.maximum.x+=0x19000;bounds.maximum.y+=0x19000;bounds.maximum.z+=0x19000;
            bounds.minimum=position;
            bounds.minimum.x-=0x19000;bounds.minimum.y-=0x19000;bounds.minimum.z-=0x19000;
            if(Bounds3D_ContainsPoint(&point,&bounds))return 0;
        }
    }
    return 1;
}

#pragma force_active on
// Original: arm9/ov017 @ 0x021A1AD0; symbol: func_ov017_021a1ad0; size: 0x2C8.
// Updates active zone groups and hides eligible monsters outside every member's culling box.
extern "C" void FieldMonster_UpdateVisibleGroupsAndCullDistantMonsters() {
    GameState* game=GameState::GetInstance();
    void* cache=ZoneState_GetTrackedZoneCache();
    void* network=Network_GetConnectionManager();
    Zone3D* zone=Zone3D_GetMainInstance();
    if(Network_IsParentOrOffline(network)) {
        int base;
        for(int group=0;group<4;++group) {
            char* record=GetBoundedEntryAtStride318(cache,group);
            if(((CullZoneHeader*)record)->active) {
                base=group*12+0x70;
                int reason=-1;
                for(int i=0;i<12;++i) {
                    GameObject* monster=game->GetMaybeFieldMonsterByIndex(i+base);
                    if(!monster || !monster->obj3D_.IsVisible())continue;
                    FieldMonster_UpdateTimersAndBehavior(monster);
                    int eligible=1;
                    unsigned char flags=*((unsigned char*)monster+0x17d);
                    if((flags&2)||(flags&4)||IsGrottoBossFloorZone(zone->currentZoneID_))eligible=0;
                    if(*((unsigned char*)monster+0x17d)&8)eligible=0;
                    if(eligible && IsDistantFromAllMembers(i+base) && *(int*)((char*)monster+0x130)!=8 && *(int*)((char*)monster+0x130)!=9) {
                        Object3D_InitializeExtendedMovementStateDefaults(monster);
                        monster->obj3D_.MakeHidden();
                        if(Network_IsSessionActive(network) && record)
                            Field_QueueMonsterHideRequest(*(unsigned short*)record,i,monster->obj3D_.unknown_2_,reason);
                    }
                }
            }
        }
    } else {
        char* record=ZoneState_FindTrackedZoneByIdentifier(cache,zone->currentZoneID_);
        if(record)for(int i=0;i<12;++i) {
            GameObject* monster=game->GetMaybeFieldMonsterByIndex(i+(((CullZoneHeader*)record)->group*12+0x70));
            if(monster && monster->obj3D_.IsVisible())FieldMonster_UpdateTimersAndBehavior(monster);
        }
    }
}
#pragma force_active off
