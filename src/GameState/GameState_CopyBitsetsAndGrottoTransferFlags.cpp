#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <System/Memory.h>
// Original: arm9/main @ 0x020A9E30; symbol: func_020a9e30; size: 0x74.
extern "C" int GameState_CopyBitsetsAndGrottoTransferFlags(char* p){GameState* g=GameState::GetInstance();char* state=(char*)g;MI_CpuCopy8(p,state+0x6fcc,0x200);MI_CpuCopy8(p+0x204,state+0x5cd0,10);*(unsigned*)(state+0x71cc)=*(unsigned*)(p+0x200);char* grotto=(char*)g->GetGrottoStruct();grotto[3]=(*(unsigned*)(p+0x200)&1)!=0;*(unsigned*)(state+0x71cc)=0;return 1;}
