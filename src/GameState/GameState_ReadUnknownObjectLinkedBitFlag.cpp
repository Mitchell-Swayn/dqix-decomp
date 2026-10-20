#include <globaldefs.h>
ARM
struct Bit {unsigned char value:1;unsigned char rest:7;};extern "C" unsigned char* _ZN9GameState20GetUnknownGameObjectEv(void*);
// Original: arm9/main @ 0x020685CC; symbol: func_020685cc; size: 0x24.
extern "C" unsigned GameState_ReadUnknownObjectLinkedBitFlag(void* p){unsigned char* q=_ZN9GameState20GetUnknownGameObjectEv(p);return q?((Bit*)(*(unsigned char**)(q+0x150)+0x49c))->value:0;}
