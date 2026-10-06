#include "GameState/GameState.h"

extern "C" GameObject* func_0200fea4(GameState* state, int index);

// The first parameter is ignored; the second selects the combatant by index.
extern "C" GameObject* func_ov000_021536f8(int unused, int id)
{
	return func_0200fea4(GameState::GetInstance(), id);
}
