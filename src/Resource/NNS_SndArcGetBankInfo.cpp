#include <globaldefs.h>

ARM
extern "C" {
struct Owner { unsigned char pad[0x8c]; unsigned char *data; };
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Owner *NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020BD51C; symbol: func_020bd51c; size: 0x64.
unsigned char *NNS_SndArcGetBankInfo(int index) {
    Owner *owner = NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
    unsigned char *base = owner->data;
    unsigned int offset = *(unsigned int *)(base+16);
    unsigned int *table = offset == 0 ? 0 : (unsigned int *)(base+offset);
    if (!table) return 0;
    if (index < 0) return 0;
    if ((unsigned int)index >= *table) return 0;
    offset = ((unsigned int *)((unsigned char *)table + index*4))[1];
    base = owner->data;
    return offset == 0 ? 0 : base+offset;
}
}
