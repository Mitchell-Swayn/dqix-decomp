#pragma thumb off
#pragma optimization_level 2
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" {void System_PushInterruptFourEnabledStateAndDisable();int Network_GetConnectionState();int Network_StepSharedPeerDataExchange(void*);void* Network_GetEnabledSharedPeerData(unsigned);void Interrupts_UpdateTimerOneFromShiftingGlobalMask();}
// Original: arm9/main @ 0x0202BF40; symbol: func_0202bf40; size: 0x10C.
extern "C" void Network_RefreshMemberPacketSnapshots(char* object){System_PushInterruptFourEnabledStateAndDisable();if(Network_GetConnectionState()==5){if(Network_StepSharedPeerDataExchange(object+0x7c0)){char* destination=object+0xbc0;for(unsigned short i=0;i<4;++i){void* source=Network_GetEnabledSharedPeerData(i);char* entry=destination+i*0x74;if(source){MI_CpuCopy8(source,entry,0x74);*(int*)(object+i*4+0xfc4)=1;}else{*(unsigned short*)entry&=~0x18;*(int*)(object+i*4+0xfc4)=0;}}*(int*)(object+0xfc0)=0;}else{for(unsigned short i=0;i<4;++i)*(int*)(object+i*4+0xfc4)=0;*(int*)(object+0xfc0)=1;}}else{for(unsigned short i=0;i<4;++i)*(int*)(object+i*4+0xfc4)=0;*(int*)(object+0xfc0)=0;}Interrupts_UpdateTimerOneFromShiftingGlobalMask();}
