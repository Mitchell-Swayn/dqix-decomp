#include <globaldefs.h>
ARM
extern "C" unsigned int _Z25DisableSpecificInterruptsj(unsigned int);
extern "C" void _Z24EnableSpecificInterruptsj(unsigned int);
extern "C" int FastIntModulus(int, int);
extern "C" void DisableInterruptsAndHaltForever(void);
// Original: arm9/ov031 @ 0x0223BF48; symbol: PushPointerIntoInterruptProtectedRing; size: 0x58.
// Under interrupt mask 1, advances ring index modulo capacity, halts if full, stores the pointer, updates the index, and restores IRQ state.
extern "C" void PushPointerIntoInterruptProtectedRing(void *ring, void *value) {
    unsigned int irq = _Z25DisableSpecificInterruptsj(1);
    int index = *(unsigned char *)((char *)ring + 3);
    int next = FastIntModulus(index + 1, *(unsigned short *)ring);
    if (next == *(unsigned char *)((char *)ring + 2)) DisableInterruptsAndHaltForever();
    *(void **)((char *)ring + (*(unsigned char *)((char *)ring + 3)) * 4 + 4) = value;
    *(unsigned char *)((char *)ring + 3) = next;
    _Z24EnableSpecificInterruptsj(irq);
}
