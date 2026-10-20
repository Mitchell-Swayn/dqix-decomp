#include <globaldefs.h>
extern "C" char* GameResources_GetInstance();extern "C" int LinkedList_ContainsTag(unsigned,int);extern "C" void LinkedQueue_RemoveNodeAndResetStatus(unsigned,unsigned);extern "C" void GameState_ResetThreeSubsystemsAndMarkComplete(unsigned);
// Original: arm9/main @ 0x020D9A58; symbol: func_020d9a58; size: 0x58.
extern "C" ARM void ZoneTransition_CancelPairedRequestsAndFinishReset(unsigned a){char* p=GameResources_GetInstance();unsigned resource=*(unsigned*)(p+0x36fc);if(LinkedList_ContainsTag(resource,28)){LinkedQueue_RemoveNodeAndResetStatus(resource,*(unsigned*)(p+0x3b14));LinkedQueue_RemoveNodeAndResetStatus(resource,*(unsigned*)(p+0x370c));}GameState_ResetThreeSubsystemsAndMarkComplete(a);}
