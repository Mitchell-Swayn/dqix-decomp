#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" unsigned char* GameState_FindIndexedObjectWithFlag400(GameState*,unsigned);extern "C" int func_0208a03c(unsigned*,unsigned,unsigned,unsigned*,unsigned);extern "C" unsigned func_ov000_02154a04(unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x0208A840; symbol: func_0208a840; size: 0xD0.
extern "C" unsigned short AdvanceSixIndexedStateCounters(unsigned* object,unsigned key,unsigned* out,unsigned arg){unsigned char* data=GameState_FindIndexedObjectWithFlag400(GameState::GetInstance(),key);unsigned char* state=(unsigned char*)object[0]+0x81c0;int offset=(short)data[0x17c]*0x18;unsigned char* table=*(unsigned char**)(data+0x148);for(unsigned char i=0;i<6;i++){unsigned index=state[offset];state[offset]=index+1;state[offset]=state[offset]%6;if(func_0208a03c(object,index,key,out,arg))return *(unsigned short*)(table+index*2+0x18);}*out=0;*out=func_ov000_02154a04(object[0],key,2,arg);return 2;}
