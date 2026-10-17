#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void SeedGlobalSequenceFromHardwareIdentifierAndBootSeed();
// Original: arm9/main @ 0x0202B7EC; symbol: func_0202b7ec; size: 0x14.
extern "C" void Object_SetStateTwoAndInvokeTransition(unsigned* p){*p=2;SeedGlobalSequenceFromHardwareIdentifierAndBootSeed();}
