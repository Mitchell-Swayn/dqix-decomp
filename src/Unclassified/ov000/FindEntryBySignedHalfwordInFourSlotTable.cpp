#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02162D88; symbol: func_ov000_02162d88; size: 0x3C.
extern "C" void* FindEntryBySignedHalfwordInFourSlotTable(unsigned char* object, int id) { for (int i = 0; i < 4; ++i) { void* entry = *(void**)(object + 0xeb8 + i * 4); if (entry) { short entryId = *(short*)((unsigned char*)entry + 2); if (id == entryId) return entry; } } return 0; }
