#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" unsigned char data_020edf2c[];
// Original: arm9/main @ 0x020D2AC4; symbol: func_020d2ac4; size: 0x70.
extern "C" unsigned short SoundVolume_EncodeClampedDecibelAttenuation(int value){if(value<-723)value=-723;else if(value>0)value=0;unsigned v=data_020edf2c[value+723];unsigned high;if(value<-240)high=3;else if(value<-120)high=2;else if(value<-60)high=1;else high=0;return v|(high<<8);}
