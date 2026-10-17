#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(usa) || defined(jpn)
extern GameState data_020f33d8;
#endif

// Original: arm9/main @ 0x0200F398; symbol: _ZN9GameState11GetInstanceEv; size: 0xC.
GameState* GameState::GetInstance()
{
	return &data_020f33d8;
}