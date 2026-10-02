#include "Overlay21Context.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "Graphics/NSBXX/GeometryFifo.h"

struct Overlay21Sound;

extern "C" {
    extern Overlay21Sound data_02108760;
    void func_0203aa08(Overlay21Sound* sound);
    void func_020bbd9c();
    int func_ov009_02184a18(Overlay21Scene* scene);
    void* func_020100bc(GameState* state);
    void func_020c52e8();
    void func_020c5414();
    void func_0202e0a4(void* camera);
    void func_ov009_02184c30(Overlay21Scene* scene);
    void func_ov009_02184bbc(Overlay21Scene* scene);
    Overlay21OAM* func_0203bd08();
    void func_0203bd88(Overlay21OAM* oam);
    void func_020d86d0(int sortMode, int bufferMode);
}

extern "C" void func_ov021_0218baf8(Overlay21Context* context)
{
    BackgroundLoader::GetInstance()->RemoveAllLocks();
    if (func_ov009_02184a18(context->scene))
        context->exitRequested = 1;
    func_0203aa08(&data_02108760);
    func_020bbd9c();
}

extern "C" void func_ov021_0218bb30(Overlay21Context* context)
{
    void* camera = func_020100bc(GameState::GetInstance());
    func_020c52e8();
    func_020c5414();
    volatile unsigned short* display3D = reinterpret_cast<volatile unsigned short*>(0x04000060);
    *display3D = (*display3D & ~0x3000) | 0x08;
    *display3D = (*display3D & ~0x3000) | 0x10;
    *display3D = (*display3D & ~0x3000) | 0x20;
    if (camera)
        func_0202e0a4(camera);
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();
    func_ov009_02184c30(context->scene);
    func_ov009_02184bbc(context->scene);
    func_0203bd88(func_0203bd08());
    func_020d86d0(1, 0);
}
