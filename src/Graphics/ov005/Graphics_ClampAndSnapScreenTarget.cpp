#include <globaldefs.h>
#include <System/Matrix.h>
ARM
#pragma always_inline on
#pragma opt_common_subs off
#pragma optimization_level 4
extern "C" int abs(int);
extern "C" void SetThreeWordFieldsAtOffsets1C20And24(int,unsigned,unsigned,unsigned);

inline int Clamp(int value,int maximum){if(value<1)value=1;if(value>maximum)value=maximum;return value;}
// Original: arm9/ov005 @ 0x02156E1C; symbol: func_ov005_02156e1c; size: 0xB0.
extern "C" void Graphics_ClampAndSnapScreenTarget(unsigned char* p,int x,int y){
 if(*(short*)(p+0x3d78)<0)return;
 Vector3fix position=*(Vector3fix*)(p+0x3d0c);
 int currentX=position.x>>12;int currentY=position.y>>12;
 int targetX=Clamp(x-12,231);int targetY=Clamp(y-12,167);
 if(abs(currentX-targetX)<3)targetX=currentX;
 if(abs(currentY-targetY)<3)targetY=currentY;
 SetThreeWordFieldsAtOffsets1C20And24((int)(p+0x3cf0),targetX<<12,targetY<<12,0x2000);
}
