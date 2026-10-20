/* Store a seed congruent to5 modulo8 and an odd step in the wireless RNG state. */
#pragma dont_inline on
typedef struct { unsigned short seed, step; } WirelessRandomParameters;
typedef struct {
    unsigned char unknown000[0x5f0];
    unsigned short seed, step;
} WirelessRandomSeedView;
// Original: arm7/wram @ 0x0380FFF4; shared wireless driver-state pointer.
extern WirelessRandomSeedView *ARM7_WirelessRandomSeedState;
// Original: arm7/mainram @ 0x027EB084; symbol: func_027eb084; size: 0x34.
void ARM7_SetWirelessRandomState(unsigned int seed, unsigned int step)
{
    WirelessRandomSeedView *state = ARM7_WirelessRandomSeedState;
    WirelessRandomParameters *parameters = (WirelessRandomParameters *)((unsigned char *)state + 0x5f0);
    state->seed = (seed & 0xfff8) + 5;
    parameters->step = step | 1;
}
