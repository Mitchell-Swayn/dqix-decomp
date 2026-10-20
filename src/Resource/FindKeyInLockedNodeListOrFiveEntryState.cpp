#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma optimization_level 3
extern "C" void System_PushInterruptFourEnabledStateAndDisable();extern "C" void Interrupts_UpdateTimerOneFromShiftingGlobalMask();extern "C" void* Network_GetConnectionManager();extern "C" unsigned char* Network_GetLocalMemberPacket(void*);
// Original: arm9/main @ 0x0205E4F8; symbol: func_0205e4f8; size: 0x84.
extern "C" int FindKeyInLockedNodeListOrFiveEntryState(unsigned char* p,int key){int found=0;System_PushInterruptFourEnabledStateAndDisable();unsigned char* node=*(unsigned char**)(p+0x150c);while(node){if(node[0]==key){found=1;break;}node=*(unsigned char**)(node+24);}if(!found){unsigned char* list=Network_GetLocalMemberPacket(Network_GetConnectionManager());for(int i=0;i<5;i++)if(list[i*20+16]==key){found=1;break;}}Interrupts_UpdateTimerOneFromShiftingGlobalMask();return found;}
