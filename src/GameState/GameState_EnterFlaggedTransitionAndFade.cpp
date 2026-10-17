#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <Resource/Brightness.h>
extern "C" GameResources* GameResources_GetInstance();extern "C" void func_ov017_021c37a4();extern "C" void* GetGlobalStatePointer();extern "C" int TestWordMaskNonzero(void*,unsigned);extern "C" void SetWordMaskBits_Main020466E4(void*,unsigned);extern "C" int WaitForStatusWithTimeoutAndSleep(unsigned*,int);extern "C" void WriteActive(GameState*);
// Original: arm9/main @ 0x0202B1F4; symbol: func_0202b1f4; size: 0x90.
extern "C" int GameState_EnterFlaggedTransitionAndFade(unsigned* object){GameState* state=GameState::GetInstance();GameResources* resources=GameResources_GetInstance();void* flags=GetGlobalStatePointer();if(TestWordMaskNonzero(flags,0x1000000))return 3;int result=WaitForStatusWithTimeoutAndSleep(object,1);if((unsigned char)(result+0xfe)>1)return result;SetWordMaskBits_Main020466E4(flags,0x1000000);func_ov017_021c37a4();SetBrightness(resources,-16,10);((unsigned char*)state)[0x5cc8]=4;WriteActive(state);*object=3;return 3;}
