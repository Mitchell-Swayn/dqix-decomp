#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" unsigned char data_02114e20[];extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);extern "C" void Object_ClearInitialWordAndTwoBytes(void*);
// Original: arm9/main @ 0x0209CD24; symbol: func_0209cd24; size: 0x2C.
extern "C" void Memory_FreePointedBufferAndResetOwner(void** p){if(*p)Memory_FreeThroughAllocatorUnion(data_02114e20,*p);Object_ClearInitialWordAndTwoBytes(p);}
