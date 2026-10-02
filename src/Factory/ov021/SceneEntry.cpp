#include "Overlay21Context.h"
#include "SceneEdgeColors.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Graphics/NSBXX/GeometryFifo.h"
#include "Graphics/VRAMStaging.h"
#include "Resource/Brightness.h"
#include "System/VRAM.h"

// Partial external layouts: only fields used by this scene are named. Unknown
// storage is retained; none of these declarations supplies external data.
struct Overlay21Scene
{
    SafeAllocator allocators[9];
    unsigned char unknown_0b4[0xd88 - 0xb4];
    GameStateIndexedRecord* indexedRecord;
    unsigned char unknown_d8c[0xdb8 - 0xd8c];
};

struct Overlay21OAM
{
    unsigned int offset;
};

struct Overlay21SpriteQueue
{
    unsigned char* objectAttributes;
    unsigned char unknown_004[0x508 - 4];
    unsigned int objectVRAMOffset;
};

struct Overlay21Graphics
{
    unsigned char unknown_0000[0x1e28];
    Overlay21TextureScope* textureScope;
};

struct Overlay21Sound;

extern "C" {
    // Hypothesis for the two literal loads: Nitro linker-valued overlay IDs.
    // This candidate is incomplete; its proposed absolute values (9 and 23)
    // are recorded in build/factory/fleet_ov021, not in the accepted link.
    extern char SDK_OVERLAY_ID_ov009[];
    extern char SDK_OVERLAY_ID_ov023[];
    extern AllocatorUnion data_02114e20;
    extern unsigned int data_02114e50;
    extern Overlay21Sound data_02109bf4;
    void func_020a1df8(unsigned int group);
    int func_020a1940(unsigned int overlay);
    void func_020a1e54(unsigned int count);
    void func_0200fb84(GameState*, GameResources*);
    unsigned char func_0200fb9c(GameState*);
    void func_020c39a0(volatile unsigned short*, int);
    Overlay21OAM* func_0203bd08();
    void func_0203bd24(Overlay21OAM*);
    Overlay21SpriteQueue* func_0203bd14();
    unsigned char* func_0203be4c(Overlay21OAM*);
    void func_0203c35c(Overlay21SpriteQueue*);
    void func_020ca458(unsigned int, void*, unsigned int);
    void func_020c51dc();
    void func_020c537c();
    void func_020c391c(int, int, int);
    void func_020c3984(int);
    void func_020c5588(unsigned int, int, unsigned int, int, int);
    void func_020c555c(unsigned short*);
    void func_0207de48(Overlay21TextureScope*, unsigned int, unsigned int);
    void func_0207df50(Overlay21TextureScope*);
    void func_0207df90(Overlay21TextureScope*);
    void func_0207dfac(Overlay21TextureScope*);
    Overlay21Graphics* func_020421a0();
    void func_02042c68(Overlay21Graphics*);
    void func_02043124(Overlay21Graphics*);
    void func_020440a4(Overlay21Graphics*);
    void func_020432c4(Overlay21Graphics*);
    void func_02043000(Overlay21Graphics*);
    void func_020100a0(GameState*, int);
    int func_020100a8(GameState*);
    void* func_02012d88(AllocatorUnion*, unsigned int);
    void func_ov009_0218454c(Overlay21Scene*, unsigned char, unsigned char);
    void func_ov008_021842a0(Overlay21Scene*, SafeAllocator*);
    void func_ov009_02184848(Overlay21Scene*);
    void func_ov009_02184ca4(Overlay21Scene*);
    GameStateIndexedRecord* func_02010954(GameState*);
    void func_0209c3b4(Overlay21Sound*, int);
    void func_0209c678(Overlay21Sound*, int);
    void func_0203ad88(Overlay21Sound*, int, int);
    void func_0203aa08(Overlay21Sound*);
    void func_0209c20c(Overlay21Sound*);
    void func_020c9820();
    void func_020c38d4();
    void func_02010124(GameState*);
    void func_02012efc();
    void func_020bbcb4();
    void func_0203bdb0(Overlay21OAM*);
    void func_ov021_0218baf8(Overlay21Context*);
    void func_ov021_0218bb30(Overlay21Context*);
}

#pragma force_active on
extern "C" void func_ov021_0218b5fc(Overlay21Context* context)
{
    func_020a1df8(3);
    func_020a1940(reinterpret_cast<unsigned int>(SDK_OVERLAY_ID_ov009));
    func_020a1940(reinterpret_cast<unsigned int>(SDK_OVERLAY_ID_ov023));
    GameState* state = GameState::GetInstance();
    func_0200fb84(state, reinterpret_cast<GameResources*>(context));
    func_020c39a0(reinterpret_cast<volatile unsigned short*>(0x0400006c), -16);
    func_020c39a0(reinterpret_cast<volatile unsigned short*>(0x0400106c), -16);
    BackgroundLoader::GetInstance()->MaybeReset();
    Overlay21OAM* oam = func_0203bd08();
    func_0203bd24(oam);
    oam->offset = 0;
    Overlay21SpriteQueue* sprites = func_0203bd14();
    sprites->objectAttributes = func_0203be4c(oam) + 0x200;
    func_0203c35c(sprites);
    sprites->objectVRAMOffset = 0x7000;
    MapVRAMBanksToLCDC(0x1ff);
    func_020ca458(0, reinterpret_cast<void*>(0x06800000), 0xa4000);
    DisableLCDCMappedVRAMBanks();
    Finish3DRendering();
    func_020c51dc();
    func_020c537c();
    LockStagedTextureVRAMCopying();
    MapVRAMBanksToTextureImage(VRAM_BANK_A);
    InitializeTextureImageVRAM(1, true);
    MapVRAMBanksToTexturePalette(VRAM_BANK_G);
    InitializeTexturePaletteVRAM(0x4000, true);
    MapVRAMBanksToMainBG(VRAM_BANK_E);
    MapVRAMBanksToSubBG(VRAM_BANK_C);
    MapVRAMBanksToMainObj(VRAM_BANK_F);
    volatile unsigned int* mainDisplay = reinterpret_cast<volatile unsigned int*>(0x04000000);
    volatile unsigned int* subDisplay = reinterpret_cast<volatile unsigned int*>(0x04001000);
    *mainDisplay = (*mainDisplay & 0xffcfffef) | 0x10;
    MapVRAMBanksToSubObj(VRAM_BANK_D);
    *subDisplay = (*subDisplay & 0xffcfffef) | 0x10;
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    *mainDisplay = (*mainDisplay & ~0x1f00) | 0x1f00;
    func_020c391c(1, 0, 1);
    volatile unsigned short* mainBG = reinterpret_cast<volatile unsigned short*>(0x0400000a);
    mainBG[0] = (mainBG[0] & 0x43) | 0x1d00;
    mainBG[1] = (mainBG[1] & 0x43) | 0x1e08;
    mainBG[2] = (mainBG[2] & 0x43) | 0x1f0c;
    volatile unsigned short* mainBG0 = reinterpret_cast<volatile unsigned short*>(0x04000008);
    *mainBG0 = (*mainBG0 & ~3) | 2;
    mainBG[0] = (mainBG[0] & ~3) | 3;
    mainBG[1] = (mainBG[1] & ~3) | 1;
    mainBG[2] = mainBG[2] & ~3;
    *reinterpret_cast<volatile unsigned int*>(0x04001000) =
        (*reinterpret_cast<volatile unsigned int*>(0x04001000) & ~0x1f00) | 0x1700;
    func_020c3984(0);
    volatile unsigned short* subBG = reinterpret_cast<volatile unsigned short*>(0x04001008);
    subBG[0] = (subBG[0] & 0x43) | 0x1d00;
    subBG[1] = (subBG[1] & 0x43) | 0x1e10;
    subBG[2] = (subBG[2] & 0x43) | 0x1f18;
    subBG[0] = (subBG[0] & ~3) | 2;
    subBG[1] = (subBG[1] & ~3) | 1;
    subBG[2] = subBG[2] & ~3;
    subBG[3] = (subBG[3] & ~3) | 3;
    volatile unsigned short* power = reinterpret_cast<volatile unsigned short*>(0x04000304);
    *power |= 0x8000;
    func_020c5588(0, 0, 0x7fff, 0, 0);
    Overlay21EdgeColors edgeColors = data_ov021_0218bbc4;
    func_020c555c(edgeColors.colors);
    func_0207de48(&context->textures, 0x4000, 0x40);
    Overlay21Graphics* graphics = func_020421a0();
    func_02042c68(graphics);
    func_02043124(graphics);
    func_020440a4(graphics);
    graphics->textureScope = &context->textures;
    func_0207df50(&context->textures);
    func_0207df90(&context->textures);
    func_020432c4(graphics);
    func_0207dfac(&context->textures);
    func_020100a0(state, 0);
    void* buffer = func_02012d88(&data_02114e20, 0x4b238);
    context->sceneAllocator.CreateTypeA(buffer, 0x4b238);
    context->sceneAllocator.Reset();
    context->scene = static_cast<Overlay21Scene*>(context->sceneAllocator.Allocate(sizeof(Overlay21Scene)));
    func_ov009_0218454c(context->scene, 0, 0);
    context->gameObject = func_02010954(state);
    context->gameObject->objectIndex_ = func_020100a8(state);
    context->scene->indexedRecord = context->gameObject;
    func_ov008_021842a0(context->scene, &context->sceneAllocator);
    func_0209c3b4(&data_02109bf4, 2);
    func_020c9820();
    func_020c38d4();
    *reinterpret_cast<volatile unsigned int*>(0x04001000) |= 0x10000;
    func_02010124(state);
    while (true) {
        if (!func_0200fb9c(state))
            break;
        if (context->exitRequested)
            break;
        func_02012efc();
        func_ov021_0218baf8(context);
        func_ov021_0218bb30(context);
        context->brightness.allowApply = true;
        func_020c9820();
        func_020bbcb4();
        func_ov009_02184ca4(context->scene);
        func_0203bdb0(func_0203bd08());
        UpdateAndApplyBrightness(reinterpret_cast<GameResources*>(context));
        ++data_02114e50;
        state->CalculateDeltaTime(0x411b);
    }
    func_ov009_02184848(context->scene);
    func_0209c678(&data_02109bf4, 0);
    func_0203ad88(&data_02109bf4, 0, 0);
    func_0203aa08(&data_02109bf4);
    func_0209c20c(&data_02109bf4);
    func_02043000(graphics);
    func_0207df50(&context->textures);
    func_0200fb84(state, 0);
    func_020a1e54(1);
}
#pragma force_active reset
