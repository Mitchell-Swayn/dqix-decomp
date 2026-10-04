#include "Graphics/NSBXX/JACInternal.h"

void CalculateTranslationAmountSmooth(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac)
{
    unsigned int frameIdx = time >> 12;
    fix32_t* samples = (fix32_t*)((intptr_t)jac + channel->samplesOffset_);
    fix16_t* samples16 = (fix16_t*)samples;
    unsigned int flags = channel->metadata_;

    // at end of animation
    if (jac->numFrames_ - 1 == frameIdx)
    {
        unsigned int sampleIdx = frameIdx;
        if (flags & 0xc0000000) // log-rate != 0, i.e. samples less than once per frame
        {
            if (flags & 0x40000000) // log-rate = 1
            {
                sampleIdx = (frameIdx & 1) + (frameIdx >> 1);
            }
            else // log-rate = 2
            {
                sampleIdx = (frameIdx & 3) + (frameIdx >> 2);
            }
        }

        if (jac->unk_8 & 2) // probably means animation is looping?
        {
            fix32_t timeFraction = time & 0xfff;
            fix32_t lerp0;
            fix32_t lerp1;
            if (flags & 0x20000000) // 16-bit samples
            {
                lerp0 = samples16[sampleIdx];
                lerp1 = samples16[0];
            }
            else
            {
                lerp0 = samples[sampleIdx];
                lerp1 = samples[0];
            }
            *out = lerp0 + ((timeFraction * (lerp1 - lerp0)) >> 12);
            return;
        }
        else
        {
            fix32_t finalValue;
            if (flags & 0x20000000) // 16-bit sample
            {
                finalValue = samples16[sampleIdx];
            }
            else
                finalValue = samples[sampleIdx];
            *out = finalValue;
            return;
        }
    }

    int preMultiply;
    int rightShift;

    if ((flags & 0xc0000000) != 0)
    {
        unsigned int endFrame = (flags & 0x1fff0000) >> 0x10;
        if (flags & 0x40000000) // log-rate = 1
        {
            if (frameIdx >= endFrame)
                frameIdx = endFrame / 2;
            else
            {
                frameIdx = frameIdx / 2;
                time &= 0x1fff;
                preMultiply = 2;
                rightShift = 1;
                goto skip_default_values;
            }
        }
        else // log-rate 2
        {
            if (frameIdx >= endFrame)
                frameIdx = (frameIdx & 3) + (frameIdx / 4);
            else
            {
                frameIdx = frameIdx / 4;
                time &= 0x3fff;
                preMultiply = 4;
                rightShift = 2;
                goto skip_default_values;
            }               
        }
    }
default_values:
    time &= 0xfff;
    preMultiply = 1;
    rightShift = 0;
skip_default_values:
    fix32_t lerp0;
    fix32_t lerp1;
    if (flags & 0x20000000) // 16-bit samples
    {
        lerp0 = (samples16 + frameIdx)[0];
        lerp1 = (samples16 + frameIdx)[1];
    }
    else
    {
        lerp0 = (samples + frameIdx)[0];
        lerp1 = (samples + frameIdx)[1];
    }

    *out = (lerp0 * preMultiply + ((time * (lerp1 - lerp0)) >> 12)) >> rightShift;
}
