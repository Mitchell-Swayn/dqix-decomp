#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct A;struct Record;
extern "C" int CombatStatus_HasAilmentModeTwo(A*);
extern "C" int CombatStatus_HasAilmentModeOne(Record*);
// Original: arm9/ov024 @ 0x021D8D38; symbol: func_ov024_021d8d38; size: 0x74.
// Multiplies the sixth argument by1.5 for either enabled mode or current-stats flag8.
// Unused argument roles and the relationship between owner-local A/Record views remain unresolved.
extern "C" int ScaleValueForCombatantModeFlags(void*,int,int index,int,int,int value){
 GameObject* object=GameState::GetInstance()->GetCombatantByIndex(index);
 if(!object)return value;
 if(CombatStatus_HasAilmentModeOne((Record*)object->currentStats_)||CombatStatus_HasAilmentModeTwo((A*)object->currentStats_)||(*(unsigned*)((char*)object->currentStats_+0x14)&8))return (int)(1.5f*value);
 return value;
}
