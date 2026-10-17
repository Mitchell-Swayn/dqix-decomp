#include <globaldefs.h>
#include "GameState/GameState.h"
struct Handler { unsigned char pad[10]; unsigned char mode; }; typedef void (Handler::*Action)();struct Table { Action actions[4]; }; extern "C" Table data_020e907c;extern "C" Action data_020e6d5c;
// Original: arm9/main @ 0x020A620C; symbol: func_020a620c; size: 0x90.
extern "C" int DispatchModeIndexedMemberFunctionIfPresent(Handler *p) { GameState::GetInstance()->GetTickCount();Table table=data_020e907c;table.actions[3]=data_020e6d5c;if(!table.actions[p->mode])return 0;(p->*table.actions[p->mode])();return 1; }
