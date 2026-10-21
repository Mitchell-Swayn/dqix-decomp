#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/Brightness.h>
#include <System/BGBases.h>
#include <System/Matrix.h>
ARM
extern "C" {
void* GameState_ReadUnknownB0(GameState* state);
void Camera_DisableTargetFollowing(int param_1);
void Camera_EnableOrbitInput(int param_1);
typedef unsigned int undefined4;
undefined4 Camera_GetOrbitHeading(int param_1);
struct Triple {
    int x, y, z;
};
void Camera_SetOrbitParameters(void* p, const Triple* v);
void GameState_SetIndexedObjectAndSlot(GameState* state, int index, GameObject* object);
void Town_LoadPreviewModel(unsigned char* self);
void Graphics_FillModelTexturePalette(char* self, unsigned short color);
void Graphics_ClearSubBG1CharacterAndScreenBuffers();
void G3X_SetClearColor(unsigned a, unsigned b, unsigned short c, unsigned d, int enabled);
void Graphics_SetSelectedScreenPowerState(unsigned int enabled);
void Graphics_LoadCanvasResourceBlocks(char* p, int mainEngine, int alternate);
unsigned int TextContext_GetSharedInstance();
void TextWindow_ResetGlyphBuffersAndFrameContexts(void* p);
struct Object {
    char pad[0xc0];
    unsigned state;
    unsigned short value;
};
void SoundSfx_LoadGroupAtCurrentHeapState(Object* p, unsigned state, unsigned short value);
extern char Town_AdvanceModelPreviewLoading_PathDataPackLv5EnemyGp2[];
extern char TownAdvanceModelPreviewLoading_UnknownRoleZeroInitializedStorage_Variant3[];
extern char TownAdvanceModelPreviewLoading_UnknownRoleZeroInitializedStorage_Variant4[];
extern char Town_AdvanceModelPreviewLoading_PathDataMenuRbEv00Pac[];
extern Vector3i TownAdvanceModelPreviewLoading_UnknownRoleZeroInitializedStorage;
extern Triple TownAdvanceModelPreviewLoading_UnknownRoleZeroInitializedStorage_Variant2;
extern unsigned char Main_UnknownRoleZeroInitializedStorage[];
}

// Original: arm9/ov003 @ 0x0217BF78; symbol: func_ov003_0217bf78; size: 0x328.
// Queues preview model/canvas archives, then on each signed phase byte waits for
// the matching BackgroundLoader task, applies camera and display setup, and
// falls through after a failed detailed status as in the original control flow.
extern "C" void Town_AdvanceModelPreviewLoading(char* self)
{
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameResources* resources = GameResources_GetInstance();
    signed char phase = self[0x141];
    if (phase == 0) {
        GameState* game = GameState::GetInstance();
        *(int*)(self + 0x130) = loader->QueueLoadFileInGP2(
            Town_AdvanceModelPreviewLoading_PathDataPackLv5EnemyGp2,
            TownAdvanceModelPreviewLoading_UnknownRoleZeroInitializedStorage_Variant3,
            0);
        *(int*)(self + 0x138) = loader->QueueLoadFile(
            TownAdvanceModelPreviewLoading_UnknownRoleZeroInitializedStorage_Variant4, 0);
        *(int*)(self + 0x134) = loader->QueueLoadFile(
            Town_AdvanceModelPreviewLoading_PathDataMenuRbEv00Pac, 0);
        int camera = (int)GameState_ReadUnknownB0(game);
        Camera_DisableTargetFollowing(camera);
        Camera_EnableOrbitInput(camera);
        *(unsigned short*)(camera + 0x21e) = (unsigned short)Camera_GetOrbitHeading(camera);
        loader->RemoveTask(*(int*)(self + 0x13c));
        *(int*)(self + 0x13c) = -1;
        self[0x141] = self[0x141] + 1;
        return;
    }
    if (phase == 1) {
        if (!loader->GetTaskStatus(*(int*)(self + 0x130)))
            return;
        if (IsBrightnessTransitionActive(resources))
            return;
        if (loader->GetDetailedTaskStatus(*(int*)(self + 0x130)) != 2) {
            loader->RemoveTask(*(int*)(self + 0x130));
            self[0x140] = 4;
            self[0x141] = 0;
        }
        GameState* game = GameState::GetInstance();
        TextWindow_ResetGlyphBuffersAndFrameContexts((void*)TextContext_GetSharedInstance());
        Town_LoadPreviewModel((unsigned char*)self);
        char* camera = (char*)GameState_ReadUnknownB0(game);
        *(Vector3i*)(self + 0x144) = *(Vector3i*)(camera + 0x10);
        *(Vector3i*)(self + 0x150) = *(Vector3i*)(camera + 0x70);
        *(Vector3i*)(camera + 0x10) = TownAdvanceModelPreviewLoading_UnknownRoleZeroInitializedStorage;
        Camera_SetOrbitParameters(camera, &TownAdvanceModelPreviewLoading_UnknownRoleZeroInitializedStorage_Variant2);
        GameState_SetIndexedObjectAndSlot(game, 0xa0, (GameObject*)(self + 0x80));
        Graphics_FillModelTexturePalette(self, 0);
        self[0x141] = self[0x141] + 1;
        return;
    }
    if (phase == 2) {
        if (!loader->GetTaskStatus(*(int*)(self + 0x134)))
            return;
        if (loader->GetDetailedTaskStatus(*(int*)(self + 0x134)) != 2) {
            loader->RemoveTask(*(int*)(self + 0x134));
            self[0x140] = 4;
            self[0x141] = 0;
        }
        if (*(int*)(self + 0x160) != 0)
            Graphics_ClearSubBG1CharacterAndScreenBuffers();
        ((Object3D*)(self + 0x80))->MakeHidden();
        G3X_SetClearColor(0, 0x1f, 0x7fff, 0, 0);
        *(volatile unsigned*)0x04000000 = (*(volatile unsigned*)0x04000000 & ~0x1f00u) | 0x100u;
        Graphics_SetSelectedScreenPowerState(1);
        self[0x141] = self[0x141] + 1;
        return;
    }
    if (phase != 3)
        return;
    if (!loader->GetTaskStatus(*(int*)(self + 0x138)))
        return;
    if (loader->GetDetailedTaskStatus(*(int*)(self + 0x138)) != 2) {
        loader->RemoveTask(*(int*)(self + 0x138));
        self[0x140] = 4;
        self[0x141] = 0;
    }
    Graphics_LoadCanvasResourceBlocks(self, 0, 0);
    unsigned short* screen = (unsigned short*)GetSubBG0ScreenBase();
    for (int i = 0; i < 0x800; ++i)
        *screen++ = 0;
    *(volatile unsigned*)0x04001000 = *(volatile unsigned*)0x04001000 & ~0x1f00u;
    self[0x140] = 2;
    self[0x141] = 0;
    SoundSfx_LoadGroupAtCurrentHeapState((Object*)Main_UnknownRoleZeroInitializedStorage, 0x8b, 0x8b);
}
