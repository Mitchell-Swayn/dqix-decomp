#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02160F60; symbol: Unclassified_GetIndexedObjectRecord; size: 0x3C.
// Returns the indexed 0x28-byte record after validating both object links.
extern "C" void *BattleScene_GetPreviousActionRecord(void *object) {
unsigned char *base=(unsigned char*)object; void *list=*(void**)(base+0x55d8); if(!list)return 0; unsigned char *records=*(unsigned char**)(base+0x29c); if(!records)return 0; return records+0x821c+((unsigned int)list-1)*0x28;
}
