#include "Graphics/NSBXX/JACInternal.h"
#pragma thumb off
// Original: arm9/main @ 0x020B8210; symbol: _Z34CalculateScalingAmountFrameAlignedPiiPN17NSBXXAnimationJAC5Track15ChannelNonConstEPS0_; size: 0x1F4.
// Evaluate primary/secondary scale samples at an integer frame, preserving
// half-rate and quarter-rate interpolation and the packed short-sample option.
void CalculateScalingAmountFrameAligned(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac)
{
    unsigned int metadata;
    unsigned int thisFrame = time >> 12;

    NSBXXAnimationJAC::ScaleSample32* samples = (NSBXXAnimationJAC::ScaleSample32*)((intptr_t)jac + channel->samplesOffset_);
    NSBXXAnimationJAC::ScaleSample16* samples16 = (NSBXXAnimationJAC::ScaleSample16*)samples;

    metadata = channel->metadata_;

    unsigned int averageIdx;

    if ((metadata & 0xc0000000) == 0)
        goto compute_directly;

{
    unsigned int endFrame = (metadata & 0x1fff0000) >> 16;

    // log-rate = 1 or 3: case 3 ignored, so only case 1 (sample every 2nd frame)
    if (metadata & 0x40000000)
    {
        if (thisFrame & 1) // odd frame, need to average
        {
            if (thisFrame > endFrame)
            {
                thisFrame = (endFrame / 2) + 1;
                goto compute_directly;
            }
            else
            {
                averageIdx = thisFrame / 2;
                goto compute_average;
            }
        }
        else
        {
            thisFrame = thisFrame / 2;
            goto compute_directly;
        }
    }
    else // log-rate = 2, sample every 4th frame
    {
        unsigned int mod4 = thisFrame & 3;
        if (mod4 != 0)
        {
            if (thisFrame > endFrame)
            {
                // Past the compressed range, the remaining samples are stored consecutively.
                thisFrame = (endFrame / 4) + mod4;
                goto compute_directly;
            }
            else if (thisFrame & 1) // odd frame: interpolate with 1/4, 3/4 or vice versa
            {
                unsigned int highWeightFrame;
                unsigned int lowWeightFrame;
                if (thisFrame & 2) // 3 mod 4: put weight on the later frame
                {
                    highWeightFrame = (thisFrame / 4) + 1;
                    lowWeightFrame = thisFrame / 4;
                }
                else // 1 mod 4: put weight on the earlier frame
                {
                    lowWeightFrame = (thisFrame / 4) + 1;
                    highWeightFrame = thisFrame / 4;
                }

                if (metadata & 0x20000000) // 16-bit samples
                {
                    fix32_t sumPrim = samples16[highWeightFrame].primary_;
                    fix32_t lowPrim = samples16[lowWeightFrame].primary_;
                    sumPrim = sumPrim * 3 + lowPrim;
                    out[0] = sumPrim >> 2;
                    fix32_t sumSec = samples16[highWeightFrame].secondary_;
                    fix32_t lowSec = samples16[lowWeightFrame].secondary_;
                    sumSec = sumSec * 3 + lowSec;
                    out[1] = sumSec >> 2;
                    return;
                }
                else
                {
                    int64_t highPrim = (int64_t)samples[highWeightFrame].primary_ * 3;
                    int64_t lowPrim = samples[lowWeightFrame].primary_;
                    // Keep the accumulator initialization separate: it preserves the original
                    // compiler scheduling of the widened primary-sample sum.
                    int64_t sumPrim = lowPrim;
                    sumPrim = highPrim + lowPrim;
                    out[0] = sumPrim >> 2;
                    int64_t highSec = (int64_t)samples[highWeightFrame].secondary_ * 3;
                    out[1] = (highSec + samples[lowWeightFrame].secondary_) >> 2;
                    return;
                }
            }
            else // 2 mod 4: can do 50/50 averaging
            {
                averageIdx = thisFrame / 4;
                goto compute_average;
            }
        }
        else
        {
            thisFrame = thisFrame / 4;
            goto compute_directly;
        }
    }
}

compute_directly:
    if (metadata & 0x20000000)
    {
        out[0] = samples16[thisFrame].primary_;
        out[1] = samples16[thisFrame].secondary_;
    }
    else
    {
        out[0] = samples[thisFrame].primary_;
        out[1] = samples[thisFrame].secondary_;
    }
    return;
compute_average:
    if (metadata & 0x20000000)
    {
        out[0] = ((samples16 + averageIdx)->primary_ + (samples16 + averageIdx + 1)->primary_) >> 1;
        out[1] = ((samples16 + averageIdx)->secondary_ + (samples16 + averageIdx + 1)->secondary_) >> 1;
    }
    else
    {
        out[0] = ((samples + averageIdx)[0].primary_ + (samples + averageIdx)[1].primary_) >> 1;
        out[1] = ((samples + averageIdx)[0].secondary_ + (samples + averageIdx)[1].secondary_) >> 1;
    }
}
