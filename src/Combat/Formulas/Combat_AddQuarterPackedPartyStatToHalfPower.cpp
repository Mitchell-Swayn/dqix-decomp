#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma always_inline on
typedef unsigned int undefined4;
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" unsigned GameObject_GetLinkedIndexedState(int);
struct PackedStat {unsigned low:10,rest:22;};
inline int IsObservedPartyIndex(unsigned index) {return index<=3;}
// Original: arm9/ov024 @ 0x021DA404; symbol: func_ov024_021da404; size: 0x78.
// For indices0..3 with object/stat data, returns truncated quarter stat plus half input.
// Unused argument meanings and the packed stat's gameplay identity remain unresolved.
extern "C" int Combat_AddQuarterPackedPartyStatToHalfPower(void*,unsigned index,void*,void*,void*,int input) {
 if(!IsObservedPartyIndex(index))return input;
 GameObject* object=GameState_GetObjectWithFlag100(GameState::GetInstance(),index);
 if(!object)return input;
 char* stats=(char*)GameObject_GetLinkedIndexedState((int)object);
 if(stats)input=(int)(0.25f*(float)((PackedStat*)(stats+4))->low)+input/2;
 return input;
}
