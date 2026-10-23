#include <globaldefs.h>
ARM
extern "C" unsigned char* Network_FindTcpSocketForReceivedSegment(void*,void*);
extern "C" void _Z28CycleCurrentPriorityContextsv();
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
// Original: arm9/ov031 @ 0x02202810; symbol: CyclePriorityContextAndReleaseExpiredWrapper; size: 0x3C.
// Cycles priority context, clears wrapper byte +8, decrements +4, and clears/switches the context when the decremented value is at most one.
extern "C" void CyclePriorityContextAndReleaseExpiredWrapper(void* header,void* keys) {
    unsigned char* wrapper = (unsigned char*)Network_FindTcpSocketForReceivedSegment(header,keys);
    if (!wrapper) return;
    _Z28CycleCurrentPriorityContextsv();
    wrapper[8] = 0;
    unsigned int state = *(unsigned int*)(wrapper + 4) - 1;
    if (state > 1) return;
    *(unsigned int*)(wrapper + 4) = 0;
    _Z25MarkContextReadyAndSwitchP16ProcessorContext(*(void**)wrapper);
}
