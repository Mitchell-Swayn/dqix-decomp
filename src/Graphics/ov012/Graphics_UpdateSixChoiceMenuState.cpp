#include <globaldefs.h>
ARM
struct State; struct GameState; struct GameResources;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned Object_ReadGlobalDisplayContextWord();
extern "C" void Object_ResetSelectionAndApplyConfiguredMode(State*,int);
extern "C" int Selection_ReadEnabledIndexFromControl(void*);
extern "C" void Object_BindMatchingPairEntryToSelectedRecord(char*,unsigned,unsigned);
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char*,int,void*);
extern "C" void func_ov012_0218943c(unsigned char*);
extern "C" int TestGlobalOrLocalInputMask(void*);
extern "C" int GameState_HasMaskOrModeTwoAtOffsetAC(void*);
extern "C" void ConfigurePairedControlsFromStateSelector(unsigned char*);
extern "C" char data_02108760[];
// Original: arm9/ov012 @ 0x02186A7C; symbol: func_ov012_02186a7c; size: 0x1A0.
extern "C" void Graphics_UpdateSixChoiceMenuState(char* p) {
 GameState_ReadPResources((GameState*)_ZN9GameState11GetInstanceEv());
 _ZN16BackgroundLoader11GetInstanceEv();
 Object_ReadGlobalDisplayContextWord();
 if(*(unsigned char*)(p+0x1370)==0) {
  *(unsigned char*)(p+0x13a0)=0; *(int*)(p+0x13d4)=0;
  Object_BindMatchingPairEntryToSelectedRecord(p+0xac,0,2);
  ConfigurePairedControlsFromStateSelector((unsigned char*)p);
  func_ov012_0218943c((unsigned char*)p);
  ++*(unsigned char*)(p+0x1370);
 } else if(*(unsigned char*)(p+0x1370)==1) {
  *(unsigned char*)(p+0x13a0)=1;
  *(int*)(p+0x13d4)=Selection_ReadEnabledIndexFromControl(p+0xac);
  int cancel=0;
  if(TestGlobalOrLocalInputMask(p)) {
   *(unsigned char*)(p+0x164)=*(unsigned char*)(p+0x1371);
   *(unsigned char*)(p+0x13a0)=0;
   DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,1,0);
   switch(*(unsigned*)(p+0x13d4)) {
   case 0: *(unsigned char*)(p+0x1371)=2; *(unsigned char*)(p+0x1370)=0; break;
   case 1: *(unsigned char*)(p+0x1371)=9; *(unsigned char*)(p+0x1370)=0; break;
   case 2: *(unsigned char*)(p+0x1371)=10; *(unsigned char*)(p+0x1370)=0; break;
   case 3: *(unsigned char*)(p+0x1371)=13; *(unsigned char*)(p+0x1370)=0; break;
   case 4: *(unsigned char*)(p+0x1371)=14; *(unsigned char*)(p+0x1370)=0; break;
   case 5: cancel=1; break;
   }
  } else if(GameState_HasMaskOrModeTwoAtOffsetAC(p)) cancel=1;
  if(cancel) {
   *(unsigned char*)(p+0x13a0)=0; *(int*)(p+0x13d4)=0;
   Object_ResetSelectionAndApplyConfiguredMode((State*)(p+0xac),1);
   *(unsigned char*)(p+0x1371)=15; *(unsigned char*)(p+0x1370)=0;
  }
 }
}
