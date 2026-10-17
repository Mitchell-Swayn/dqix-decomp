#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_TestByteFlagsAtOffset63DC(void*,unsigned);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int IsFirstWordNonzero(void*);
extern "C" unsigned ReadValue_Main0202BA00(void*);
extern "C" void SetNestedSecondWordForTypeThree(void*,unsigned);
// Original: arm9/ov011 @ 0x02187F7C; symbol: func_ov011_02187f7c; size: 0x98.
extern "C" unsigned func_ov011_02187f7c(void* self) {
 unsigned mode=0;
 void* input=_ZN9GameState11GetInstanceEv();
 if(GameState_TestByteFlagsAtOffset63DC(input,1)) {
  if(GameState_TestByteFlagsAtOffset63DC(input,2)) mode=1;
  if(GameState_TestByteFlagsAtOffset63DC(input,4)) mode=2;
  if(GameState_TestByteFlagsAtOffset63DC(input,8)) mode=3;
  void* state=Object_GetGlobalConnectionState();
  if(IsFirstWordNonzero(state) && ReadValue_Main0202BA00(state)==6) mode=4;
 }
 SetNestedSecondWordForTypeThree(self,mode);
 return 1;
}
