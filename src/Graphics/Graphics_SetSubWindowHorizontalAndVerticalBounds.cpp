// Exact ARM widths, branches and relocation-backed callee contracts reviewed.
#include <globaldefs.h>
#include <Resource/Script.h>
#include <GameState/GameState.h>
ARM
#pragma force_active on
struct Twelve{unsigned count:12,rest:20;};extern "C"{void ClearFourBytes_Main020E303C(void*);void func_0204719c(void*);int sprintf(char*,const char*,...);int TestActiveWordAndGlobalStateNonzero(void*);int Object_FindSignedByteKeyInSixteenEntries(void*,int);void GameState_ClearObjectByIndex(GameState*,int);void InitializeSixteenEmbeddedEntries(void*);extern char data_020fdc4c[],data_02109404[];extern char* data_02105244[];}
// Original: arm9/main @ 0x020E29EC; symbol: func_020e29ec; size: 0x34.
extern "C" void Graphics_SetSubWindowHorizontalAndVerticalBounds(unsigned a,unsigned b,unsigned c,unsigned d){volatile unsigned short* p=(volatile unsigned short*)0x04001040;p[0]=((a<<8)&0xff00)|(c&255);p[2]=((b<<8)&0xff00)|(d&255);}
