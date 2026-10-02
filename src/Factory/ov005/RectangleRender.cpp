#include "AnimatedRectangle.h"
#include "std_library_functions.h"

// Partial records observed by this renderer. Mode selects the layout of
// renderParts; unknown bytes and the callees' remaining semantics are unresolved.
// Sizes describe array strides, not a recovered class hierarchy.
struct RectangleGeometryPart {
    unsigned char unknown_00[0x80];
    unsigned short attribute;
    unsigned char unknown_82[6];
};

struct RectangleScreenPart {
    unsigned char unknown_00[0x70];
};

struct RectanglePositionPart {
    unsigned char unknown_00[0x14];
    fix32_t x;
    fix32_t y;
    unsigned char unknown_1c[0x0c];
};

typedef char GeometryPartSizeCheck[sizeof(RectangleGeometryPart) == 0x88 ? 1 : -1];
typedef char GeometryAttributeOffsetCheck[
    offsetof(RectangleGeometryPart, attribute) == 0x80 ? 1 : -1];
typedef char ScreenPartSizeCheck[sizeof(RectangleScreenPart) == 0x70 ? 1 : -1];
typedef char PositionPartSizeCheck[sizeof(RectanglePositionPart) == 0x28 ? 1 : -1];
typedef char PositionXOffsetCheck[offsetof(RectanglePositionPart, x) == 0x14 ? 1 : -1];
typedef char PositionYOffsetCheck[offsetof(RectanglePositionPart, y) == 0x18 ? 1 : -1];

extern "C" void func_02047554(RectangleGeometryPart*, int, int);
extern "C" void func_02075db0(RectangleScreenPart*, int, int);

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
            RectangleGeometryPart* part = (RectangleGeometryPart*)rectangle->renderParts + i;
            part->attribute = attribute;
            func_02047554((RectangleGeometryPart*)rectangle->renderParts + i, 0, 1);
            geometry[1] = 1;
            break;
        }
        case 1:
            func_02075db0((RectangleScreenPart*)rectangle->renderParts + i, x >> 12, y >> 12);
            break;
        case 2: {
            RectanglePositionPart* part = (RectanglePositionPart*)rectangle->renderParts + i;
            part->x = x;
            part->y = y;
            break;
        }
        }
    }
}
