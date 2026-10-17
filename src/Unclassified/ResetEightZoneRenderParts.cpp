// Exact ARM widths, branches and relocation-backed callee contracts reviewed.
#include <globaldefs.h>
#include <Resource/Script.h>
#include <GameState/GameState.h>
ARM
#pragma force_active on
struct Twelve{unsigned count:12,rest:20;};extern "C"{void ClearFourBytes_Main020E303C(void*);void _ZN23ZoneContainerRenderPart5ResetEv(void*);char* func_0200fdf0(GameState*,int);int sprintf(char*,const char*,...);int TestActiveWordAndGlobalStateNonzero(void*);int Object_FindSignedByteKeyInSixteenEntries(void*,int);void GameState_ClearObjectByIndex(GameState*,int);void InitializeSixteenEmbeddedEntries(void*);extern char data_020fdc4c[],data_02109404[];extern char* data_02105244[];}
// Original: arm9/main @ 0x0202F1A4; symbol: func_0202f1a4; size: 0x38.
extern "C" void ResetEightZoneRenderParts(char* p){for(int i=0;i<8;++i)_ZN23ZoneContainerRenderPart5ResetEv(p+i*136);*(int*)(p+1088)=0;*(int*)(p+1092)=0;}
