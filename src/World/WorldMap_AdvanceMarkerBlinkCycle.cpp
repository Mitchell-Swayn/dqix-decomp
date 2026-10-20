#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" unsigned _ZNK9GameState16GetTrueDeltaTimeEv(const void*);
// Original: arm9/main @ 0x0202441C; symbol: func_0202441c; size: 0x40.
extern "C" void WorldMap_AdvanceMarkerBlinkCycle(unsigned char* p){unsigned v=*(unsigned*)(p+0x9bc)+_ZNK9GameState16GetTrueDeltaTimeEv(_ZN9GameState11GetInstanceEv());*(unsigned*)(p+0x9bc)=v;if(v>=1200){p[0x9c0]=0;*(unsigned*)(p+0x9bc)=0;return;}if(v>=500)p[0x9c0]=1;}
