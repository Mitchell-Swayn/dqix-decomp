#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {void*SystemState_GetGlobalFlags();void SystemState_SetFlags(void*,unsigned);}
// Original: arm9/main @ 0x020A8AC8; symbol: func_020a8ac8; size: 0x44.
extern "C" ARM void GameState_SetMemberMaskAndObjectFlags(unsigned char *p,unsigned member){p[4]|=1u<<member;SystemState_SetFlags(SystemState_GetGlobalFlags(),0x402);GameState::GetInstance()->GetPartyMemberByIndex(member)->obj3D_.EnableFlag(0x08000100);}
