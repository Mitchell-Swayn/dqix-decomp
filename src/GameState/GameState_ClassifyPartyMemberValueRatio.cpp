#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
struct Stats{int value;int rest[7];};extern Stats data_020fdcb0[],data_020fdcb8[];
// Original: arm9/main @ 0x02027BD0; symbol: func_02027bd0; size: 0xD4.
extern "C" int GameState_ClassifyPartyMemberValueRatio(int index){bool valid;if(index>=0&&index<=3)valid=true;else valid=false;if(!valid)return 1;int current=data_020fdcb0[index].value;int maximum=data_020fdcb8[index].value;if(current<0)return 1;if(maximum<=0)return 1;if(!GameState::GetInstance()->GetPartyMemberByIndex(index))return 1;float ratio=(float)current/(float)maximum;if(ratio<=0.0f)return 2;if(ratio<=0.08f)return 3;if(ratio<=0.25f)return 4;return 1;}
