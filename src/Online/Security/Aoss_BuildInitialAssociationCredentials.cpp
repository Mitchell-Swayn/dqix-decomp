#include <globaldefs.h>
THUMB
extern "C" void System_Copy8WithReversedPointers(void *, const void *, unsigned int);
extern "C" unsigned int Util_GetStringLength(const char *);
extern "C" char Aoss_ClassifySetupAccessPointMatches_TextESSIDAOSS[];
extern "C" char WirelessSetup_SendCompletionRequest_TextMELCO[];
// Original: arm9/ov031 @ 0x0221D310; symbol: func_ov031_0221d310; size: 0x44.
extern "C" int Aoss_BuildInitialAssociationCredentials(unsigned *state) {
    state[0] = Util_GetStringLength(Aoss_ClassifySetupAccessPointMatches_TextESSIDAOSS);
    System_Copy8WithReversedPointers(state + 1, Aoss_ClassifySetupAccessPointMatches_TextESSIDAOSS, state[0]);
    state[9] = 1;
    state[10] = Util_GetStringLength(WirelessSetup_SendCompletionRequest_TextMELCO);
    if (state[10] > 13) return -1;
    System_Copy8WithReversedPointers(state + 11, WirelessSetup_SendCompletionRequest_TextMELCO, state[10]);
    return 0;
}
