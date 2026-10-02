#include "AnimatedRectangle.h"

extern "C" void func_ov005_02153728(AnimatedRectangle* rectangle, int ticks)
{
    if (ticks == 0)
        ticks = 1;
    fix32_t rate = ticks * 0xb33;
    fix32_t threshold = ticks * 0xccc;
    func_ov005_021538fc(rectangle, &rectangle->targetLeft, &rectangle->currentLeft, rate, threshold);
    func_ov005_021538fc(rectangle, &rectangle->targetTop, &rectangle->currentTop, rate, threshold);
    func_ov005_021538fc(rectangle, &rectangle->targetWidth, &rectangle->currentWidth, rate, threshold);
    func_ov005_021538fc(rectangle, &rectangle->targetHeight, &rectangle->currentHeight, rate, threshold);
}
