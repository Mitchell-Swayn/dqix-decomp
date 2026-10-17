#include <globaldefs.h>
extern "C" int func_020a0a08(void*,int,int);extern "C" int func_0207c894(void*,int,int);extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* GameState_GetObjectWithFlag100(void*,unsigned);extern "C" void* ReadWordFieldAtOffset150(void*);extern "C" int Object_RemoveHalfwordKeyAndCompactEightEntries(void*,int);
#pragma optimization_level 4
// Original: arm9/main @ 0x02086D88; symbol: func_02086d88; size: 0xC8.
extern "C" ARM int GameState_TestKeyInContainersOrListedPartyMembers(unsigned char* p,int key){if(key<0)return 0;if(func_020a0a08(p,key,1))return 1;if(func_0207c894(p+0x1d4,key,9))return 1;if(func_020a0a08(p+0xe04,key,1))return 1;void* state=_ZN9GameState11GetInstanceEv();for(unsigned char i=0;i<p[0xf7c];++i){void* obj=GameState_GetObjectWithFlag100(state,p[0xf78+i]);if(obj){void* data=ReadWordFieldAtOffset150(obj);if(data&&Object_RemoveHalfwordKeyAndCompactEightEntries(data,key))return 1;}}return 0;}
