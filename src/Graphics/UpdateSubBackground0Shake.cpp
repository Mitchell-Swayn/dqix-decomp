// Original: arm9/main @ 0x0208CA00; symbol: func_0208ca00; size: 0x108.
#include <globaldefs.h>
struct SubBackgroundShakeState {
    char unknown00[0xc8]; float phase; char unknowncc[0xb];
    unsigned char elapsed; char unknownd8[2]; unsigned short flags;
};
extern "C" double Runtime_ComputeSine(double);
// ARM9 main, original func_0208ca00 at 0x0208ca00.
// Proposed semantic name: UpdateSubBackground0Shake.
extern "C" ARM int UpdateSubBackground0Shake(SubBackgroundShakeState *state, int ticks)
{
    if (state->flags & 0x80) {
        if (state->elapsed > 10) {
            state->flags &= ~0x80;
            *(volatile unsigned *)0x04001010 = 0;
            state->elapsed = 0;
        } else {
            float amplitude = 5.0f - 0.3f * state->elapsed;
            state->phase += 1.8f * ticks;
            state->elapsed += ticks;
            if (3.14f < state->phase) state->phase -= 6.28f;
            int offset = (int)(amplitude * (float)Runtime_ComputeSine((double)state->phase));
            *(volatile unsigned *)0x04001010 = offset & 0x1ff;
            return offset;
        }
    }
    return 0;
}
