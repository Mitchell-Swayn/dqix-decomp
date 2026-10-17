// Exact ARM widths, branches and relocation-backed callee contracts reviewed.
#include <globaldefs.h>
#include <Resource/Script.h>
#include <GameState/GameState.h>
ARM
#pragma force_active on
struct Twelve{unsigned count:12,rest:20;};extern "C"{void ClearFourBytes_Main020E303C(void*);void _ZN23ZoneContainerRenderPart5ResetEv(void*);char* func_0200fdf0(GameState*,int);int sprintf(char*,const char*,...);int TestActiveWordAndGlobalStateNonzero(void*);int Object_FindSignedByteKeyInSixteenEntries(void*,int);void GameState_ClearObjectByIndex(GameState*,int);void InitializeSixteenEmbeddedEntries(void*);extern char data_020fdc4c[],data_02109404[];extern char* data_02105244[];}
// Original: arm9/main @ 0x02070F98; symbol: func_02070f98; size: 0x38.
extern "C" char* SetMaskedFlagsAtOffset4(char* p,int i){if(i<0||i>=(int)((Twelve*)p)->count||!*(char**)(p+4))return 0;return *(char**)(p+4)+i*132;}
