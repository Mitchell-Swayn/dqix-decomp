#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" int Geometry_ReadPositionMatrixStackLevel(unsigned*);extern "C" int Graphics_ReadStackStatusUnlessBusyFlag(unsigned*);
// Original: arm9/main @ 0x020C5414; symbol: func_020c5414; size: 0x90.
extern "C" void Graphics_ResetGeometryMatrixStackState(){unsigned projection;unsigned texture;*(volatile unsigned*)0x04000600|=0x8000;while(Geometry_ReadPositionMatrixStackLevel(&projection)){}while(Graphics_ReadStackStatusUnlessBusyFlag(&texture)){}volatile unsigned* command=(volatile unsigned*)0x04000440;command[0]=3;command[5]=0;command[0]=0;if(texture)command[2]=texture;volatile unsigned* command2=(volatile unsigned*)0x04000440;command2[0]=2;command2[2]=projection;command2[5]=0;}
