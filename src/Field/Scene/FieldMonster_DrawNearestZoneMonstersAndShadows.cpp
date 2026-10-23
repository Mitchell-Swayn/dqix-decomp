#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
ARM
struct DrawZoneHeader {unsigned short id;unsigned short group:2,active:1,reserved:13;};
#pragma always_inline on
struct MonsterDistance { int distance;unsigned char selected;MonsterDistance():distance(0x270f000),selected(0){} };
extern "C" {
void _ZNK8Object3D8GetScaleEv(Vector3fix*,const Object3D*);
void _ZNK8Object3D23GetShadowSourcePositionEv(Vector3fix*,const Object3D*);
void* ZoneState_GetTrackedZoneCache();
char* ZoneState_FindTrackedZoneByIdentifier(void*,int);
Zone3D* Zone3D_GetMainInstance();
int GameResources_GetMaskedSecondaryFlags(void*,unsigned);
int DrawVisibleObjectWithOptionalOverlayPosition(GameObject*,int);
int GameObject_IsMovementPauseActive(GameObject*);
int Vector3fix_Distance(const Vector3fix*,const Vector3fix*);
void Graphics_RenderPresentModelWithDiffuseColorAndScale(Vector3fix*,unsigned,int,int,int);
}
#pragma force_active on
// Original: arm9/ov017 @ 0x021A1D98; symbol: func_ov017_021a1d98; size: 0x2C4.
// Selects the nearest visible monsters within the zone's model budget and draws their shadows.
extern "C" void FieldMonster_DrawNearestZoneMonstersAndShadows(void* self,int zoneID) {
    GameState* game=GameState::GetInstance();
    char* record=ZoneState_FindTrackedZoneByIdentifier(ZoneState_GetTrackedZoneCache(),zoneID);
    if(!record)return;
    Zone3D* zone=Zone3D_GetMainInstance();
    unsigned short shadowModel=*(unsigned short*)((char*)zone+0x38);
    unsigned shadowAlpha=*(unsigned*)((char*)zone+0x3c);
    int overlay=1;
    if(GameResources_GetMaskedSecondaryFlags(self,0x1000))overlay=0;
    int members=0;
    for(int i=0;i<4;++i) {
        GameObject* object=game->GetPartyMemberByIndex(i);
        if(object && zoneID==object->obj3D_.GetField06())++members;
    }
    int budget=7-members;
    Vector3fix origin=game->GetUnknownGameObject()->obj3D_.position_;
    MonsterDistance distances[12];
    for(int i=0;i<12;++i) {
        GameObject* object=game->GetMaybeFieldMonsterByIndex(i+(((DrawZoneHeader*)record)->group*12+0x70));
        if(object && object->obj3D_.IsVisible()) {
            Vector3fix position=object->obj3D_.position_;
            distances[i].distance=Vector3fix_Distance(&origin,&position);
        }
    }
    int distance;
    for(int i=0;i<budget;++i) {
        int nearest=-1;
        distance=0x270f000;
        for(int j=0;j<12;++j)if(!distances[j].selected && distances[j].distance<=distance){distance=distances[j].distance;nearest=j;}
        if(nearest!=-1)distances[nearest].selected=1;
    }
    for(int i=0;i<12;++i)if(distances[i].selected) {
        GameObject* object=game->GetMaybeFieldMonsterByIndex(i+(((DrawZoneHeader*)record)->group*12+0x70));
        if(object && object->obj3D_.IsVisible() && DrawVisibleObjectWithOptionalOverlayPosition(object,overlay) && !GameObject_IsMovementPauseActive(object)) {
            int alpha=object->obj3D_.GetCombinedAlpha();
            int diffuse=(int)(((float)shadowAlpha/31.0f)*(float)alpha);
            char* data=*(char**)((char*)object+0x180);
            int factor=data?*(short*)(data+0x12):0x1000;
            Vector3fix position,scale;_ZNK8Object3D8GetScaleEv(&scale,&object->obj3D_);
            int radius=(int)(((long long)factor*(scale.x*15)+0x800)>>12);
            _ZNK8Object3D23GetShadowSourcePositionEv(&position,&object->obj3D_);
            Graphics_RenderPresentModelWithDiffuseColorAndScale(&position,shadowModel,radius,diffuse,8);
        }
    }
}
#pragma force_active off
