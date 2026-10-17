#include <globaldefs.h>
ARM
extern "C" void Memory_Clear22BytesAndSetTwoSentinels(void*);
// Original: arm9/ov023 @ 0x021F6EB8; symbol: func_ov023_021f6eb8; size: 0x20.
extern "C" void Memory_InitializeRecordAtIndexIfLessThanThree(char* p, int index) { if (index < 3) Memory_Clear22BytesAndSetTwoSentinels(p + 0x30 + index * 0x16); }
