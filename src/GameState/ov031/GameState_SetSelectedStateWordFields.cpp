#include <globaldefs.h>
ARM
extern "C" void* SelectStateWordByPriorityMask(unsigned int);
extern "C" unsigned int ReadOptionalObjectByteNine(void);
// Original: arm9/ov031 @ 0x022134CC; symbol: func_ov031_022134cc; size: 0x24.
extern "C" void GameState_SetSelectedStateWordFields(unsigned int value) { unsigned int* state = (unsigned int*)SelectStateWordByPriorityMask(1); state[3] = value; *((unsigned char*)state + 0xa) = ReadOptionalObjectByteNine(); }
