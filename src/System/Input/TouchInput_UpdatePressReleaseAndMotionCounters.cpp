#include <globaldefs.h>
ARM
extern "C" void TP_GetLatestCalibratedPointInAuto(void*);extern "C" int TouchInput_ComputeSampleDistance(void*);
// Original: arm9/main @ 0x020129B4; symbol: func_020129b4; size: 0xD0.
extern "C" int TouchInput_UpdatePressReleaseAndMotionCounters(unsigned char* object){TP_GetLatestCalibratedPointInAuto(object+32);if(!object[0x5f]){if(*(unsigned short*)(object+0x24))return 0;object[0x5f]=1;}if(*(unsigned short*)(object+0x24) && !*(unsigned short*)(object+0x26)){(*(int*)(object+0x40))++;*(int*)(object+0x48)=0;if(object[0x56] && TouchInput_ComputeSampleDistance(object)>1)*(int*)(object+0x4c)=0;else if(TouchInput_ComputeSampleDistance(object)<1)(*(int*)(object+0x4c))++;}else{*(unsigned short*)(object+0x24)=0;if(*(int*)(object+0x40))*(int*)(object+0x44)=*(int*)(object+0x40);*(int*)(object+0x40)=0;(*(int*)(object+0x48))++;}return 1;}
