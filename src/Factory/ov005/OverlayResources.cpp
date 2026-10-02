#include "OverlayResources.h"

extern "C" void func_ov005_02153954(OverlayResources* state,
                                   SafeAllocator* primary, SafeAllocator* secondary)
{
    if (!primary || !secondary)
        return;

    state->pool014.CreateTypeA(secondary->Allocate(0x1300), 0x1300);
    for (int i = 0; i < 8; ++i)
        state->pools028[i].CreateTypeA(secondary->Allocate(0xe0), 0xe0);
    for (int i = 0; i < 16; ++i)
        state->pools0c8[i].CreateTypeA(secondary->Allocate(0xe0), 0xe0);
    state->pool208.CreateTypeA(secondary->Allocate(0xe0), 0xe0);
    state->pool21c.CreateTypeA(secondary->Allocate(0xc00), 0xc00);
    state->pool244.CreateTypeA(primary->Allocate(0x1e00), 0x1e00);
    state->pool000.CreateTypeA(primary->Allocate(0x4b00), 0x4b00);
    state->pool258.CreateTypeA(primary->Allocate(0x4a00), 0x4a00);
    state->pool26c.CreateTypeA(primary->Allocate(0x1e00), 0x1e00);
    state->pool280.CreateTypeA(secondary->Allocate(0x200), 0x200);
    state->buffer3d88 = primary->Allocate(0x800);
    state->buffer3d8c = secondary->Allocate(0x200);
    state->buffer3d90 = primary->Allocate(0x800);
    state->buffer3d94 = secondary->Allocate(0x200);
}

extern "C" void func_ov005_02153b20(OverlayResources* state)
{
    for (int i = 0; i < 24; ++i) {
        func_0207de48(&state->textures[i], 0x120, 0x20);
        func_0207df50(&state->textures[i]);
    }
    func_0207de48(&state->extraTexture, 0x120, 0x20);
    func_0207df50(&state->extraTexture);
    func_0207de48(&state->largeTexture, 0x3000, 0x400);
    func_0207df50(&state->largeTexture);
}
