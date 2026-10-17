// Exact ARM widths, branches and relocation-backed callee contracts reviewed.
#include <globaldefs.h>
#include <Resource/Script.h>
#include <GameState/GameState.h>
ARM
#pragma force_active on
struct Twelve{unsigned count:12,rest:20;};extern "C"{void ClearFourBytes_Main020E303C(void*);void func_0204719c(void*);int sprintf(char*,const char*,...);int TestActiveWordAndGlobalStateNonzero(void*);int Object_FindSignedByteKeyInSixteenEntries(void*,int);void GameState_ClearObjectByIndex(GameState*,int);void InitializeSixteenEmbeddedEntries(void*);extern char data_020fdc4c[],data_02109404[];extern char* data_02105244[];}
// Original: arm9/main @ 0x020954B0; symbol: func_020954b0; size: 0x38.
extern "C" int Script_WriteBoundedGlobalByteArray(const Script::Parameter* p){unsigned a=p->ToInt()&255;unsigned i=(p+1)->ToInt()&255;if(i<204)(*(char**)(data_02109404+16))[i]=a;return 1;}
