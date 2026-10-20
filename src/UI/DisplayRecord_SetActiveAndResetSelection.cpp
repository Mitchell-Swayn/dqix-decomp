#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02050400; symbol: func_02050400; size: 0x2C.
ARM void DisplayRecord_SetActiveAndResetSelection(unsigned char* self,unsigned int value) { self[216]=(self[216]&~1)|(value&1);self[216]|=2;self[217]=0;self[218]=0; }
}
