#include "World/ZoneResourceInterfaces.h"
#pragma once

#include "Memory/SafeAllocator.h"
#include "Graphics/VRAMAllocations.h"

// State saved by 0207de48, copied/reset by 0207df50 and restored by 0207df90.
// Texture image snapshots contain the start/end pair for each of five pools.
struct OverlayTextureReservation {
    unsigned int initialImageState[10];  // 0x00
    unsigned int currentImageState[10];  // 0x28
    unsigned int imageAllocation;        // 0x50
    int imageBytes;                      // 0x54
    TexturePaletteVRAMState initialPaletteState; // 0x58
    TexturePaletteVRAMState currentPaletteState; // 0x60
    unsigned int paletteAllocation;      // 0x68
    int paletteBytes;                    // 0x6c
};

// Observed resource prefix of the overlay state. Names intentionally retain
// offsets where the allocation's eventual payload has not been established.
// The intervening overlay state remains required reconstruction work.
struct OverlayResources {
    SafeAllocator pool000;
    SafeAllocator pool014;
    SafeAllocator pools028[8];
    SafeAllocator pools0c8[16];
    SafeAllocator pool208;
    SafeAllocator pool21c;
    SafeAllocator pool230;
    SafeAllocator pool244;
    SafeAllocator pool258;
    SafeAllocator pool26c;
    SafeAllocator pool280;
    OverlayTextureReservation largeTexture; // 0x294
    OverlayTextureReservation textures[24]; // 0x304
    OverlayTextureReservation extraTexture; // 0xd84
    unsigned char unresolvedState[0x3d88 - 0xdf4];
    void* buffer3d88;
    void* buffer3d8c;
    void* buffer3d90;
    void* buffer3d94;
};

extern "C" void func_0207de48(OverlayTextureReservation*, int imageBytes, int paletteBytes);
