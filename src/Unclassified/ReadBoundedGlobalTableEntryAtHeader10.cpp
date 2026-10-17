#include <globaldefs.h>

ARM
extern "C" {
struct Owner { unsigned char pad[0x8c]; unsigned char *data; };
extern Owner *data_02110370;
// Original: arm9/main @ 0x020BD51C; symbol: func_020bd51c; size: 0x64.
unsigned char *ReadBoundedGlobalTableEntryAtHeader10(int index) {
    Owner *owner = data_02110370;
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
