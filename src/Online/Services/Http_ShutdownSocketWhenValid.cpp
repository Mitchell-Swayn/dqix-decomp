#include <globaldefs.h>
ARM
extern "C" void NetworkSocket_Shutdown(int, unsigned int);
// Original: arm9/ov031 @ 0x02241518; symbol: func_ov031_02241518; size: 0x1C.
extern "C" void Http_ShutdownSocketWhenValid(unsigned int unused, int value) { if (value >= 0) NetworkSocket_Shutdown(value, 2); }
