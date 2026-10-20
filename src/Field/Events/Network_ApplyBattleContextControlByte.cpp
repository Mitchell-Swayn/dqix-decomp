#include <globaldefs.h>
ARM
extern "C" void* FieldBattle_GetScene(void*);
// Original: arm9/ov017 @ 0x021C9D08; symbol: func_ov017_021c9d08; size: 0x24.
extern "C" void* Network_ApplyBattleContextControlByte(unsigned int unused0, unsigned char* record, unsigned int unused2, char* base) { void* q = FieldBattle_GetScene(*(void**)(base + 0x3718)); if (q) *((unsigned char*)q + 0xeb4) = record[4]; return q; }
