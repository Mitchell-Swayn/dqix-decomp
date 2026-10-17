#include "Graphics/AlphaTween.h"

// Original: arm9/main @ 0x020349C8; symbol: _ZNK10AlphaTween9GetTargetEv; size: 0x20.
float AlphaTween::GetTarget() const
{
    return (target * 31u) / 65535.0f;
}

// Original: arm9/main @ 0x020349E8; symbol: _ZN10AlphaTween15SetCurrentValueEf; size: 0x34.
void AlphaTween::SetCurrentValue(float to)
{
    current = 65535.0f * (to / 31.0f);
}

// Original: arm9/main @ 0x02034A1C; symbol: _ZN10AlphaTween5ResetEv; size: 0x14.
void AlphaTween::Reset()
{
    memset(this, 0, sizeof(AlphaTween));
}

// Original: arm9/main @ 0x02034A30; symbol: _ZN10AlphaTween7AdvanceEi; size: 0x104.
float AlphaTween::Advance(int numTicks)
{
    if (changePerTick == 0.0f)
        return (current * 31u) / 65535.0f;
    
    float priorValueNorm = (current * 31u) / 65535.0f;
    float targetValueNorm = (target * 31u) / 65535.0f;

    float newValueNorm = priorValueNorm + (changePerTick * numTicks);
    if (0.0f < changePerTick && targetValueNorm < newValueNorm)
    {
        changePerTick = 0.0f;
        newValueNorm = targetValueNorm;
    }
    else if (changePerTick < 0.0f && newValueNorm < targetValueNorm)
    {
        changePerTick = 0.0f;
        newValueNorm = targetValueNorm;
    }

    current = 65535.0f * (newValueNorm / 31.0f);
    return newValueNorm;
}

// Original: arm9/main @ 0x02034B34; symbol: _ZN10AlphaTween14ConfigureTweenEii; size: 0x90.
void AlphaTween::ConfigureTween(int targetAlpha, int duration)
{
    float initialNorm = (current * 31u) / 65535.0f;
    float targetNorm = targetAlpha;
    target = 65535.0f * (targetNorm / 31.0f);

    if (duration <= 0)
        changePerTick = 0.0f;
    else
        changePerTick = (targetNorm - initialNorm) / duration;
}