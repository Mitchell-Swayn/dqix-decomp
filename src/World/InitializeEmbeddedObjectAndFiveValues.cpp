#include "World/Object3D.h"
extern "C" void InitializeSignedAllocatorLists(void*);
// Original: arm9/main @ 0x02055558; symbol: func_02055558; size: 0x48.
extern "C" int InitializeEmbeddedObjectAndFiveValues(unsigned int* object, unsigned int first, unsigned int second,
                              unsigned int third, unsigned int fourth, unsigned int fifth)
{
    ((Object3D*)((unsigned char*)object + 0x14))->Initialize();
    InitializeSignedAllocatorLists((unsigned char*)object + 0xc0);
    object[0] = first;
    object[1] = second;
    object[2] = fifth;
    object[3] = third;
    object[4] = fourth;
    return 1;
}
