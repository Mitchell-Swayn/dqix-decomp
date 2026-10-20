#include <globaldefs.h>
extern "C" {
extern unsigned int Text_LoadItemNameRecord_PathDataPrmItemnameGp2;
extern unsigned int Text_LoadItemNameRecord_MarkupItemnameLGNat;
void LoadAndAllocateIndexedResourceWithOptionalLock(unsigned int, unsigned int *, int, int, int, unsigned int *);
// Original: arm9/main @ 0x020DCF7C; symbol: func_020dcf7c; size: 0x4C.
ARM void Text_LoadItemNameRecord(int param_1, unsigned int param_2, int param_3, int param_4) {
    if (param_1 > 0 && param_2 != 0) {
        LoadAndAllocateIndexedResourceWithOptionalLock(param_2, &Text_LoadItemNameRecord_MarkupItemnameLGNat, param_1, 0, 1, &Text_LoadItemNameRecord_PathDataPrmItemnameGp2);
    }
}
}
