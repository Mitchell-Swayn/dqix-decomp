#include <globaldefs.h>
ARM
struct Bit{unsigned char value:1;unsigned char rest:7;};extern "C" unsigned char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
// Original: arm9/main @ 0x020685A4; symbol: func_020685a4; size: 0x28.
extern "C" unsigned GameState_ReadFirstPartyMemberStoredBit(void* p){unsigned char* q=_ZN9GameState21GetPartyMemberByIndexEi(p,0);return q?((Bit*)(*(unsigned char**)(q+0x150)+0x49c))->value:0;}
