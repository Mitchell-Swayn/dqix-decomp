#include <globaldefs.h>
ARM
extern "C" void* OV017_ReadWordField6AC(void*);
// Original: arm9/ov017 @ 0x021C9D08; symbol: func_ov017_021c9d08; size: 0x24.
extern "C" void* Graphics_SetLightingRecordByteFromArgument(unsigned int unused0, unsigned char* record, unsigned int unused2, char* base) { void* q = OV017_ReadWordField6AC(*(void**)(base + 0x3718)); if (q) *((unsigned char*)q + 0xeb4) = record[4]; return q; }
