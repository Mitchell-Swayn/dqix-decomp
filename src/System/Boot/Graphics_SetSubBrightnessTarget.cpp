struct Overlay20BrightnessTransition { float current; int target; int duration; };
struct Overlay20TimedState {
    unsigned char earlierFields[0x4e4];
    int countdown;
    Overlay20BrightnessTransition mainBrightness, subBrightness;
};
extern "C" void Graphics_WriteSignedBrightnessMagnitudeAndMode(volatile unsigned short* masterBrightness, int value);
extern "C" int Graphics_DecodeSignedBrightness(volatile unsigned short* masterBrightness);
// Original: arm9/ov020 @ 0x0218D800; symbol: func_ov020_0218d800; size: 0x54.
extern "C" void Graphics_SetSubBrightnessTarget(Overlay20TimedState* state, int target, int duration)
{
    if (duration == 0) {
        Graphics_WriteSignedBrightnessMagnitudeAndMode((volatile unsigned short*)0x0400106c, target);
        state->subBrightness.current = (float)target;
        state->subBrightness.target = target;
        state->subBrightness.duration = 0;
    } else {
        state->subBrightness.current = (float)Graphics_DecodeSignedBrightness((volatile unsigned short*)0x0400106c);
        state->subBrightness.target = target;
        state->subBrightness.duration = duration;
    }
}
