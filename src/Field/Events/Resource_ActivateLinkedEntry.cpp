#include <globaldefs.h>
ARM

extern "C" void InitializeType23LinkedNode(void *);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int *, unsigned int);

// Original: arm9/ov017 @ 0x021B66F0; symbol: func_ov017_021b66f0; size: 0x38.
extern "C" void Resource_ActivateLinkedEntry(void *object) {
    InitializeType23LinkedNode(*(void **)((char *)object + 0x3B00));
    LinkedQueue_AppendAndMarkActive(*(unsigned int **)((char *)object + 0x36FC), *(unsigned int *)((char *)object + 0x3B00));
    *((unsigned char *)(*(unsigned int **)((char *)object + 0x3B00)) + 0x1F) = 2;
}
