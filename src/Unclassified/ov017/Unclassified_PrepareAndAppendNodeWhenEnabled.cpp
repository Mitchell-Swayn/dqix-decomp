#include <globaldefs.h>
ARM
extern unsigned char data_ov017_021d76d8[];
extern "C" void Resource_InitializeType3ARecordAndAllocator(void *);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned int *, unsigned int);
// Original: arm9/ov017 @ 0x021A4DD0; symbol: func_ov017_021a4dd0; size: 0x3C.
extern "C" void Unclassified_PrepareAndAppendNodeWhenEnabled(void *self) {
    unsigned int *list = *(unsigned int **)((char *)self + 0x36FC);
    unsigned int node = *(unsigned int *)((char *)self + 0x3B84);
    if (*(signed char *)data_ov017_021d76d8 < 0) return;
    Resource_InitializeType3ARecordAndAllocator((void *)node);
    AppendLinkedNodeAndMarkActive(list, node);
}
