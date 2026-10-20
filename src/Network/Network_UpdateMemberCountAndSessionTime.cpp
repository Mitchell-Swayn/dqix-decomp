#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <System/Timing.h>
extern "C" void System_PushInterruptFourEnabledStateAndDisable(),Interrupts_UpdateTimerOneFromShiftingGlobalMask(),Network_RefreshAdvertisedPartyCount(void*),GameState_CopyElapsedTimeIntoTwoConfigurationRecords(int);extern "C" unsigned Network_IsMemberActive(void*,int);
// Original: arm9/main @ 0x0202C288; symbol: func_0202c288; size: 0xD8.
extern "C" void Network_UpdateMemberCountAndSessionTime(unsigned char* object){System_PushInterruptFourEnabledStateAndDisable();unsigned char old=object[0x100d];int active=*(int*)object!=0;if(!active)object[0x100d]=1;else{object[0x100d]=0;for(int i=0;i<4;++i)if(Network_IsMemberActive(object,i))++object[0x100d];Network_RefreshAdvertisedPartyCount(object);}if(*(int*)object==5){if(object[0x100d]==1&&old>1)GameState_CopyElapsedTimeIntoTwoConfigurationRecords(1);else if(object[0x100d]>1&&old==1){GameState* state=GameState::GetInstance();*(unsigned long long*)((unsigned char*)state+0x3f0)=GetCurrentTimestamp();}}Interrupts_UpdateTimerOneFromShiftingGlobalMask();}
