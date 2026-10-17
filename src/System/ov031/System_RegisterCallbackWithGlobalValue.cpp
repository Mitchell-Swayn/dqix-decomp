#include <globaldefs.h>
ARM
extern "C" int func_ov031_0223fd9c(void (*)(void));
extern "C" unsigned int data_ov031_02290da0[];
extern "C" void Unclassified_RunRegisteredCallbacksAndCleanup(void);
// Original: arm9/ov031 @ 0x0223E8AC; symbol: func_ov031_0223e8ac; size: 0x28.
extern "C" int System_RegisterCallbackWithGlobalValue(unsigned int value) { data_ov031_02290da0[5] = 0; data_ov031_02290da0[0] = value; return func_ov031_0223fd9c(Unclassified_RunRegisteredCallbacksAndCleanup); }
