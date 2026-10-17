#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();extern "C" void _Z20SetIRQInterruptStatei(int);extern "C" void* data_02112780[];
// Original: arm9/main @ 0x020D28A8; symbol: func_020d28a8; size: 0x48.
extern "C" void* SoundCommand_PopPendingRecordAtomically(){int state=_Z20DisableIRQInterruptsv();void* q=data_02112780[0];if(!q){_Z20SetIRQInterruptStatei(state);return 0;}void* next=*(void**)q;data_02112780[0]=next;if(!next)data_02112780[4]=0;_Z20SetIRQInterruptStatei(state);return q;}
