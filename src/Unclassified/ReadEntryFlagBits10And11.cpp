#pragma optimization_level 4
#include <globaldefs.h>
struct PackedEntry { unsigned unused; const unsigned short* flags; };
// Original: arm9/main @ 0x0205B174; symbol: func_0205b174; size: 0x1C.
extern "C" unsigned ReadEntryFlagBits10And11(void*,const PackedEntry* entry) { if(entry==0)return 0;else return ((unsigned)*entry->flags>>10)&3; }
