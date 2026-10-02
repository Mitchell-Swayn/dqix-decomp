#pragma once

#include "Graphics/Vector.h"

// Layout observed at the overlay's embedded state (+0x1a34). The renderer
// selects the pointee layout by mode; its reconstruction remains separate.
struct AnimatedRectangle {
    void* renderParts;          // 0x00
    fix32_t cornerInset;        // 0x04
    fix32_t baseLeft;           // 0x08
    fix32_t baseWidth;          // 0x0c
    fix32_t baseTop;            // 0x10
    fix32_t baseHeight;         // 0x14
    fix32_t targetLeft;         // 0x18
    fix32_t targetTop;          // 0x1c
    fix32_t targetWidth;        // 0x20
    fix32_t targetHeight;       // 0x24
    fix32_t currentLeft;        // 0x28
    fix32_t currentTop;         // 0x2c
    fix32_t currentWidth;       // 0x30
    fix32_t currentHeight;      // 0x34
    fix32_t depth;              // 0x38
};

extern "C" void func_ov005_021538fc(AnimatedRectangle*, const fix32_t*, fix32_t*, fix32_t, fix32_t);
