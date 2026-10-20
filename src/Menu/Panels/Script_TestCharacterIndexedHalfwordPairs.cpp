#include <globaldefs.h>
ARM
#pragma opt_propagation off
struct IntegerParameterView;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" char* Script_ResolveCharacterFromSignedSelector(int);
extern "C" void Script_WriteIntegerReferenceOutput(void*,int);
// Original: arm9/ov023 @ 0x021E9424; symbol: func_ov023_021e9424; size: 0xA8.
extern "C" int Script_TestCharacterIndexedHalfwordPairs(char* params,int count) {
 _ZN9GameState11GetInstanceEv();
 int selector=Script_ReadParameterAsInteger((IntegerParameterView*)params);
 params+=8;
 char* character=Script_ResolveCharacterFromSignedSelector(selector);
 if(!character) return 0;
 int allMatch=1;
 for(int i=0;i<count-2;i+=2) {
  int index=Script_ReadParameterAsInteger((IntegerParameterView*)params);
  IntegerParameterView* next=(IntegerParameterView*)(params+8);
  params+=16;
  int expected=Script_ReadParameterAsInteger(next);
  char* records=*(char**)(character+0x150)+0x194;
  int actual=*(short*)(records+(unsigned char)index*32+0x18);
  if(actual!=expected) allMatch=0;
 }
 if(allMatch) Script_WriteIntegerReferenceOutput(params,1);
 else Script_WriteIntegerReferenceOutput(params,0);
 return 1;
}
