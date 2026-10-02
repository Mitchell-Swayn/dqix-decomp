#include "AnimatedRectangle.h"

extern "C" void func_02047554(void*, int, int);
extern "C" void func_02075db0(void*, int, int);

extern "C" void func_ov005_021537bc(AnimatedRectangle* rectangle, int mode, unsigned short attribute)
{
    if (!rectangle->renderParts)
        return;

    struct Corner { fix32_t x, y; };
    Corner corners[4];
    fix32_t left = rectangle->currentLeft;
    fix32_t width = rectangle->currentWidth;
    fix32_t top = rectangle->currentTop;
    fix32_t height = rectangle->currentHeight;
    fix32_t inset = rectangle->cornerInset;
    corners[0].x = left & ~0xfff;
    corners[0].y = top & ~0xfff;
    corners[3].x = corners[1].x = (left + width - inset) & ~0xfff;
    corners[1].y = corners[0].y;
    corners[2].x = corners[0].x;
    corners[3].y = corners[2].y = (top + height - inset) & ~0xfff;

    for (int i = 0; i < 4; ++i) {
        fix32_t x = corners[i].x;
        fix32_t y = corners[i].y;
        switch (mode) {
        case 0: {
            // Geometry matrix push, translation, then matrix pop.
            volatile unsigned int* geometry = (volatile unsigned int*)0x04000444;
            geometry[0] = 0;
            fix32_t depth = rectangle->depth;
            geometry[11] = x;
            geometry[11] = y;
            geometry[11] = depth;
            unsigned char* part = (unsigned char*)rectangle->renderParts + i * 0x88;
            *(unsigned short*)(part + 0x80) = attribute;
            func_02047554((unsigned char*)rectangle->renderParts + i * 0x88, 0, 1);
            geometry[1] = 1;
            break;
        }
        case 1:
            func_02075db0((unsigned char*)rectangle->renderParts + i * 0x70, x >> 12, y >> 12);
            break;
        case 2: {
            unsigned char* part = (unsigned char*)rectangle->renderParts + i * 0x28;
            *(fix32_t*)(part + 0x14) = x;
            *(fix32_t*)(part + 0x18) = y;
            break;
        }
        }
    }
}
