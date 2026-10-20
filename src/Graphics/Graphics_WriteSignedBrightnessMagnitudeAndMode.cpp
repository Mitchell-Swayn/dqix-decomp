#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020C39A0; symbol: func_020c39a0; size: 0x28.
void Graphics_WriteSignedBrightnessMagnitudeAndMode(unsigned short *p,int v){if(v==0){*p=0;return;}if(v>0)*p=v|0x4000;else *p=-v|0x8000;}
}
