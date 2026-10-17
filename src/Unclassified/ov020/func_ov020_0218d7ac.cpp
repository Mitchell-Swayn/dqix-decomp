struct Overlay20BrightnessTransition { float current; int target; int duration; };
struct Overlay20TimedState {
    unsigned char earlierFields[0x4e4];
    int countdown;
    Overlay20BrightnessTransition mainBrightness, subBrightness;
};
extern "C" void Graphics_WriteSignedBrightnessMagnitudeAndMode(volatile unsigned short* masterBrightness, int value);
extern "C" int Graphics_DecodeSignedBrightness(volatile unsigned short* masterBrightness);
// Original: arm9/ov020 @ 0x0218D7AC; symbol: func_ov020_0218d7ac; size: 0x54.
extern "C" void func_ov020_0218d7ac(Overlay20TimedState* state, int target, int duration)
{
    if (duration == 0) {
        Graphics_WriteSignedBrightnessMagnitudeAndMode((volatile unsigned short*)0x0400006c, target);
        state->mainBrightness.current = (float)target;
        state->mainBrightness.target = target;
        state->mainBrightness.duration = 0;
    } else {
        state->mainBrightness.current = (float)Graphics_DecodeSignedBrightness((volatile unsigned short*)0x0400006c);
        state->mainBrightness.target = target;
        state->mainBrightness.duration = duration;
    }
}
