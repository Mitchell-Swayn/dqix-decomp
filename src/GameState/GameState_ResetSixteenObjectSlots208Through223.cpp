// Exact ARM widths, branches and relocation-backed callee contracts reviewed.
#include <globaldefs.h>
#include <Resource/Script.h>
#include <GameState/GameState.h>
ARM
#pragma force_active on
struct Twelve{unsigned count:12,rest:20;};extern "C"{void ClearFourBytes_Main020E303C(void*);void func_0204719c(void*);int sprintf(char*,const char*,...);int TestActiveWordAndGlobalStateNonzero(void*);int Object_FindSignedByteKeyInSixteenEntries(void*,int);void GameState_ClearObjectByIndex(GameState*,int);void InitializeSixteenEmbeddedEntries(void*);extern char data_020fdc4c[],data_02109404[];extern char* data_02105244[];}
// Original: arm9/main @ 0x02057978; symbol: func_02057978; size: 0x3C.
extern "C" void GameState_ResetSixteenObjectSlots208Through223(void* p){GameState* state=GameState::GetInstance();for(int i=0;i<16;++i)GameState_ClearObjectByIndex(state,i+208);InitializeSixteenEmbeddedEntries(p);}
