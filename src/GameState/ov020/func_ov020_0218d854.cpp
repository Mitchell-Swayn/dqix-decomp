#pragma opt_propagation off
#include <GameState/GameState.h>
struct Overlay20BrightnessTransition { float current; int target; int duration; };
struct Overlay20TimedState {
    unsigned char earlierFields[0x4e4];
    int countdown;
    Overlay20BrightnessTransition mainBrightness, subBrightness;
    inline bool HasCountdown() const { return countdown > 0; }
    inline bool HasMainTransition() const { return mainBrightness.duration > 0; }
    inline bool HasSubTransition() const { return subBrightness.duration > 0; }
};
// Original: arm9/ov020 @ 0x0218D854; symbol: func_ov020_0218d854; size: 0x44.
extern "C" void func_ov020_0218d854(Overlay20TimedState* state)
{
    int elapsed = GameState::GetInstance()->GetEffectiveDeltaTime();
    if (state->HasCountdown()) {
        state->countdown -= elapsed;
        if (state->countdown <= 0) state->countdown = 0;
    }
}
