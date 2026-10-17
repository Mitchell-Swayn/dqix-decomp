#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" unsigned char* _ZN9GameState20GetUnknownGameObjectEv(void*);
// Original: arm9/main @ 0x0203CEDC; symbol: func_0203cedc; size: 0x70.
extern "C" void GameState_CopyObjectValueAndUpdateTwoModeFlags(unsigned* p,unsigned a,unsigned b){unsigned char* state=_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());if(*(int*)(state+76)>=(int)p[3])return;p[38]=*(unsigned*)(state+68);p[23]&=~32U;p[23]&=~16U;if(a&&!b){p[23]|=16;return;}if(a&b)p[23]|=32;}
