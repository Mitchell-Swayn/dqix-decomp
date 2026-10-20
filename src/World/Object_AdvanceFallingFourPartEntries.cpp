#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Matrix.h>
// Original: arm9/main @ 0x02017208; symbol: func_02017208; size: 0x104.
extern "C" ARM void Object_AdvanceFallingFourPartEntries(unsigned char* p){unsigned ticks=GameState::GetInstance()->GetTickCount();for(int i=0;i<p[0x476];i++){unsigned char* entry=*(unsigned char**)(p+0x478)+i*0x368;if(*(short*)(entry+2)!=-1){for(unsigned t=0;t<ticks;t++){if(*(short*)(entry+2)==3){(*(short*)(entry+4))++;if(*(short*)(entry+4)>20)*(short*)(entry+2)=-1;else for(int j=0;j<4;j++){unsigned char* part=entry+0x118+j*0x88;Vector3fix point;Vector3fix_Add((Vector3fix*)(part+0x1c),(Vector3fix*)(entry+0x338+j*12),&point);*(Vector3fix*)(part+0x1c)=point;*(int*)(entry+0x33c+j*12)-=64;}}}}}}
