#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();extern "C" void _Z20SetIRQInterruptStatei(int);extern "C" void* data_02112780;
// Original: arm9/main @ 0x020D2768; symbol: func_020d2768; size: 0x3C.
extern "C" unsigned SoundCommand_CountPendingLinkedRecordsAtomically(){int state=_Z20DisableIRQInterruptsv();unsigned count=0;void* node=data_02112780;if(node){do{node=*(void**)node;++count;}while(node);}_Z20SetIRQInterruptStatei(state);return count;}
