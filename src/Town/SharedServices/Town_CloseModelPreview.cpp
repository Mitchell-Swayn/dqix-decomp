#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Brightness.h>
#include <System/Matrix.h>
ARM
extern "C" {
void Graphics_ClearScreenBuffer(unsigned char* p, void* buffer);
void Graphics_CleanConfiguredDestinationCache(unsigned char* entry, void* destination);
void Graphics_TransferScreenBuffer(void*, int);
void Graphics_ResetLoadedLayerResources(unsigned char* p);
void G3X_SetClearColor(unsigned a, unsigned b, unsigned short c, unsigned d, int enabled);
void* GameState_ReadUnknownB0(GameState* state);
struct Triple {
    int x, y, z;
};
void Camera_SetOrbitParameters(void* p, const Triple* v);
void Camera_EnableTargetFollowing(int param_1);
void Camera_RestoreSavedOrbitHeading(char* p);
void Graphics_SetSelectedScreenPowerState(unsigned int enabled);
void GameState_ClearObjectByIndex(GameState* state, int index);
}

// Original: arm9/ov003 @ 0x0217C7A0; symbol: func_ov003_0217c7a0; size: 0x1d4.
// Fades brightness, then on the next phase destroys nested allocators, removes
// preview load tasks, clears canvases and restores the saved orbit camera.
extern "C" void Town_CloseModelPreview(char* self)
{
    GameResources* resources = GameResources_GetInstance();
    signed char phase = self[0x141];
    if (phase == 0) {
        SetBrightness(resources, -16, 0x3c);
        self[0x141] = self[0x141] + 1;
        return;
    }
    if (phase != 1)
        return;
    if (IsBrightnessTransitionActive(resources))
        return;
    GameState* game = GameState::GetInstance();
    void* allocation = ((SafeAllocator*)(self + 4))->GetSignedAllocator();
    if (allocation != 0) {
        ((SafeAllocator*)(self + 4))->Destroy();
        (*(SafeAllocator**)self)->Free(allocation);
    }
    allocation = ((SafeAllocator*)(self + 0x18))->GetSignedAllocator();
    if (allocation != 0) {
        ((SafeAllocator*)(self + 0x18))->Destroy();
        (*(SafeAllocator**)self)->Free(allocation);
    }
    allocation = ((SafeAllocator*)(self + 0x2c))->GetSignedAllocator();
    if (allocation != 0) {
        ((SafeAllocator*)(self + 0x2c))->Destroy();
        (*(SafeAllocator**)self)->Free(allocation);
    }
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    loader->RemoveTask(*(int*)(self + 0x130));
    *(int*)(self + 0x130) = -1;
    loader->RemoveTask(*(int*)(self + 0x134));
    *(int*)(self + 0x134) = -1;
    loader->RemoveTask(*(int*)(self + 0x138));
    *(int*)(self + 0x138) = -1;
    Graphics_ClearScreenBuffer((unsigned char*)(self + 0x40), 0);
    Graphics_CleanConfiguredDestinationCache((unsigned char*)(self + 0x40), 0);
    Graphics_TransferScreenBuffer(self + 0x40, 0);
    Graphics_ResetLoadedLayerResources((unsigned char*)(self + 0x40));
    Graphics_ClearScreenBuffer((unsigned char*)(self + 0x60), 0);
    Graphics_CleanConfiguredDestinationCache((unsigned char*)(self + 0x60), 0);
    Graphics_TransferScreenBuffer(self + 0x60, 0);
    Graphics_ResetLoadedLayerResources((unsigned char*)(self + 0x60));
    G3X_SetClearColor(0, 0, 0x7fff, 0, 0);
    char* camera = (char*)GameState_ReadUnknownB0(game);
    *(Vector3i*)(camera + 0x10) = *(Vector3i*)(self + 0x144);
    Camera_SetOrbitParameters(camera, (const Triple*)(self + 0x150));
    Camera_EnableTargetFollowing((int)camera);
    Camera_RestoreSavedOrbitHeading(camera);
    Graphics_SetSelectedScreenPowerState(0);
    GameState_ClearObjectByIndex(game, 0xa0);
    self[0x143] = 1;
}
