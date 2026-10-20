#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void LinkedQueue_InitializeNodeStatus(signed char* p);

// Original: arm9/ov003 @ 0x0217EF24; symbol: func_ov003_0217ef24; size: 0x34.
// Initializes base words, type 42, zero state fields, and a byte sentinel.
extern "C" void Town_InitializeQueuedFacilityRecord(unsigned char* object)
{
    LinkedQueue_InitializeNodeStatus((signed char*)object);
    object[0] = 42;
    *(int*)(object + 0xc) = 0;
    *(int*)(object + 0x10) = 0;
    object[0x3a] = 0;
    object[0x3b] = 0;
    object[0x28] = 255;
}
