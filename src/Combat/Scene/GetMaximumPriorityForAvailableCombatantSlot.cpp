#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma always_inline on
extern "C" int CombatantMotion_GetActiveStatus(char*);
inline bool CombatantSlotHasComponent(char* owner,int index) {
 GameState* state=GameState::GetInstance();
 unsigned id=*(unsigned*)(*(char**)(owner+0x29c)+index*4+0x8de0)&255;
 GameObject* combatant=state->GetCombatantByIndex(id);
 if(combatant)return CombatantMotion_GetActiveStatus((char*)combatant)!=0;
 return false;
}
// Original: arm9/ov000 @ 0x02167BB4; symbol: func_ov000_02167bb4; size: 0x74.
// Gives maximum signed priority to slots 0..7 whose combatant lacks the indirect component byte.
// Component meaning remains unknown. Original performs the indexed lookup before range validation.
extern "C" int GetMaximumPriorityForAvailableCombatantSlot(char* owner,int index) {
 if(CombatantSlotHasComponent(owner,index))return 0;
 if(index<0||index>=8)return 0;
 return 0x7fffffff;
}
