#include <globaldefs.h>
#pragma force_active on
// stores a value in the first zero word at record offset 0x48 among eight records.
// Original: arm9/ov024 @ 0x021EB4E4; symbol: func_ov024_021eb4e4; size: 0x2c.
extern "C" void Combat_RememberTargetWorkInFirstFreeSlot(unsigned int* records, unsigned int value) { int i; for (i=0;i<8;i++) { unsigned int* slot=(unsigned int*)((char*)records+i*4+0x48); if (*slot==0) { *slot=value; return; } } }
