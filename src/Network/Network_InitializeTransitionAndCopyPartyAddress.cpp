#include <globaldefs.h>
ARM
extern "C" void Network_ResetConnectionManager(void*);
extern "C" void System_PushInterruptFourEnabledStateAndDisable();
extern "C" unsigned short WirelessCommand_IncrementTimeSeededSequence();
extern "C" int Network_BeginModeValidationRequest();
extern "C" void _Z19SleepCurrentContextj(unsigned);
extern "C" int WM_SetIndCallback(unsigned);
extern "C" void Network_HandleConnectionEventSixteen();
extern "C" void Network_SetDiscoveryGameIdentifier(unsigned);
extern "C" int GameState_EnterFlaggedTransitionAndFade(void*,int);
extern "C" void Network_RestartOperationAndTrackFailure();
extern "C" void WM_SetMPTiming(void*,unsigned short,unsigned short);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void Interrupts_UpdateTimerOneFromShiftingGlobalMask();
struct Address { unsigned char bytes[6]; };
// Original: arm9/main @ 0x0202B000; symbol: Network_InitializeTransitionAndCopyPartyAddress; size: 0xf4.
// Initializes network transition, waits up to 5000 ticks and copies the six-byte party address.
extern "C" unsigned char Network_InitializeTransitionAndCopyPartyAddress(char *object){
Network_ResetConnectionManager(object);System_PushInterruptFourEnabledStateAndDisable();*(unsigned short*)(object+4)=WirelessCommand_IncrementTimeSeededSequence();
 int elapsed=0;while(!Network_BeginModeValidationRequest()){if(++elapsed>5000)break;_Z19SleepCurrentContextj(1);}
 WM_SetIndCallback((unsigned)Network_HandleConnectionEventSixteen);Network_SetDiscoveryGameIdentifier(0x785);*(int*)object=1;
 int result=GameState_EnterFlaggedTransitionAndFade(object,1);
 if(result){Network_RestartOperationAndTrackFailure();GameState_EnterFlaggedTransitionAndFade(object,1);}
 WM_SetMPTiming(0,255,235);
 Address local=*(Address*)((char*)_ZN9GameState11GetInstanceEv()+0x74fe);
 *(Address*)(object+0x102c)=local;
 Interrupts_UpdateTimerOneFromShiftingGlobalMask();return result;
}
