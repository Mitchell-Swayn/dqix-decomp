#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Resource/GameResources.h>
#undef GameResources_GetInstance
ARM
extern "C" GameResources* GameResources_GetInstance();
extern "C" void GameObject_RequestMovementInputEnable(int);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_ClearFlags(unsigned*, unsigned);
extern "C" void OnlineContent_DispatchDownloadedParts(void*, void*, int, void*);
extern "C" SafeAllocator MemoryFreeWithIRQDisabled_UnknownRoleZeroInitializedStorage;

#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x022439D8; symbol: OnlineTransfer_CleanUpSession; size: 0x15c.
extern "C" int OnlineTransfer_CleanUpSession(void* object) {
    GameResources* resources = GameResources_GetInstance();
    BackgroundLoader* backgroundLoader = BackgroundLoader::GetInstance();
    GameState* gameState = GameState::GetInstance();
    GameObject* unknownObject = gameState->GetUnknownGameObject();
    if (unknownObject) GameObject_RequestMovementInputEnable((int)unknownObject);
    W((char*)resources + 0x4000, 0x494) = 0;
    int task = (int)W(object, 0x39c);
    if (task >= 0) {
        backgroundLoader->RemoveTask(task);
        W(object, 0x39c) = 0xffffffff;
    }
    if ((int)W(object, 0x3a0) >= 0) {
        backgroundLoader = BackgroundLoader::GetInstance();
        backgroundLoader->RemoveTask((int)W(object, 0x3a0));
        W(object, 0x3a0) = 0xffffffff;
    }
    SignedAllocatorHeader* signedBlock = MemoryFreeWithIRQDisabled_UnknownRoleZeroInitializedStorage.GetSignedAllocator();
    if (signedBlock) {
        MemoryFreeWithIRQDisabled_UnknownRoleZeroInitializedStorage.Destroy();
        ((SafeAllocator*)object)->Free(signedBlock);
    }
    signedBlock = ((SafeAllocator*)object)->GetSignedAllocator();
    if (signedBlock) {
        ((SafeAllocator*)object)->Destroy();
        ((SafeAllocator*)W(object, 0x28))->Free(signedBlock);
    }
    if (B(object, 0x44) & 1) {
        ((SafeAllocator*)object)->ResetAllocatorPointer();
        SafeAllocator* backing = (SafeAllocator*)W(object, 0x28);
        void* block = backing->Allocate(0xf000);
        if (block) {
            ((SafeAllocator*)object)->CreateTypeA(block, 0xf000);
            ((SafeAllocator*)object)->Reset();
            OnlineContent_DispatchDownloadedParts((void*)W(object, 0x37c), (char*)object + 0x50, 4, object);
        }
        signedBlock = ((SafeAllocator*)object)->GetSignedAllocator();
        if (signedBlock) {
            ((SafeAllocator*)object)->Destroy();
            ((SafeAllocator*)W(object, 0x28))->Free(signedBlock);
        }
    }
    if (!(B(object, 0x374) & 0x20)) SystemState_ClearFlags((unsigned*)SystemState_GetGlobalFlags(), 0x80);
    W(object, 0x30) = 1;
    return 2;
}
