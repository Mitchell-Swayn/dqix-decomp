#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(usa) || defined(jpn)
// Original data: arm9/main @ 0x20f33d8; symbol: data_020f33d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4648 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern GameState GameStateGetInstance_UnknownRoleZeroInitializedStorage;
#endif

// Original: arm9/main @ 0x0200F398; symbol: _ZN9GameState11GetInstanceEv; size: 0xC.
GameState* GameState::GetInstance()
{
	return &GameStateGetInstance_UnknownRoleZeroInitializedStorage;
}