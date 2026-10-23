#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
struct AppearanceTintState { unsigned char unknown0, value1, unknown2, value3; };
struct FieldAppearanceState { char unknown0000[0x3b50]; AppearanceTintState* tint; };
extern "C" {
int _ZNK8Object3D10GetField06Ev(const Object3D*);
void* SystemState_GetGlobalFlags();
int SystemState_TestAnyFlags(void*,unsigned);
unsigned Field_GetCombatantAppearanceFlags(FieldAppearanceState*,int);
void Field_SetCombatantAlphaAndPaletteTint(FieldAppearanceState*,int,unsigned short,unsigned char,unsigned short);
void Graphics_SetPolygonIdForPartyObjectGroup(FieldAppearanceState*,int,int);
void GameState_ApplyIndexedObjectSlotValues(FieldAppearanceState*,int);
void Field_RestoreCombatantAppearance(FieldAppearanceState*,int);
unsigned char* GameState_GetIndexedByteField(FieldAppearanceState*,int);
}
#pragma force_active on
// Original: arm9/ov017 @ 0x02191CC0; symbol: func_ov017_02191cc0; size: 0x19C.
// Applies queued appearance flags for combatants belonging to the protagonist's owner.
extern "C" void Field_ApplyDirtyCombatantAppearances(FieldAppearanceState* field) {
    if (SystemState_TestAnyFlags(SystemState_GetGlobalFlags(),0x20000)) return;
    GameState* game = GameState::GetInstance();
    GameObject* protagonist = game->GetProtagonist();
    if (!protagonist) return;
    unsigned short owner = _ZNK8Object3D10GetField06Ev(&protagonist->obj3D_);
    for (int index = 0; index <= 199; ++index) {
        unsigned flags = Field_GetCombatantAppearanceFlags(field,index);
        if (!(flags & 1)) continue;
        GameObject* object = game->GetGameObjectByIndex(index);
        if (object && owner != _ZNK8Object3D10GetField06Ev(&object->obj3D_)) continue;
        int flag4 = flags & 4;
        int flag2 = flags & 2;
        if (flag4 && flag2) {
            Field_SetCombatantAlphaAndPaletteTint(field,index,0x999,1,0x65ff);
            Graphics_SetPolygonIdForPartyObjectGroup(field,index,8);
        } else if (flag4) {
            Field_SetCombatantAlphaAndPaletteTint(field,index,0x1000,0,0x282f);
            GameState_ApplyIndexedObjectSlotValues(field,index);
        } else if (flag2) {
            unsigned short alpha = 0x999;
            AppearanceTintState* tint = field->tint;
            if (tint->value3 && !tint->value1) alpha = 0x1000;
            Field_SetCombatantAlphaAndPaletteTint(field,index,alpha,1,0x79e8);
            Graphics_SetPolygonIdForPartyObjectGroup(field,index,8);
        } else {
            Field_RestoreCombatantAppearance(field,index);
            GameState_ApplyIndexedObjectSlotValues(field,index);
        }
        unsigned char* stored = GameState_GetIndexedByteField(field,index);
        if (stored) *stored &= ~1;
    }
}
#pragma force_active off
