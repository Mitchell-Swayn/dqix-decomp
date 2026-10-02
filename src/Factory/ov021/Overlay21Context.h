#pragma once

#include "Memory/SafeAllocator.h"
#include "Graphics/VRAMAllocations.h"

struct Overlay21Scene;
struct Overlay21OAM;

// The brightness routines share the first 0x29 bytes with GameResources.
// This overlay has its own allocator immediately afterward, at 0x2c.
struct Overlay21Brightness
{
    unsigned int flags[3];
    float mainBrightness;
    int mainTarget;
    int mainTimeRemaining;
    float subBrightness;
    int subTarget;
    int subTimeRemaining;
    bool mainLocked;
    bool subLocked;
    bool mainDirty;
    bool subDirty;
    bool allowApply;
};

// Layout follows the save/copy/allocation operations in 0207de48.
struct Overlay21TextureScope
{
    unsigned int savedImageBounds[10];
    unsigned int currentImageBounds[10];
    unsigned int imageAllocationKey;
    unsigned int imageAllocationSize;
    TexturePaletteVRAMState savedPaletteBounds;
    TexturePaletteVRAMState currentPaletteBounds;
    unsigned int paletteAllocationKey;
    unsigned int paletteAllocationSize;
};

struct Overlay21Context
{
    Overlay21Brightness brightness;
    SafeAllocator sceneAllocator;
    Overlay21Scene* scene;
    Overlay21TextureScope textures;
    // A free GameState indexed record, returned by 02010954 (not GameObject).
    struct GameStateIndexedRecord* gameObject;
    int exitRequested;
};

typedef char Overlay21BrightnessSizeCheck[sizeof(Overlay21Brightness) == 0x2c ? 1 : -1];
typedef char Overlay21TextureSizeCheck[sizeof(Overlay21TextureScope) == 0x70 ? 1 : -1];
typedef char Overlay21ContextSizeCheck[sizeof(Overlay21Context) == 0xbc ? 1 : -1];
