#include <globaldefs.h>
struct Color{unsigned red,green,blue;};
// Original: arm9/main @ 0x02070900; symbol: func_02070900; size: 0x50.
extern "C" ARM void Object_SetPackedColorAndMillisecondsDuration(unsigned char* object,const Color* color,unsigned time){*(unsigned short*)(object+2)=color->red|(color->green<<5)|(color->blue<<10);*(int*)(object+8)=(int)(16.66699981689453f*(float)time);object[4]=31;object[0]=1;}
