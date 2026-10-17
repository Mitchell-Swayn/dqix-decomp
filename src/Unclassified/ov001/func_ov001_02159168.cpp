#include <globaldefs.h>
ARM
extern "C" void *Queue_AppendNodeFromFreeList(void *queue);

// Original: arm9/ov001 @ 0x02159168; symbol: func_ov001_02159168; size: 0x48.
extern "C" void func_ov001_02159168(void *queue, unsigned int first, unsigned int second, unsigned int third, unsigned int fourth, unsigned int fifth, unsigned char sixth) {
    unsigned char *entry = (unsigned char *)Queue_AppendNodeFromFreeList(queue);
    if (entry == 0) return;
    *(unsigned int *)entry = 0xe;
    *(unsigned int *)(entry + 4) = first;
    *(unsigned int *)(entry + 8) = second;
    *(unsigned int *)(entry + 0xc) = third;
    *(unsigned int *)(entry + 0x1c) = fourth;
    *(unsigned int *)(entry + 0x20) = fifth;
    *(unsigned int *)(entry + 0x24) = sixth;

}
