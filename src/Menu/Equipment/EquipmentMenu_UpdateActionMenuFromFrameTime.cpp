#include "GameState/GameState.h"
extern "C" void EquipmentMenu_UpdateActionMenu(void*,int);
// Original: arm9/ov005 @ 0x0215C034; symbol: func_ov005_0215c034; size: 0x24.
extern "C" void EquipmentMenu_UpdateActionMenuFromFrameTime(void* self) { int ticks=GameState::GetInstance()->GetTickCount(); if(!ticks)ticks=1; EquipmentMenu_UpdateActionMenu(self,ticks); }
