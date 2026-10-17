// Original: arm9/main @ 0x02058B3C; symbol: func_02058b3c; size: 0x14c.
#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
#include <std_library_functions.h>
struct AngleKeyframe { unsigned tick; float angle, variationPercent; };
struct AngleKeyframeNode { AngleKeyframe *value; };
struct AngleTimelineResource { char prefix[0xe0]; SignedAllocatorList keyframes; };
struct AngleTimelineRecord { char prefix[8]; unsigned char count; };
struct AngleTimelineState {
    char unknown00[4]; unsigned tick; char unknown08[0x20]; AngleTimelineResource *resource;
    char unknown2c[0x20]; float anglePerTick; char unknown50[0x10]; float segmentAngle;
    char unknown64[6]; unsigned short frameIndex;
};
extern "C" AngleTimelineRecord *ReadResolvedRecordWordField20OrZero(AngleTimelineResource *);
// ARM9 main, original func_02058b3c at 0x02058b3c.
// Proposed semantic name: AdvanceRandomizedAngleKeyframe.
extern "C" ARM void AdvanceRandomizedAngleKeyframe(AngleTimelineState *state)
{
    AngleTimelineRecord *record = ReadResolvedRecordWordField20OrZero(state->resource);
    if (record->count <= 1) return;
    if (record->count <= state->frameIndex) return;
    AngleKeyframeNode *previous = (AngleKeyframeNode *)state->resource->keyframes.GetNthElement(state->frameIndex);
    if (!previous) return;
    if (previous->value->tick >= state->tick) return;
    state->frameIndex++;
    if (state->frameIndex >= record->count) { state->anglePerTick = 0; return; }
    AngleKeyframeNode *next = (AngleKeyframeNode *)state->resource->keyframes.GetNthElement(state->frameIndex);
    if (!next) return;
    AngleKeyframe *key = next->value;
    // Preserve the original bit-mask sampling, rather than a remainder operation.
    float variation = (float)((rand() & ((int)key->variationPercent * 2)) - (int)key->variationPercent) / 100.0f;
    state->segmentAngle = key->angle + key->angle * variation;
    state->anglePerTick = state->segmentAngle / (float)(int)(next->value->tick - previous->value->tick);
    if (state->anglePerTick < 0.0f) state->anglePerTick += 360.0f;
    if (state->anglePerTick > 360.0f) state->anglePerTick -= 360.0f;
}
