#include <Memory/SafeAllocator.h>
// Brightness state occupies the shared first 0x2c bytes; the following
// fields are proved by the five ov021 entry points and their main callees.
struct Stage {
    unsigned char brightness[0x2c];
    SafeAllocator allocator;
    void *screen;
    unsigned char renderer[0x70];
    void *resource;
    int exitRequested;
};

#pragma force_active on
#include <GameState/GameState.h>
#include <Graphics/NSBXX/RenderConfig.h>
#include <Graphics/NSBXX/GeometryFifo.h>
extern "C" void *GameState_ReadUnknownB0(GameState *);
extern "C" void Graphics_InitializeGeometryAndDisplayState();
extern "C" void Graphics_ResetGeometryMatrixStackState();
extern "C" void Camera_UpdateRenderView(void *);
extern "C" void func_ov009_02184c30(void *);
extern "C" void func_ov009_02184bbc(void *);
extern "C" void *ReadGlobalAt02105AB4();
extern "C" void Graphics_FlushTwoBackgroundBuffers();
extern "C" void Graphics_WriteSwapControlAndToggleGlobalState(unsigned int, unsigned int);
// Original: arm9/ov021 @ 0x0218BB30; symbol: func_ov021_0218bb30; size: 0x94.
extern "C" void func_ov021_0218bb30(Stage *self) {
    void *object = GameState_ReadUnknownB0(GameState::GetInstance());
    Graphics_InitializeGeometryAndDisplayState();
    Graphics_ResetGeometryMatrixStackState();
    volatile unsigned short *control = (volatile unsigned short *)0x04000060;
    *control = (*control & ~0x3000) | 8;
    *control = (*control & ~0x3000) | 16;
    *control = (*control & ~0x3000) | 32;
    if (object) Camera_UpdateRenderView(object);
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();
    func_ov009_02184c30(self->screen);
    func_ov009_02184bbc(self->screen);
    ReadGlobalAt02105AB4();
    Graphics_FlushTwoBackgroundBuffers();
    Graphics_WriteSwapControlAndToggleGlobalState(1, 0);
}
