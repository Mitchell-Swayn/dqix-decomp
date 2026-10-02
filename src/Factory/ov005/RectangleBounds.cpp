#include "AnimatedRectangle.h"

extern "C" void func_ov005_02154d18(AnimatedRectangle* rectangle, fix32_t left, fix32_t top)
{
    rectangle->targetLeft = left + rectangle->baseLeft;
    rectangle->targetTop = top + rectangle->baseTop;
}

extern "C" void func_ov005_02154d34(AnimatedRectangle* rectangle, fix32_t left, fix32_t top)
{
    rectangle->currentLeft = left + rectangle->baseLeft;
    rectangle->currentTop = top + rectangle->baseTop;
}

extern "C" void func_ov005_02154d50(AnimatedRectangle* rectangle, fix32_t right, fix32_t bottom)
{
    rectangle->targetWidth = rectangle->baseWidth + (right - rectangle->baseLeft);
    rectangle->targetHeight = rectangle->baseHeight + (bottom - rectangle->baseTop);
}

extern "C" void func_ov005_02154d7c(AnimatedRectangle* rectangle, fix32_t right, fix32_t bottom)
{
    rectangle->currentWidth = rectangle->baseWidth + (right - rectangle->baseLeft);
    rectangle->currentHeight = rectangle->baseHeight + (bottom - rectangle->baseTop);
}
