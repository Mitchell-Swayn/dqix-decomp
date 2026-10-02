#include "GameState/GameState.h"
#include "TitleController.h"

extern "C" {
void func_020c39a0(volatile unsigned short* reg, int brightness);
int func_020c39c8(volatile unsigned short* reg);
}

static inline int IsMainTransitioning(TitleTransitionController* state) {
    return state->mainBrightness.timeRemaining > 0;
}
static inline int IsSubTransitioning(TitleTransitionController* state) {
    return state->subBrightness.timeRemaining > 0;
}
static inline int IsWaiting(TitleTransitionController* state) {
    return state->waitTimeRemaining > 0;
}

// Advance both brightness transitions and apply the interpolated values.
extern "C" void func_ov020_0218d644(TitleTransitionController* state) {
    int delta = GameState::GetInstance()->GetEffectiveDeltaTime();
    if (IsMainTransitioning(state)) {
        state->mainBrightness.current += (float)delta *
            (((float)state->mainBrightness.target - state->mainBrightness.current) /
             (float)state->mainBrightness.timeRemaining);
        state->mainBrightness.timeRemaining -= delta;
        if (state->mainBrightness.timeRemaining <= 0) {
            state->mainBrightness.current = (float)state->mainBrightness.target;
            state->mainBrightness.timeRemaining = 0;
        }
        func_020c39a0((volatile unsigned short*)0x0400006c, (int)state->mainBrightness.current);
    }
    if (IsSubTransitioning(state)) {
        state->subBrightness.current += (float)delta *
            (((float)state->subBrightness.target - state->subBrightness.current) /
             (float)state->subBrightness.timeRemaining);
        state->subBrightness.timeRemaining -= delta;
        if (state->subBrightness.timeRemaining <= 0) {
            state->subBrightness.current = (float)state->subBrightness.target;
            state->subBrightness.timeRemaining = 0;
        }
        func_020c39a0((volatile unsigned short*)0x0400106c, (int)state->subBrightness.current);
    }
}

// Start a main-screen transition; zero duration applies the target immediately.
extern "C" void func_ov020_0218d7ac(TitleTransitionController* state, int brightness, int duration) {
    if (duration == 0) {
        func_020c39a0((volatile unsigned short*)0x0400006c, brightness);
        state->mainBrightness.current = (float)brightness;
        state->mainBrightness.target = brightness;
        state->mainBrightness.timeRemaining = 0;
    } else {
        state->mainBrightness.current = (float)func_020c39c8((volatile unsigned short*)0x0400006c);
        state->mainBrightness.target = brightness;
        state->mainBrightness.timeRemaining = duration;
    }
}

// Start the corresponding sub-screen transition.
extern "C" void func_ov020_0218d800(TitleTransitionController* state, int brightness, int duration) {
    if (duration == 0) {
        func_020c39a0((volatile unsigned short*)0x0400106c, brightness);
        state->subBrightness.current = (float)brightness;
        state->subBrightness.target = brightness;
        state->subBrightness.timeRemaining = 0;
    } else {
        state->subBrightness.current = (float)func_020c39c8((volatile unsigned short*)0x0400106c);
        state->subBrightness.target = brightness;
        state->subBrightness.timeRemaining = duration;
    }
}

// Advance the logo/title wait timer, clamping it to zero.
extern "C" void func_ov020_0218d854(TitleTransitionController* state) {
    int delta = GameState::GetInstance()->GetEffectiveDeltaTime();
    if (IsWaiting(state)) {
        state->waitTimeRemaining -= delta;
        if (state->waitTimeRemaining <= 0)
            state->waitTimeRemaining = 0;
    }
}

extern "C" int func_ov020_0218d898(TitleTransitionController* state) {
    return IsMainTransitioning(state) || IsSubTransitioning(state);
}
