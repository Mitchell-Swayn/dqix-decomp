#include <globaldefs.h>
ARM
#pragma opt_propagation off
struct IntegerParameterView;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" char* ResolveCharacterBySignedSelector(int);
extern "C" void SetNestedSecondWordForTypeThree(void*,int);
// Original: arm9/ov023 @ 0x021E9424; symbol: func_ov023_021e9424; size: 0xA8.
extern "C" int Script_TestCharacterIndexedHalfwordPairs(char* params,int count) {
 _ZN9GameState11GetInstanceEv();
 int selector=ReadScriptParameterAsInteger((IntegerParameterView*)params);
 params+=8;
 char* character=ResolveCharacterBySignedSelector(selector);
 if(!character) return 0;
 int allMatch=1;
 for(int i=0;i<count-2;i+=2) {
  int index=ReadScriptParameterAsInteger((IntegerParameterView*)params);
  IntegerParameterView* next=(IntegerParameterView*)(params+8);
  params+=16;
  int expected=ReadScriptParameterAsInteger(next);
  char* records=*(char**)(character+0x150)+0x194;
  int actual=*(short*)(records+(unsigned char)index*32+0x18);
  if(actual!=expected) allMatch=0;
 }
 if(allMatch) SetNestedSecondWordForTypeThree(params,1);
 else SetNestedSecondWordForTypeThree(params,0);
 return 1;
}
