#include <globaldefs.h>
ARM
#include <System/Matrix.h>
#include <System/Interrupts.h>
// Original: arm9/ov031 @ 0x0223BFA0; symbol: WfcUtility_PopPointerRingBack; size: 0x58.
// Removes the last ring entry under interrupt mask 1; returns null if empty.
extern "C" void* WfcUtility_PopPointerRingBack(unsigned char* ring) {
    void* result = 0;
    unsigned int irq = DisableSpecificInterrupts(1);
    if (ring[2] != ring[3]) {
        ring[3] = FastIntModulus(ring[3] + *(unsigned short*)ring - 1, *(unsigned short*)ring);
        result = *(void**)(ring + ring[3] * 4 + 4);
    }
    EnableSpecificInterrupts(irq);
    return result;
}
