#include <globaldefs.h>
ARM
extern "C" void ResourceManager_ExchangeGlobalValue(void*);extern "C" int NNS_SndArcStrmGetCurrentPlayingPos(void*);
// Original: arm9/main @ 0x0203ADFC; symbol: func_0203adfc; size: 0x50.
extern "C" bool ResourceHandle_HasElapsedStreamPlaybackTime(char* p,void* q){if(!*(int*)p)return false;ResourceManager_ExchangeGlobalValue(p+4);int n;if(q)n=NNS_SndArcStrmGetCurrentPlayingPos(q);else n=NNS_SndArcStrmGetCurrentPlayingPos(p+156);return n>0;}
