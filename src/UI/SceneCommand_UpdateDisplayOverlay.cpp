#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Resource/GameResources.h>
ARM
extern "C" {
unsigned Memory_ReadMaximumAlignedAllocation(char *p);
void *AllocatorUnion_AllocateFourByteAligned(AllocatorUnion *a, unsigned size);
int Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned size);
void FileCache_RestoreRomTablesIfSpaceAvailable();
void OverlayLoader_PushPrimarySelection(unsigned int index);
void Town_InitializeDestinationMenu(unsigned char *p);
void Town_AllocateDestinationMenuResources(unsigned char *self, void *allocator);
struct Object {
    unsigned char pad[0xc1];
};
void GameObject_DisableMovementInput(Object *p, int reset);
void *GameState_GetFieldOrbitCamera(GameState *state);
void Camera_DisableOrbitInput(int param_1);
void GameResources_SetSecondaryFlags(int self, unsigned int mask);
int Town_UpdateDestinationMenu(char *self);
int Field_IsHostDisconnectPending();
void GameState_ResetResourcesAndApplyModeTwoCompletion(unsigned char *p);
void CleanupOverlayObjectAndOwnedAllocator(unsigned char *object);
void GameObject_RequestMovementInputEnable(int param_1);
void Camera_EnableOrbitInput(int param_1);
void Camera_ClearFollowControlFlags(unsigned char *p, unsigned char mask);
void GameResources_ClearSecondaryFlags(int self, unsigned int mask);
extern AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;
}

// Original: arm9/main @ 0x020DAC94; symbol: func_020dac94; size: 0x174.
// Advances the display-overlay scene command: allocate overlay 3 destination menu, poll it, or restore field controls.
extern "C" void SceneCommand_UpdateDisplayOverlay(unsigned char *p)
{
    GameState *game = GameState::GetInstance();
    unsigned state = *(unsigned *)(p + 0x10);
    if (state == 0) {
        GameResources_SetSecondaryFlags((int)GameResources_GetInstance(), 0xc0);
        if (Memory_ReadMaximumAlignedAllocation((char *)&Main_UnknownRoleZeroInitializedStorage_Variant3) < 0x6000)
            Filesystem_FreeCachedTableIfAllocationNeedsSpace(0x6000);
        void *buffer = AllocatorUnion_AllocateFourByteAligned(
            &Main_UnknownRoleZeroInitializedStorage_Variant3, 0x6000);
        if (buffer == 0) {
            FileCache_RestoreRomTablesIfSpaceAvailable();
            p[1] = 1;
            return;
        }
        ((SafeAllocator *)(p + 0x14))->CreateTypeA(buffer, 0x6000);
        ((SafeAllocator *)(p + 0x14))->Reset();
        if ((*(void **)(p + 0xc) = ((SafeAllocator *)(p + 0x14))->Allocate(0xe4)) == 0) {
            FileCache_RestoreRomTablesIfSpaceAvailable();
            p[1] = 1;
            return;
        }
        OverlayLoader_PushPrimarySelection(3);
        Town_InitializeDestinationMenu((unsigned char *)*(void **)(p + 0xc));
        Town_AllocateDestinationMenuResources((unsigned char *)*(void **)(p + 0xc), p + 0x14);
        GameObject_DisableMovementInput((Object *)game->GetUnknownGameObject(), 1);
        Camera_DisableOrbitInput((int)GameState_GetFieldOrbitCamera(game));
        *(unsigned *)(p + 0x10) = 1;
        return;
    }
    if (state == 1) {
        if (Town_UpdateDestinationMenu((char *)*(void **)(p + 0xc)) == 0)
            *(unsigned *)(p + 0x10) = 2;
        if (Field_IsHostDisconnectPending() == 0)
            return;
        GameState_ResetResourcesAndApplyModeTwoCompletion(p);
        *(unsigned *)(p + 0x10) = 3;
        return;
    }
    if (state != 2)
        return;
    CleanupOverlayObjectAndOwnedAllocator(p);
    GameObject_RequestMovementInputEnable((int)game->GetUnknownGameObject());
    int camera = (int)GameState_GetFieldOrbitCamera(game);
    Camera_EnableOrbitInput(camera);
    Camera_ClearFollowControlFlags((unsigned char *)camera, 2);
    GameResources_ClearSecondaryFlags((int)GameResources_GetInstance(), 0xc0);
    *(unsigned *)(p + 0x10) = ~0u;
}
