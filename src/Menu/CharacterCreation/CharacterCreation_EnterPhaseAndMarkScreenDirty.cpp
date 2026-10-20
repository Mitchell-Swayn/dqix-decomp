#include <globaldefs.h>
ARM
struct PhaseState { char unknown0[0xc58]; signed char phase; unsigned char phaseStep; char unknown1[0x142]; unsigned flags; signed char maximumPhase[3]; unsigned char selection; };
// Original: arm9/ov009 @ 0x021855DC; symbol: func_ov009_021855dc; size: 0x58.
extern "C" void CharacterCreation_EnterPhaseAndMarkScreenDirty(PhaseState* state,int phase) {
 state->phase=phase; state->phaseStep=0;
 if(state->maximumPhase[state->selection]<phase) state->maximumPhase[state->selection]=phase;
 state->flags|=0x1100;
 if(phase!=9 && phase!=11 && phase!=12) state->flags|=0x80;
}
