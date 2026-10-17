#include <globaldefs.h>
ARM
extern "C" void GameState_ComputeNextThresholdAndPartyContribution(void *a, void *b, void *c, void *d, void *e);
extern "C" void func_ov004_02167b78(void *state, int value);
extern "C" void func_ov004_02167adc(void *state);
extern "C" void func_ov011_021848a0(void *state, unsigned value);
// Original: arm9/ov004 @ 0x02167EB0; symbol: func_ov004_02167eb0; size: 0x6C.
extern "C" int GameState_ConfigureFieldFromCalculatedStatus(void *state) {
    unsigned char values[0x0c];
    GameState_ComputeNextThresholdAndPartyContribution(values + 6, values + 4, values + 2, values, values + 8);
    func_ov004_02167b78(state, 0);
    func_ov004_02167adc(state);
    if (values[0]) func_ov011_021848a0(state, 0x28);
    else func_ov011_021848a0(state, 0x33);
    return 0;
}
