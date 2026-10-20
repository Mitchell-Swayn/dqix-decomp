#include <globaldefs.h>
ARM
extern "C" void* Network_FindTcpSocketForReceivedSegment();
extern "C" void _Z28CycleCurrentPriorityContextsv();
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
// Original: arm9/ov031 @ 0x02202810; symbol: CyclePriorityContextAndReleaseExpiredWrapper; size: 0x3C.
// Cycles priority context, clears wrapper byte +8, decrements +4, and clears/switches the context when the decremented value is at most one.
extern "C" void CyclePriorityContextAndReleaseExpiredWrapper() {
    unsigned char* wrapper = (unsigned char*)Network_FindTcpSocketForReceivedSegment();
    if (!wrapper) return;
    _Z28CycleCurrentPriorityContextsv();
    wrapper[8] = 0;
    unsigned int state = *(unsigned int*)(wrapper + 4) - 1;
    if (state > 1) return;
    *(unsigned int*)(wrapper + 4) = 0;
    _Z25MarkContextReadyAndSwitchP16ProcessorContext(*(void**)wrapper);
}
