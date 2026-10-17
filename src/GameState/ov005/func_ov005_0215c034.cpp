#include "GameState/GameState.h"
extern "C" void func_ov005_02158e04(void*,int);
// Original: arm9/ov005 @ 0x0215C034; symbol: func_ov005_0215c034; size: 0x24.
extern "C" void func_ov005_0215c034(void* self) { int ticks=GameState::GetInstance()->GetTickCount(); if(!ticks)ticks=1; func_ov005_02158e04(self,ticks); }
