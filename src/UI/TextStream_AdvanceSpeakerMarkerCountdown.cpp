#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 2
#pragma opt_common_subs off
extern "C" unsigned** ActorPool_GetGlobalInstance();extern "C" unsigned* ActorPool_GetActiveSlot(unsigned**,unsigned);
// Original: arm9/main @ 0x02065758; symbol: func_02065758; size: 0x70.
extern "C" int TextStream_AdvanceSpeakerMarkerCountdown(unsigned char* p,unsigned n){if(!ActorPool_GetActiveSlot(ActorPool_GetGlobalInstance(),*(unsigned*)(p+0x1838)))return 0;if(!p[0x19b7])return 0;n&=0xff;int result=1;if(p[0x1959]<n)p[0x1959]=0;else p[0x1959]-=n;if(!p[0x1959]){result=0;p[0x19b7]=0;}return result;}
