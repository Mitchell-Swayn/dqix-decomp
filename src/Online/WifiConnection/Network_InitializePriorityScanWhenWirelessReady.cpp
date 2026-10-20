#include <globaldefs.h>
ARM
extern "C" unsigned Network_GetWirelessLifecycleState();
extern "C" unsigned char* Network_GetConnectionWorkspace(unsigned);
extern "C" void Resource_RebuildPriorityStateByMode(unsigned);
extern "C" int Network_StartWirelessInitializationUnderIRQ(void*,void(*)());
extern "C" void SetPriorityStateActionFromEvent();
extern "C" void GameState_SetSelectedStateWordFields(unsigned);
// Original: arm9/ov031 @ 0x022151D4; symbol: SubmitSharedStateByteWhenReady; size: 0x88.
// Submits state byteD0A as four-word parameters when shared word2260 is one; returns1/2/17 by readiness/result.
extern "C" int Network_InitializePriorityScanWhenWirelessReady(){
 unsigned ready=Network_GetWirelessLifecycleState();unsigned char* state=Network_GetConnectionWorkspace(16);
 if(ready==1){unsigned params[4];params[0]=state[0xd0a];params[1]=0;params[2]=0;params[3]=0;
 Resource_RebuildPriorityStateByMode(0);int result=Network_StartWirelessInitializationUnderIRQ(params,SetPriorityStateActionFromEvent);
 if(result==1||result>=4){GameState_SetSelectedStateWordFields(1);return 17;}}else return 1;
 return 2;
}
