#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
#include <Graphics/LightingManager.h>
ARM
struct OverlayTextState {char low[0x1000];unsigned char high[0x1000];};
struct OverlayFieldState {char low[0x3000];unsigned char high[0x1000];};
extern "C" {
char* TextContext_GetSharedInstance();
unsigned char* ColorAnimation_GetGlobalInstance();
void InterpolateValueToTargetByRemainingTime(void*);
void Graphics_InitializeGeometryAndDisplayState();
void Graphics_ResetGeometryMatrixStackState();
void G3_LookAt(const Vector3i*,const Vector3i*,const Vector3i*,int,void*);
void Geometry_BuildAndOptionallyApplyProjectionMatrix(int,int,int,int,int,int,int,int,void*);
void FieldCommandQueue_DrawFrontOverlay(void*);
int LinkedQueue_GetFrontKindOrInvalid(void*);
int GameResources_GetMaskedSecondaryFlags(void*,unsigned);
void TextWindow_DrawAndTransferOptionalWindow(void*);
void Field_DrawInteractionAndRemotePartyIndicators(void*);
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
void Graphics_DrawProjectedAttachedResource(GameObject*);
int GameObject_GetMovementInputEnabled(GameObject*);
int GameObject_GetLadderTraversalActive(GameObject*);
int ReadSelectedCoordinatePair(void*,int*,int*);
void TouchMovement_DrawIndicatorIfInputAllowed(void*);
void NavigationMessage_GetGlobalInstance();
void NavigationMessage_DrawForCurrentState();
Zone3D* Zone3D_GetMainInstance();
void Camera_UpdateFromGameStateFlags(void*);
void __clear(void*,unsigned);
// Original data: arm9/ov017 @ 0x021D6408/0x021D6414: look-at target and up vectors.
extern const Vector3i FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleInitializedBytes;
extern const Vector3i FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleInitializedBytes_Variant2;
// Original data: arm9/main @ 0x02114E54: coordinate input state.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original data: arm9/ov017 @ 0x021D8340..0x021D8350: coordinate latch and two coordinate pairs.
extern int FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleZeroInitializedStorage;
extern int FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleZeroInitializedStorage_Variant2;
extern int FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleZeroInitializedStorage_Variant3;
extern int FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleZeroInitializedStorage_Variant4;
extern int FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleZeroInitializedStorage_Variant5;
}
#pragma force_active on
// Original: arm9/ov017 @ 0x021960B8; symbol: func_ov017_021960b8; size: 0x2E0.
// Sets overlay projection and draws command windows, party indicators and atmospheric effects.
extern "C" void Field_DrawOverlayWindowsAndInteractionIndicators(char* self) {
    GameState* game=GameState::GetInstance();
    char* text=TextContext_GetSharedInstance();
    unsigned char* animation=ColorAnimation_GetGlobalInstance();
    GameObject* protagonist=game->GetUnknownGameObject();
    game->GetTickCount();
    Vector3i target=FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleInitializedBytes;
    Vector3i eye;__clear(&eye,12);
    Vector3i up=FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleInitializedBytes_Variant2;
    Graphics_InitializeGeometryAndDisplayState();
    Graphics_ResetGeometryMatrixStackState();
    *(volatile unsigned*)0x04000440=0;
    G3_LookAt(&eye,&up,&target,1,0);
    Geometry_BuildAndOptionallyApplyProjectionMatrix(0,0xc0000,0,0x100000,-0x400000,0x400000,0x400000,1,0);
    *(volatile unsigned*)0x04000440=2;
    FieldCommandQueue_DrawFrontOverlay(*(void**)(self+0x36fc));
    if(*animation)InterpolateValueToTargetByRemainingTime(animation);
    if(LinkedQueue_GetFrontKindOrInvalid(*(void**)(self+0x36fc))!=2 &&
       LinkedQueue_GetFrontKindOrInvalid(*(void**)(self+0x36fc))!=3 &&
       LinkedQueue_GetFrontKindOrInvalid(*(void**)(self+0x36fc))!=10) {
        if((*(int*)(text+0x998) || ((OverlayTextState*)text)->high[0x9cb]) && !GameResources_GetMaskedSecondaryFlags(self,0x8000))TextWindow_DrawAndTransferOptionalWindow(text);
        Field_DrawInteractionAndRemotePartyIndicators(self);
        if(!GameResources_GetMaskedSecondaryFlags(self,4))for(int i=0;i<4;++i) {
            GameObject* object=GameState_GetObjectWithFlag100(game,i);
            if(object && !object->obj3D_.GetFlag(1))Graphics_DrawProjectedAttachedResource(object);
        }
    }
    if(!GameResources_GetMaskedSecondaryFlags(self,0x800)) {
        LightingManager::GetInstance()->DrawBackgroundGradient();
    }
    if(!GameResources_GetMaskedSecondaryFlags(self,0x80) && !((OverlayFieldState*)self)->high[0x658] && protagonist &&
       (GameObject_GetMovementInputEnabled(protagonist) || GameObject_GetLadderTraversalActive(protagonist))) {
        unsigned char* input=Main_UnknownRoleZeroInitializedStorage_Variant4;
        if(input[0x5f] && *(unsigned short*)(input+0x24)) {
            if(!FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleZeroInitializedStorage) {
                FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleZeroInitializedStorage=1;
                ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleZeroInitializedStorage_Variant2,&FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleZeroInitializedStorage_Variant4);
            }
            ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleZeroInitializedStorage_Variant3,&FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleZeroInitializedStorage_Variant5);
        }else FieldDrawOverlayWindowsAndInteractionIndicators_UnknownRoleZeroInitializedStorage=0;
        TouchMovement_DrawIndicatorIfInputAllowed(*(void**)(self+0x4328));
    }
    NavigationMessage_GetGlobalInstance();NavigationMessage_DrawForCurrentState();
    if(Zone3D_GetMainInstance()->atmosphericEffects_.Draw())Camera_UpdateFromGameStateFlags(self);
}
#pragma force_active off
