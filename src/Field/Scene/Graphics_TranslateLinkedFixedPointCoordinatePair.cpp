#include <globaldefs.h>
ARM
extern "C" void ZoneContainerRenderPart_SetPositionComponents(int,unsigned int,unsigned int,unsigned int);
// Original: arm9/ov017 @ 0x0219B578; symbol: func_ov017_0219b578; size: 0xAC.
extern "C" void Graphics_TranslateLinkedFixedPointCoordinatePair(unsigned char* object,int x,int y) {
unsigned char* linked=*(unsigned char**)(object+0x3630);
if(!linked)return;
int nextX=(int)(4096.0f*((float)*(int*)(linked+0x1c)/4096.0f+(float)x));
int nextY=(int)(4096.0f*((float)*(int*)(linked+0x20)/4096.0f+(float)y));
ZoneContainerRenderPart_SetPositionComponents((int)linked,nextX,nextY,0);
}
