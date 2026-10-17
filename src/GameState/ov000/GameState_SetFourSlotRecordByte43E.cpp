#include <globaldefs.h>
ARM
extern "C" void* FindFourSlotRecordByIndex(unsigned int, unsigned int);
// Original: arm9/ov000 @ 0x02162B70; symbol: func_ov000_02162b70; size: 0x20.
extern "C" void* GameState_SetFourSlotRecordByte43E(unsigned char* base, unsigned int index, unsigned int value) { void* p = FindFourSlotRecordByIndex((unsigned int)(base + 0x3760), index); if (p) *((unsigned char*)p + 0x43e) = value; return p; }
