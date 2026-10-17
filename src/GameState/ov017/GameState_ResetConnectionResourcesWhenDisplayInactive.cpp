#include <globaldefs.h>
ARM
struct Owner; struct A; struct GameResources;
extern "C" void* GetGlobalStatePointer();
extern "C" void* Object_GetGlobalDisplayManager();
extern "C" bool Object_TestDisabledOrNonpositiveState(A*);
extern "C" void SetWordMaskBits_Main020466E4(unsigned*,unsigned);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* Object_GetGlobalConnectionState();
extern "C" void* ReadGlobalAt02100044();
extern "C" void SetWordMaskBits_Main0203B4A0(unsigned*,unsigned);
extern "C" unsigned WaitForStateThreeThenProcessOwnerWithTimeout(Owner*);
extern "C" void ClearIndirectBytePairAt441C(char*);
extern "C" void GameState_ResetPartyMemberHalfwords(GameResources*);
extern "C" void ClearField3C9Flag1AndRefreshRecord(unsigned char*);
extern "C" void* FillThirtyTwoByteBitsetWithFF(unsigned char*);
extern "C" void Flags_ClearWordMask(unsigned*,unsigned);
// Original: arm9/ov017 @ 0x021AF4EC; symbol: func_ov017_021af4ec; size: 0xB0.
extern "C" unsigned GameState_ResetConnectionResourcesWhenDisplayInactive(unsigned char* self) {
 void* global=GetGlobalStatePointer();
 void* display=Object_GetGlobalDisplayManager();
 if(Object_TestDisabledOrNonpositiveState((A*)display)) {
  SetWordMaskBits_Main020466E4((unsigned*)global,0x20);
  GameResources* resources=GameResources_GetInstance();
  void* connection=Object_GetGlobalConnectionState();
  void* queue=ReadGlobalAt02100044();
  self[15]=0;
  SetWordMaskBits_Main0203B4A0((unsigned*)resources,2);
  WaitForStateThreeThenProcessOwnerWithTimeout((Owner*)connection);
  ClearIndirectBytePairAt441C((char*)resources);
  GameState_ResetPartyMemberHalfwords(resources);
  ClearField3C9Flag1AndRefreshRecord((unsigned char*)display);
  FillThirtyTwoByteBitsetWithFF((unsigned char*)queue);
  Flags_ClearWordMask((unsigned*)resources,0x40);
  ((unsigned char*)resources)[0x42e3]=0;
  ((unsigned char*)resources)[0x42e2]=0;
  self[1]=1;
 }
 return self[8];
}
