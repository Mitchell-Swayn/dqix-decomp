#include <globaldefs.h>
#include <System/Interrupts.h>
struct OV031PointerPair { void* first; void* second; };
// Relinks two pointer slots and clears the pair while interrupts are masked.
// Original: arm9/ov031 @ 0x0223D8A0; symbol: func_ov031_0223d8a0; size: 0x38.
extern "C" ARM void WfcUtility_UnlinkListNode(OV031PointerPair* pair)
{
    unsigned int state = DisableSpecificInterrupts(1);
    *(void**)((char*)pair->first + 4) = pair->second;
    *(void**)pair->second = pair->first;
    pair->second = 0;
    pair->first = 0;
    EnableSpecificInterrupts(state);
}
