#include <globaldefs.h>
ARM
#include <System/Matrix.h>
// Original: arm9/main @ 0x020AE3F4; symbol: func_020ae3f4; size: 0xD4.
extern "C" void AdvanceSquaredTimeVerticalOffset(unsigned char* object){int next=*(int*)(object+0x140)+1;int square=next*next;*(int*)(object+0x140)=next;Vector3i position;position=*(Vector3i*)(object+0x44);position.y+=(int)(4096.0f*(0.005f*(float)square));*(Vector3i*)(object+0x44)=position;*(int*)(object+0x168)+=(int)(4096.0f*(0.005f*(float)square));*(int*)(object+0x178)+=(int)(4096.0f*(0.005f*(float)square));}
