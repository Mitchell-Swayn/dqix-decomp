#include <globaldefs.h>
#pragma optimization_level 4
extern "C" {
    unsigned int SoundCommand_CountPendingLinkedRecordsAtomically();
    unsigned int CountGlobalLinkedNodesUnderIRQProtection();
// Original: arm9/main @ 0x020D27E0; symbol: func_020d27e0; size: 0x1C.
    unsigned int ComputeRemainingSpaceIn256EntryCommandQueue(){
        unsigned int a=SoundCommand_CountPendingLinkedRecordsAtomically();
        return 256-a-CountGlobalLinkedNodesUnderIRQProtection();
    }
}
