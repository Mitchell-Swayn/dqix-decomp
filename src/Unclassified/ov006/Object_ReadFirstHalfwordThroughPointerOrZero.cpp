#include <globaldefs.h>
// Original: arm9/ov006 @ 0x021599AC; symbol: func_ov006_021599ac; size: 0x14.
extern "C" ARM int Object_ReadFirstHalfwordThroughPointerOrZero(void* object) { void* value = *(void**)object; return value ? *(unsigned short*)value : 0; }
