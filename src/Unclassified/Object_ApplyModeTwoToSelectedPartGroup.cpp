#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void ClearMaskedFlagsAtOffset2A(void*,int,unsigned);
// Original: arm9/main @ 0x020806C4; symbol: func_020806c4; size: 0x14.
extern "C" void Object_ApplyModeTwoToSelectedPartGroup(unsigned char* p,int key){ClearMaskedFlagsAtOffset2A(p+4,key,2);}
