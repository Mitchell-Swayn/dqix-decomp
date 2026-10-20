#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionWorkspace(unsigned int);
extern "C" unsigned int Network_GetConnectionPhase(void);
// Original: arm9/ov031 @ 0x022134CC; symbol: func_ov031_022134cc; size: 0x24.
extern "C" void GameState_SetSelectedStateWordFields(unsigned int value) { unsigned int* state = (unsigned int*)Network_GetConnectionWorkspace(1); state[3] = value; *((unsigned char*)state + 0xa) = Network_GetConnectionPhase(); }
