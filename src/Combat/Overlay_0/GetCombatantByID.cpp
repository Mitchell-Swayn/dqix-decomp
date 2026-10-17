#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "GameState/GameState.h"

// Original: arm9/ov000 @ 0x021536E0; symbol: _Z16GetCombatantByIDii; size: 0x18.
struct GameObject* GetCombatantByID(int unused, int id) {
	return GameState::GetInstance()->GetCombatantByIndex(id);
}