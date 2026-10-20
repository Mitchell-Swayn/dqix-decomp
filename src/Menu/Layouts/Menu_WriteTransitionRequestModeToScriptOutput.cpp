#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_TestTransitionRequestFlags(void*,unsigned);
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void*);
extern "C" unsigned Network_GetSessionPhase(void*);
extern "C" void Script_WriteIntegerReferenceOutput(void*,unsigned);
// Original: arm9/ov011 @ 0x02187F7C; symbol: func_ov011_02187f7c; size: 0x98.
extern "C" unsigned Menu_WriteTransitionRequestModeToScriptOutput(void* self) {
 unsigned mode=0;
 void* input=_ZN9GameState11GetInstanceEv();
 if(GameState_TestTransitionRequestFlags(input,1)) {
  if(GameState_TestTransitionRequestFlags(input,2)) mode=1;
  if(GameState_TestTransitionRequestFlags(input,4)) mode=2;
  if(GameState_TestTransitionRequestFlags(input,8)) mode=3;
  void* state=Network_GetConnectionManager();
  if(Network_IsSessionActive(state) && Network_GetSessionPhase(state)==6) mode=4;
 }
 Script_WriteIntegerReferenceOutput(self,mode);
 return 1;
}
