#include <globaldefs.h>
#include <Resource/GameResources.h>
#include <Resource/Brightness.h>
extern "C" void *GetGlobalStatePointer(),*Object_GetGlobalDisplayManager();
extern "C" int TestWordMaskNonzero(void*,int),TestIdPresentInSignedCountRecordArray(void*,int),ContainsHalfwordValueInFiftyTwoByteRecords(void*,int);
extern "C" void Object_CopyDisplayStateAndClearPendingMode(void*),CommitPendingSelectorAndClearField3CDFlag4(void*),GameState_UpdateFourPartyMemberEntryFlagsAndTimers(void*),DispatchStateHandlersByKindAndPhase(void*),AllocateAndCopyPresentResourceBuffer(void*),Graphics_DrawConditionalSubDisplaySprites(void*),Graphics_UpdateSubBackgroundScrollByDisplayMode(void*);
extern "C" int Object_TestSelectedFloatWithinSixteen(GameResources*,int),TestStatusZero(GameResources*,int),IsSelectedFloatFieldZeroAfterIntegerConversion(GameResources*,int);
// Original: arm9/main @ 0x0202343C; symbol: func_0202343c; size: 0x18C.
extern "C" void Object_UpdateGraphicsReadinessAndBrightness(unsigned char *self){
if(TestWordMaskNonzero(GetGlobalStatePointer(),65))return;
GameResources *resources=GameResources_GetInstance();void *manager=Object_GetGlobalDisplayManager();
if(self[0x9c3]||*(signed char*)(self+0x9c2)<=0){if(TestIdPresentInSignedCountRecordArray(manager,4))Object_CopyDisplayStateAndClearPendingMode(manager);return;}
if(ContainsHalfwordValueInFiftyTwoByteRecords(manager,4))CommitPendingSelectorAndClearField3CDFlag4(manager);
if(self[0x764]){if(self[0x778]){AllocateAndCopyPresentResourceBuffer(self);self[0x778]=0;}Graphics_DrawConditionalSubDisplaySprites(self);}else{GameState_UpdateFourPartyMemberEntryFlagsAndTimers(self);DispatchStateHandlersByKindAndPhase(self);}
if(TestIdPresentInSignedCountRecordArray(manager,4)){self[0x9c6]=0;self[0x9c7]=0;self[0x9c4]=1;self[0x9c8]=0;}
if(Object_TestSelectedFloatWithinSixteen(resources,0)&&TestStatusZero(resources,1)){
if(self[0x9c6]||self[0x9c7])return;if(!self[0x9c4])return;
if(self[0x9c8]){--self[0x9c8];return;}Graphics_UpdateSubBackgroundScrollByDisplayMode(self);SetSubBrightness(resources,0,25);self[0x9c4]=0;
}else if(IsSelectedFloatFieldZeroAfterIntegerConversion(resources,1))self[0x9c4]=0;
}
