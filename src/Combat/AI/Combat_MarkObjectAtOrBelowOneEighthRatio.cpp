#include <globaldefs.h>
ARM
#pragma opt_propagation off
#include <GameState/GameState.h>
extern "C" GameObject* Combat_FindIndexedMonsterObject(void*,int);
// Original: arm9/ov024 @ 0x021F32B4; symbol: func_ov024_021f32b4; size: 0x68.
extern "C" int Combat_MarkObjectAtOrBelowOneEighthRatio(GameState** game,int index,int unused,int* marked,unsigned short* selected){unsigned char* object=(unsigned char*)Combat_FindIndexedMonsterObject(*game,index);if(!object)return 0;unsigned char* record=*(unsigned char**)(object+0x138);unsigned denominator=*(unsigned short*)(record+6);unsigned numerator=*(unsigned short*)(record+2);float ratio=(float)numerator/(float)denominator;if(ratio>0.125f)return 0;*marked=1;*selected=index;return 1;}
