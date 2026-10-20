#pragma opt_propagation off
#pragma optimize_for_size off
#include <GameState/GameState.h>
struct Overlay20BrightnessTransition { float current; int target; int duration; };
struct Overlay20TimedState {
    unsigned char earlierFields[0x4e4];
    int countdown;
    Overlay20BrightnessTransition mainBrightness, subBrightness;
};
inline bool HasRemainingTransition(int duration) { return duration > 0; }
extern "C" void Graphics_WriteSignedBrightnessMagnitudeAndMode(volatile unsigned short* masterBrightness, int value);
// Original: arm9/ov020 @ 0x0218D644; symbol: func_ov020_0218d644; size: 0x168.
extern "C" void Graphics_AdvanceBrightnessTransitions(Overlay20TimedState* state)
{
    int elapsed = GameState::GetInstance()->GetEffectiveDeltaTime();
    int remaining = state->mainBrightness.duration;
    if (HasRemainingTransition(remaining)) {
        float milliseconds = (float)elapsed;
        float distance = (float)state->mainBrightness.target - state->mainBrightness.current;
        state->mainBrightness.current += milliseconds * (distance / (float)remaining);
        state->mainBrightness.duration -= elapsed;
        if (state->mainBrightness.duration <= 0) {
            state->mainBrightness.current = (float)state->mainBrightness.target;
            state->mainBrightness.duration = 0;
        }
        Graphics_WriteSignedBrightnessMagnitudeAndMode((volatile unsigned short*)0x0400006c, (int)state->mainBrightness.current);
    }
    remaining = state->subBrightness.duration;
    if (HasRemainingTransition(remaining)) {
        float milliseconds = (float)elapsed;
        float distance = (float)state->subBrightness.target - state->subBrightness.current;
        state->subBrightness.current += milliseconds * (distance / (float)remaining);
        state->subBrightness.duration -= elapsed;
        if (state->subBrightness.duration <= 0) {
            state->subBrightness.current = (float)state->subBrightness.target;
            state->subBrightness.duration = 0;
        }
        Graphics_WriteSignedBrightnessMagnitudeAndMode((volatile unsigned short*)0x0400106c, (int)state->subBrightness.current);
    }
}
