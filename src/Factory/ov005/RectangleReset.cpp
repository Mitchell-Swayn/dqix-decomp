#include "AnimatedRectangle.h"

extern "C" void func_ov005_021536e0(AnimatedRectangle* rectangle)
{
    rectangle->renderParts = 0;
    rectangle->cornerInset = 0x8000;
    rectangle->baseLeft = rectangle->baseWidth = 0;
    rectangle->baseTop = rectangle->baseHeight = 0;
    rectangle->targetLeft = rectangle->targetTop = 0;
    rectangle->targetWidth = rectangle->targetHeight = 0;
    rectangle->currentLeft = rectangle->currentTop = 0;
    rectangle->currentWidth = rectangle->currentHeight = 0;
    rectangle->depth = 0;
}
