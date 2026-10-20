#include <globaldefs.h>
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int* NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020BD454; symbol: func_020bd454; size: 0x64.
extern "C" int NNS_SndArcGetSeqInfo(unsigned int index) {
    char* owner=(char*)NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage[0];
    volatile int* rootSlot=(volatile int*)(owner+0x8C);
    int* root=(int*)rootSlot[0];
    int offset=*(int*)((char*)root+8);
    int* table=offset==0 ? 0 : (int*)((char*)root+offset);
    if(table==0) return 0;
    if((int)index<0) return 0;
    if(index >= (unsigned int)table[0]) return 0;
    int relative=*(int*)((char*)table + (index << 2) + 4);
    int baseValue=rootSlot[0];
    if(relative==0) return 0;
    return baseValue+relative;
}
