#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
struct OverlayThreePanelTransition {
    unsigned char unknown00, complete; char unknown02[6]; int phase;
    SafeAllocator allocator; void* panel;
};
extern "C" {
GameResources* GameResources_GetInstance();
void* GameState_GetFieldOrbitCamera(GameState*);
void GameResources_SetSecondaryFlags(GameResources*,unsigned);
void GameResources_ClearSecondaryFlags(GameResources*,unsigned);
void GameObject_DisableMovementInput(GameObject*,int);
void GameObject_RequestMovementInputEnable(GameObject*);
void Camera_SetFollowControlFlags(void*,unsigned char);
void Camera_ClearFollowControlFlags(void*,unsigned char);
void Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned);
void FileCache_RestoreRomTablesIfSpaceAvailable();
extern AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;
void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
void OverlayLoader_PushPrimarySelection(int);
// These five loaded addresses identify ov003, selected immediately before use.
void Graphics_InitializeBackgroundCanvasAndDayState(void*);
void Memory_InitializeFiveAllocatorRegions(void*,SafeAllocator*);
void Inn_RequestStayDialogClose(void*);
int Inn_UpdateStayDialog(void*,int);
void Inn_ReleaseStayDialogResources(void*);
int Field_IsHostDisconnectPending();
void Overlay_DestroyAllocatorAndFreeSignedAllocation(OverlayThreePanelTransition*);
}
#pragma force_active on
// Original: arm9/ov017 @ 0x021BACD8; symbol: func_ov017_021bacd8; size: 0x1A8.
// Allocates, updates and releases the ov003 dialog while holding field movement and camera flags.
extern "C" void Field_AdvanceOverlayThreePanelTransition(OverlayThreePanelTransition* transition) {
    GameState* game=GameState::GetInstance();
    GameResources* resources=GameResources_GetInstance();
    GameObject* leader=game->GetUnknownGameObject();
    void* camera=GameState_GetFieldOrbitCamera(game);
    GameResources_SetSecondaryFlags(resources,0xc0);
    GameObject_DisableMovementInput(leader,1);
    Camera_SetFollowControlFlags(camera,3);
    int ticks=(int)game->GetTickCount();
    if(ticks<0) ticks=1;
    if(transition->phase==0) {
        Filesystem_FreeCachedTableIfAllocationNeedsSpace(0xf43c);
        void* buffer=AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3,0xf43c);
        if(!buffer) {
            FileCache_RestoreRomTablesIfSpaceAvailable();
            transition->complete=1;
            return;
        }
        transition->allocator.CreateTypeA(buffer,0xf43c);
        transition->allocator.Reset();
        transition->panel=transition->allocator.Allocate(0x3fc);
        if(!transition->panel) {
            FileCache_RestoreRomTablesIfSpaceAvailable();
            transition->complete=1;
            return;
        }
        OverlayLoader_PushPrimarySelection(3);
        Graphics_InitializeBackgroundCanvasAndDayState(transition->panel);
        Memory_InitializeFiveAllocatorRegions(transition->panel,&transition->allocator);
        ++transition->phase;
    } else if(transition->phase==1) {
        if(Field_IsHostDisconnectPending()) Inn_RequestStayDialogClose(transition->panel);
        if(Inn_UpdateStayDialog(transition->panel,ticks)) ++transition->phase;
    } else if(transition->phase==2) {
        Inn_ReleaseStayDialogResources(transition->panel);
        ++transition->phase;
    } else if(transition->phase==3) {
        Overlay_DestroyAllocatorAndFreeSignedAllocation(transition);
        GameResources_ClearSecondaryFlags(resources,0xc0);
        GameObject_RequestMovementInputEnable(leader);
        Camera_ClearFollowControlFlags(camera,3);
        FileCache_RestoreRomTablesIfSpaceAvailable();
        transition->complete=1;
    }
}
#pragma force_active off
