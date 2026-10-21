#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Resource/GameResources.h>
#include <System/Memory.h>
ARM
extern "C" {
struct State;
void Graphics_CacheFourMainBackgroundControlsOnce(volatile State* p);
void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion* a, unsigned size);
int Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned size);
void FileCache_RestoreRomTablesIfSpaceAvailable();
void OverlayLoader_PushPrimarySelection(unsigned int index);
void InitializePresentationAndTransferControlDefaults(char* p);
void Inn_AllocateServiceMenuResources(char* self, SafeAllocator* allocator);
struct Object {
    unsigned char pad[0xc1];
};
void GameObject_DisableMovementInput(Object* p, int reset);
void* GameState_GetFieldOrbitCamera(GameState* state);
void Camera_DisableOrbitInput(int param_1);
void GameResources_SetSecondaryFlags(int self, unsigned int mask);
int Inn_UpdateServiceMenuState(char* p);
int Field_IsHostDisconnectPending();
void GameState_InitializeResourcesThenMarkOverlayRecord(void* object);
void Graphics_ReleaseSelectionResourcesAndClearMainBG(char* self);
void GameObject_RequestMovementInputEnable(int param_1);
void Camera_EnableOrbitInput(int param_1);
void Camera_ClearFollowControlFlags(unsigned char* p, unsigned char mask);
void GameResources_ClearSecondaryFlags(int self, unsigned int mask);
void Ov003_CompleteSelectionInitialization(void* object);
extern AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;
}

// Original: arm9/ov003 @ 0x0217EF58; symbol: func_ov003_0217ef58; size: 0x1c0.
// Allocates the inn service controller, copies launch mode, disables movement
// and orbit input, then restores them after the service menu finishes or a
// host disconnect forces shutdown.
extern "C" void Inn_UpdateServiceSceneLifecycle(char* self)
{
    GameState* game = GameState::GetInstance();
    unsigned state = *(unsigned*)(self + 0x10);
    if (state == 0) {
        Graphics_CacheFourMainBackgroundControlsOnce((volatile State*)(self + 0x2a));
        GameResources_SetSecondaryFlags((int)GameResources_GetInstance(), 0xc0);
        Filesystem_FreeCachedTableIfAllocationNeedsSpace(0x1e800);
        void* buffer = AllocatorUnion_AllocateFourByteAligned(
            &Main_UnknownRoleZeroInitializedStorage_Variant3, 0xb000);
        if (buffer == 0) {
            FileCache_RestoreRomTablesIfSpaceAvailable();
            self[1] = 1;
            return;
        }
        VectorizedMemset(buffer, 0, 0xb000);
        ((SafeAllocator*)(self + 0x14))->CreateTypeA(buffer, 0xb000);
        ((SafeAllocator*)(self + 0x14))->Reset();
        if ((*(void**)(self + 0xc) = ((SafeAllocator*)(self + 0x14))->Allocate(0x1414)) == 0) {
            FileCache_RestoreRomTablesIfSpaceAvailable();
            self[1] = 1;
            return;
        }
        OverlayLoader_PushPrimarySelection(3);
        InitializePresentationAndTransferControlDefaults(*(char**)(self + 0xc));
        Inn_AllocateServiceMenuResources(*(char**)(self + 0xc), (SafeAllocator*)(self + 0x14));
        *(unsigned short*)(*(char**)(self + 0xc) + 0xa) = *(unsigned*)(self + 8);
        GameObject_DisableMovementInput((Object*)game->GetUnknownGameObject(), 1);
        Camera_DisableOrbitInput((int)GameState_GetFieldOrbitCamera(game));
        *(unsigned*)(self + 0x10) = 1;
        return;
    }
    if (state == 1) {
        if (Inn_UpdateServiceMenuState(*(char**)(self + 0xc)) == 0)
            *(unsigned*)(self + 0x10) = 2;
        Field_IsHostDisconnectPending();
        if (Field_IsHostDisconnectPending() != 0) {
            if (*(short*)(*(char**)(self + 0xc) + 4) != 5) {
                GameState_InitializeResourcesThenMarkOverlayRecord(self);
                *(unsigned*)(self + 0x10) = 3;
            }
        }
        return;
    }
    if (state == 2) {
        Graphics_ReleaseSelectionResourcesAndClearMainBG(self);
        GameObject_RequestMovementInputEnable((int)game->GetUnknownGameObject());
        int camera = (int)GameState_GetFieldOrbitCamera(game);
        Camera_EnableOrbitInput(camera);
        Camera_ClearFollowControlFlags((unsigned char*)camera, 2);
        GameResources_ClearSecondaryFlags((int)GameResources_GetInstance(), 0xc0);
        *(unsigned*)(self + 0x10) = ~0u;
        return;
    }
    if (state != 3)
        return;
    if (Inn_UpdateServiceMenuState(*(char**)(self + 0xc)) != 0)
        return;
    Ov003_CompleteSelectionInitialization(self);
}
