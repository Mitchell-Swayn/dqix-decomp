#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" GameObject* GameState_GetValidObjectByIndex(GameState*,int);
extern "C" void* MonsterData_FindByRecordId(void*,int);
#pragma always_inline on
inline bool IsReservedPartyIndex(int index){if(index>=0&&index<=3)return true;else return false;}
// Original: arm9/ov000 @ 0x02153758; symbol: func_ov000_02153758; size: 0x60.
// Skips party indices 0 through 3, then finds a resource record using the indexed object's halfword key.
extern "C" void* FindNonPartyObjectResourceRecord(unsigned char* self,int index){
 if(IsReservedPartyIndex(index))return 0;
 GameObject* object=GameState_GetValidObjectByIndex(GameState::GetInstance(),index);
 if(!object)return 0;
 return MonsterData_FindByRecordId(*(unsigned char**)(self+0x8e18)+0x678,*(short*)((unsigned char*)object+2));
}
