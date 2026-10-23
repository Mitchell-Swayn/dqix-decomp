#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
ARM
struct BattleDisplay {unsigned char bytes[4];};
extern "C" {
Zone3D* Zone3D_GetMainInstance();
int FieldBattle_GetLifecyclePhase(BattleDisplay*);
void* FieldBattle_GetEncounterRequest(BattleDisplay*);
int Field_GetCombatantAppearanceFlags(void*,int);
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
int GameResources_GetMaskedTertiaryFlags(void*,unsigned);
int PartySelection_GetMemberMask(void*,unsigned char);
void Field_DrawPartyMemberAndEquipment(void*,int);
int GameObject_IsPartyRenderingSuppressed(GameObject*);
bool Object3D_DrawWithTemporaryHeightAndCameraDisplacement(GameObject*,int,int);
void Graphics_RenderPartyMemberShadow(int);
}
#pragma force_active on
// Original: arm9/ov017 @ 0x0218E8C8; symbol: func_ov017_0218e8c8; size: 0x234.
// Filters party members by zone, render pass, battle selection and grotto appearance, then draws them.
extern "C" void Field_DrawPartyMembersForZone(char* self,int zoneId,int pass) {
    GameState* game=GameState::GetInstance();
    Zone3D* zone=Zone3D_GetMainInstance();
    bool grotto=false;
    if(zone->state_840_.IsValueInRangeC3b5(zoneId)) grotto=true;
    void* request=0;
    if(((*(BattleDisplay**)(self+0x3718))->bytes[3] && !FieldBattle_GetLifecyclePhase(*(BattleDisplay**)(self+0x3718))) ||
       ((*(BattleDisplay**)(self+0x3b30))->bytes[3] && (*(BattleDisplay**)(self+0x3718))->bytes[2]))
        request=FieldBattle_GetEncounterRequest(*(BattleDisplay**)(self+0x3718));
    int grottoAppearance=9032;
    for(int i=0;i<4;++i) {
        unsigned char appearance=Field_GetCombatantAppearanceFlags(self,i)|2;
        if(pass==1) { if(appearance) continue; }
        else if(pass==2 && !appearance) continue;
        bool skip=false;
        GameObject* object=GameState_GetObjectWithFlag100(game,i);
        GameObject* model=game->GetGameObjectByIndex(i*12+20);
        if(!object) continue;
        if(!GameResources_GetMaskedTertiaryFlags(self,2) && !object->obj3D_.GetFlag(0x800000)) {
            if(zoneId!=object->obj3D_.GetField06()) continue;
        } else if(GameResources_GetMaskedTertiaryFlags(self,4) && zoneId!=object->obj3D_.GetField06()) continue;
        if(request && !PartySelection_GetMemberMask(request,(unsigned char)i)) continue;
        if(grotto && model) {
            if(model->obj3D_.unknown_2_==grottoAppearance-1 || model->obj3D_.unknown_2_==grottoAppearance || model->obj3D_.unknown_2_==grottoAppearance+1) skip=true;
        }
        if(!skip) Field_DrawPartyMemberAndEquipment(self,i);
    }
    GameObject* extra=game->GetPartyMemberByIndex(206);
    if(extra && !GameObject_IsPartyRenderingSuppressed(extra) && Object3D_DrawWithTemporaryHeightAndCameraDisplacement(extra,1,0))
        Graphics_RenderPartyMemberShadow(206);
}
#pragma force_active off
