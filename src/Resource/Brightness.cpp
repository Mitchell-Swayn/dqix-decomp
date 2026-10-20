#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include <globaldefs.h>

#if defined(jpn)
#define Graphics_WriteSignedBrightnessMagnitudeAndMode func_020c546c
#define Graphics_DecodeSignedBrightness func_020c5494
#define DisplayOverlay_GetInstance func_020dc998
#define DisplayOverlay_InterceptBrightnessChange func_020dd3d4
#endif

// Temporary internal wrappers
extern "C"
{
    // write brightness to master register
    void Graphics_WriteSignedBrightnessMagnitudeAndMode(volatile unsigned short *reg, int brightness);
    // get brightness from master register
    int Graphics_DecodeSignedBrightness(volatile unsigned short *reg);

    void *DisplayOverlay_GetInstance();
    int DisplayOverlay_InterceptBrightnessChange(void *unk, int screen, int brightness, unsigned int duration);
}
#define REG_MASTER_BRIGHT ((volatile unsigned short *) 0x0400006C)
#define REG_MASTER_BRIGHT_SUB ((volatile unsigned short *) 0x0400106C)

// helper functions to be inlined, needs to return int to get "? 1 : 0" behaviour
static inline int IsTransitioningMain(GameResources* res) { return res->mainBrightnessTimeRemaining > 0; }
static inline int IsTransitioningSub(GameResources* res) { return res->subBrightnessTimeRemaining > 0; }

// usa: func_0203aee0
// Original: arm9/main @ 0x0203AEE0; symbol: _Z25InitializeBrightnessStateP13GameResources; size: 0x64.
void InitializeBrightnessState(GameResources* resources)
{
    resources->brightnessFlags_0 = 0;
    resources->brightnessFlags_4 = 0;
    resources->brightnessFlags_8 = 0;

    resources->mainBrightnessTimeRemaining = 0;
    resources->subBrightnessTimeRemaining  = 0;

    resources->mainBrightnessLocked = false;
    resources->subBrightnessLocked  = false;
    resources->mainBrightnessDirty  = false;
    resources->subBrightnessDirty   = false;

    resources->allowBrightnessApply = true;

    resources->mainBrightness = (float) Graphics_DecodeSignedBrightness(REG_MASTER_BRIGHT);
    resources->subBrightness = (float) Graphics_DecodeSignedBrightness(REG_MASTER_BRIGHT_SUB);
}

// usa: func_0203af44
// Original: arm9/main @ 0x0203AF44; symbol: _Z4StubP13GameResources; size: 0x4.
void Stub(GameResources*) {}

// usa: func_0203af48
// Original: arm9/main @ 0x0203AF48; symbol: _Z27UpdateBrightnessTransitionsP13GameResources; size: 0x138.
void UpdateBrightnessTransitions(GameResources* resources)
{
    int delta = GameState::GetInstance()->GetEffectiveDeltaTime();

    if (IsTransitioningMain(resources))
    {
        resources->mainBrightness += (float)delta * (((float)resources->mainBrightnessTarget - resources->mainBrightness) /
                                                    (float)resources->mainBrightnessTimeRemaining);
        resources->mainBrightnessTimeRemaining -= delta;

        if (resources->mainBrightnessTimeRemaining <= 0)
            resources->mainBrightness = (float)resources->mainBrightnessTarget;

        resources->mainBrightnessDirty = true;
    }

    if (IsTransitioningSub(resources))
    {
        resources->subBrightness += (float)delta * (((float)resources->subBrightnessTarget - resources->subBrightness) /
                                                   (float)resources->subBrightnessTimeRemaining);
        resources->subBrightnessTimeRemaining -= delta;

        if (resources->subBrightnessTimeRemaining <= 0)
            resources->subBrightness = (float)resources->subBrightnessTarget;

        resources->subBrightnessDirty = true;
    }
}

// usa: func_0203b080
// Original: arm9/main @ 0x0203B080; symbol: _Z15ApplyBrightnessP13GameResources; size: 0x78.
void ApplyBrightness(GameResources* resources)
{
    if (resources->allowBrightnessApply == 0) return;

    resources->allowBrightnessApply = 0;

    if (resources->mainBrightnessDirty)
        Graphics_WriteSignedBrightnessMagnitudeAndMode(REG_MASTER_BRIGHT, (int) resources->mainBrightness);

    resources->mainBrightnessDirty = false;

    if (resources->subBrightnessDirty)
        Graphics_WriteSignedBrightnessMagnitudeAndMode(REG_MASTER_BRIGHT_SUB, (int) resources->subBrightness);

    resources->subBrightnessDirty = false;
}

// usa: func_0203b0f8
// Original: arm9/main @ 0x0203B0F8; symbol: _Z24UpdateAndApplyBrightnessP13GameResources; size: 0x18.
void UpdateAndApplyBrightness(GameResources* resources)
{
    UpdateBrightnessTransitions(resources);
    ApplyBrightness(resources);
}

// usa: func_0203b110
// Original: arm9/main @ 0x0203B110; symbol: _Z17SetMainBrightnessP13GameResourcesii; size: 0x8C.
void SetMainBrightness(GameResources* resources, int brightness, int duration)
{
    if (resources->mainBrightnessLocked)
        return;

    void *unk = DisplayOverlay_GetInstance();

    if (DisplayOverlay_InterceptBrightnessChange(unk, 0, brightness, duration) == 0)
        return;

    if (duration == 0)
    {
        resources->mainBrightness              = (float)brightness;
        resources->mainBrightnessTarget        = brightness;
        resources->mainBrightnessTimeRemaining = 0;
        resources->mainBrightnessDirty         = true;
    }
    else
    {
        resources->mainBrightnessTarget        = brightness;
        resources->mainBrightnessTimeRemaining = (int)((float)duration * 16.667f);
    }
}

// usa: func_0203b19c
// Original: arm9/main @ 0x0203B19C; symbol: _Z16SetSubBrightnessP13GameResourcesii; size: 0x8C.
void SetSubBrightness(GameResources* resources, int brightness, int duration)
{
    if (resources->subBrightnessLocked)
        return;

    void *unk = DisplayOverlay_GetInstance();

    if (DisplayOverlay_InterceptBrightnessChange(unk, 1, brightness, duration) == 0)
        return;

    if (duration == 0)
    {
        resources->subBrightness              = (float)brightness;
        resources->subBrightnessTarget        = brightness;
        resources->subBrightnessTimeRemaining = 0;
        resources->subBrightnessDirty         = true;
    }
    else
    {
        resources->subBrightnessTarget        = brightness;
        resources->subBrightnessTimeRemaining = (int)((float)duration * 16.667f);
    }    
}

// usa: func_0203b228
// Original: arm9/main @ 0x0203B228; symbol: _Z13SetBrightnessP13GameResourcesii; size: 0x28.
void SetBrightness(GameResources* resources, int brightness, int duration)
{
    SetMainBrightness(resources, brightness, duration);
    SetSubBrightness(resources, brightness, duration);
}

// usa: func_0203b250
// Original: arm9/main @ 0x0203B250; symbol: _Z24SetAndLockMainBrightnessP13GameResourcesii; size: 0x18.
void SetAndLockMainBrightness(GameResources* resources, int brightness, int duration)
{
    SetMainBrightness(resources, brightness, duration);
    resources->mainBrightnessLocked = true;
}

// usa: func_0203b268
// Original: arm9/main @ 0x0203B268; symbol: _Z23SetAndLockSubBrightnessP13GameResourcesii; size: 0x18.
void SetAndLockSubBrightness(GameResources* resources, int brightness, int duration)
{
    SetSubBrightness(resources, brightness, duration);
    resources->subBrightnessLocked = true;
}

// usa: func_0203b280
// Original: arm9/main @ 0x0203B280; symbol: _Z20SetAndLockBrightnessP13GameResourcesii; size: 0x38.
void SetAndLockBrightness(GameResources* resources, int brightness, int duration)
{
    SetMainBrightness(resources, brightness, duration);
    resources->mainBrightnessLocked = true;

    SetSubBrightness(resources, brightness, duration);
    resources->subBrightnessLocked = true;
}

// usa: func_0203b2b8
// Original: arm9/main @ 0x0203B2B8; symbol: _Z26UnlockAndSetMainBrightnessP13GameResourcesii; size: 0x14.
void UnlockAndSetMainBrightness(GameResources* resources, int brightness, int duration)
{
    resources->mainBrightnessLocked = false;
    SetMainBrightness(resources, brightness, duration);
}

// usa: func_0203b2cc
// Original: arm9/main @ 0x0203B2CC; symbol: _Z25UnlockAndSetSubBrightnessP13GameResourcesii; size: 0x14.
void UnlockAndSetSubBrightness(GameResources* resources, int brightness, int duration)
{
    resources->subBrightnessLocked = false;
    SetSubBrightness(resources, brightness, duration);
}

// usa: func_0203b2e0
// Original: arm9/main @ 0x0203B2E0; symbol: _Z22UnlockAndSetBrightnessP13GameResourcesii; size: 0x38.
void UnlockAndSetBrightness(GameResources* resources, int brightness, int duration)
{
    resources->mainBrightnessLocked = false;
    SetMainBrightness(resources, brightness, duration);

    resources->subBrightnessLocked = false;
    SetSubBrightness(resources, brightness, duration);
}

// usa: func_0203b318
// Original: arm9/main @ 0x0203B318; symbol: _Z31SetMainBrightnessWithDurationMsP13GameResourcesij; size: 0x80.
void SetMainBrightnessWithDurationMs(GameResources* resources, int brightness, unsigned int durationMs)
{
    if (resources->mainBrightnessLocked)
        return;

    void *unk = DisplayOverlay_GetInstance();
    unsigned int numFrames = (durationMs * 3) / 100;

    if (DisplayOverlay_InterceptBrightnessChange(unk, 0, brightness, numFrames) == 0)
        return;

    if (durationMs != 0)
    {
        resources->mainBrightnessTarget        = brightness;
        resources->mainBrightnessTimeRemaining = durationMs;
    }
    else
    {
        resources->mainBrightness              = (float) brightness;
        resources->mainBrightnessTarget        = brightness;
        resources->mainBrightnessTimeRemaining = 0;
        resources->mainBrightnessDirty         = true;
    }    
}

// usa: func_0203b398
// Original: arm9/main @ 0x0203B398; symbol: _Z32IsMainBrightnessTransitionActiveP13GameResources; size: 0x14.
int IsMainBrightnessTransitionActive(GameResources* resources)
{
    return resources->mainBrightnessTimeRemaining > 0;
}

// usa: func_0203b3ac
// Original: arm9/main @ 0x0203B3AC; symbol: _Z31IsSubBrightnessTransitionActiveP13GameResources; size: 0x14.
int IsSubBrightnessTransitionActive(GameResources* resources)
{
    return resources->subBrightnessTimeRemaining > 0;
}

// usa: func_0203b3c0
// Original: arm9/main @ 0x0203B3C0; symbol: _Z28IsBrightnessTransitionActiveP13GameResources; size: 0x40.
int IsBrightnessTransitionActive(GameResources* resources)
{
    return IsTransitioningMain(resources) || IsTransitioningSub(resources);
}

// usa: func_0203b400
// Original: arm9/main @ 0x0203B400; symbol: _Z32GetMainBrightnessTransitionStateP13GameResources; size: 0x38.
int GetMainBrightnessTransitionState(GameResources* resources)
{
    if (!IsTransitioningMain(resources))
        return 0;

    int state = 1;

    if (resources->mainBrightnessTarget < 0)
        state = 2;
    if (resources->mainBrightnessTarget > 0)
        state = 3;

    return state;
}

// usa: func_0203b438
// Original: arm9/main @ 0x0203B438; symbol: _Z31GetSubBrightnessTransitionStateP13GameResources; size: 0x38.
int GetSubBrightnessTransitionState(GameResources* resources)
{
    if (!IsTransitioningSub(resources))
        return 0;

    int state = 1;

    if (resources->subBrightnessTarget < 0)
        state = 2;
    if (resources->subBrightnessTarget > 0)
        state = 3;

    return state;
}

// usa: func_0203b470
// Original: arm9/main @ 0x0203B470; symbol: _Z29GetBrightnessTransitionStatesP13GameResources; size: 0x28.
unsigned short GetBrightnessTransitionStates(GameResources* resources)
{
    int mainState = GetMainBrightnessTransitionState(resources);
    int subState  = GetSubBrightnessTransitionState(resources);

    return mainState | (subState << 8);
}