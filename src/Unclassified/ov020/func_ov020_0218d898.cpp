#pragma opt_propagation off
#pragma optimize_for_size off
struct Overlay20BrightnessTransition { float current; int target; int duration; };
struct Overlay20TimedState {
    unsigned char earlierFields[0x4e4];
    int countdown;
    Overlay20BrightnessTransition mainBrightness, subBrightness;
    inline bool HasCountdown() const { return countdown > 0; }
    inline bool HasMainTransition() const { return mainBrightness.duration > 0; }
    inline bool HasSubTransition() const { return subBrightness.duration > 0; }
};
// Original: arm9/ov020 @ 0x0218D898; symbol: func_ov020_0218d898; size: 0x40.
extern "C" bool func_ov020_0218d898(Overlay20TimedState* state)
{
    if (state->HasMainTransition() || state->HasSubTransition()) return true;
    return false;
}
