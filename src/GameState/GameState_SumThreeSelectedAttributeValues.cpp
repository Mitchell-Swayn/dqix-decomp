#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" int GameState_ReadAttributeBits12To19(void*,int);
// Original: arm9/main @ 0x02085B88; symbol: func_02085b88; size: 0x80.
extern "C" int GameState_SumThreeSelectedAttributeValues(unsigned char* p){if(*(short*)(p+0x2cc)<=0)return 0;void* state=_ZN9GameState11GetInstanceEv();int sum=0;if(p[0x8f0]&4)sum+=GameState_ReadAttributeBits12To19(state,34);if(p[0x8f0]&16)sum+=GameState_ReadAttributeBits12To19(state,36);if(p[0x8f0]&64)sum+=GameState_ReadAttributeBits12To19(state,38);return sum;}
