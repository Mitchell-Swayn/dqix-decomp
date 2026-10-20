#include <globaldefs.h>
ARM
extern "C" void ResourceManager_ExchangeGlobalValue(void*);extern "C" unsigned NNS_SndArcStrmGetCurrentPlayingPos(void*);extern "C" void ResourceHandle_SetOptionalEnabledState(void*,unsigned);
// Original: arm9/main @ 0x0203AD88; symbol: func_0203ad88; size: 0x74.
extern "C" unsigned ResourceHandle_ReplaceValueAndInvalidateFileIndices(unsigned* p,void* other,unsigned value){if(!p[0])return 0;ResourceManager_ExchangeGlobalValue(p+1);unsigned result;if(other){result=NNS_SndArcStrmGetCurrentPlayingPos(other);ResourceHandle_SetOptionalEnabledState(other,value);}else{result=NNS_SndArcStrmGetCurrentPlayingPos(p+0x27);ResourceHandle_SetOptionalEnabledState(p+0x27,value);}*(short*)(p+0x29)= -1;return result;}
