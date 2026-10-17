// Exact ARM widths, branches and relocation-backed callee contracts reviewed.
#include <globaldefs.h>
#include <Resource/Script.h>
#include <GameState/GameState.h>
ARM
#pragma force_active on
struct Twelve{unsigned count:12,rest:20;};extern "C"{void ClearFourBytes_Main020E303C(void*);void func_0204719c(void*);int sprintf(char*,const char*,...);int TestActiveWordAndGlobalStateNonzero(void*);int Object_FindSignedByteKeyInSixteenEntries(void*,int);void GameState_ClearObjectByIndex(GameState*,int);void InitializeSixteenEmbeddedEntries(void*);extern char data_020fdc4c[],data_02109404[];extern char* data_02105244[];}
// Original: arm9/main @ 0x0201F4CC; symbol: func_0201f4cc; size: 0x34.
extern "C" int Script_SetStateWords18And1C(const Script::Parameter* p){int a=p->ToInt();int b=(p+1)->ToInt();char* q=*(char**)(data_020fdc4c+16);*(int*)(q+24)=a;*(int*)(q+28)=b;return 1;}
