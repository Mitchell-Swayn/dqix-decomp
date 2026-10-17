// Exact ARM widths, branches and relocation-backed callee contracts reviewed.
#include <globaldefs.h>
#include <Resource/Script.h>
#include <GameState/GameState.h>
ARM
#pragma force_active on
struct Twelve{unsigned count:12,rest:20;};extern "C"{void ClearFourBytes_Main020E303C(void*);void func_0204719c(void*);int sprintf(char*,const char*,...);int TestActiveWordAndGlobalStateNonzero(void*);int Object_FindSignedByteKeyInSixteenEntries(void*,int);void GameState_ClearObjectByIndex(GameState*,int);void InitializeSixteenEmbeddedEntries(void*);extern char data_020fdc4c[],data_02109404[];extern char* data_02105244[];}
// Original: arm9/main @ 0x02054248; symbol: func_02054248; size: 0x38.
extern "C" void ConsumePendingFlagAndConditionallySetBitZero(char* p){unsigned f=*(unsigned*)(p+396);if(!(f&256))return;unsigned a=f&128;if(a)*(unsigned*)(p+396)=f|1;else if(a)*(unsigned*)(p+396)=f&~1;*(unsigned*)(p+396)&=~256;}
