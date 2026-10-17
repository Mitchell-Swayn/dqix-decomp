// Original: arm9/main @ 0x0202E9A4; symbol: func_0202e9a4; size: 0x48.
#include <globaldefs.h>

extern int fix32sin(int);
extern int fix32cos(int);
struct AngleState { char unknown[0x58]; int angle; int sine; int cosine; };
// ARM9 main, original func_0202e9a4 at 0x0202e9a4.
// Proposed semantic name: SetAngleAndCacheTrig.
extern "C" ARM void SetAngleAndCacheTrig(AngleState *state, int angle)
{
    // Repeating this expression lets MWCC retain its common result for both calls.
    state->angle = angle;
    state->sine = fix32sin((int)(((long long)angle * 71 + 0x800) >> 12));
    state->cosine = fix32cos((int)(((long long)angle * 71 + 0x800) >> 12));
}
