#include <globaldefs.h>
ARM
extern "C" unsigned char* Network_GetConnectionWorkspace(unsigned);
extern "C" void MIi_CpuClear32(int,void*,unsigned);
extern "C" unsigned Network_BuildFreespotScanTargets(void*);
extern "C" unsigned Network_BuildServiceScanTargets(void*);
extern "C" unsigned char MarkEntriesAndCountChangedValues(void*);
extern "C" unsigned Network_FindFirstPendingScanCandidate(void*);
// Original: arm9/ov031 @ 0x02214520; symbol: Resource_RebuildPriorityStateByMode; size: 0x94.
// Rebuilds priority-mask-10 state by mode and returns result byte D10.
extern "C" unsigned Resource_RebuildPriorityStateByMode(int mode) {
 unsigned char* state=Network_GetConnectionWorkspace(16);
 switch(mode){case 0:MIi_CpuClear32(0,state+0x300,0x144);state[0xd10]=Network_BuildFreespotScanTargets(state);break;
 case 1:state[0xd10]=MarkEntriesAndCountChangedValues(state);state[0xd0f]=Network_FindFirstPendingScanCandidate(state);break;
 case 2:MIi_CpuClear32(0,state+0x300,0x144);state[0xd0f]=0;state[0xd10]=Network_BuildServiceScanTargets(state);break;}
 return state[0xd10];
}
