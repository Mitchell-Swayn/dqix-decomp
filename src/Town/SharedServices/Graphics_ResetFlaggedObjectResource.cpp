#include <globaldefs.h>
ARM
extern "C" void Graphics_TransferScreenBuffer(void *, int);
// Original: arm9/ov003 @ 0x0216720C; symbol: Graphics_ResetFlaggedObjectResource; size: 0x34.
// When flag 0x40000 is set, resets the pointed resource entry at object+0x328+0x40, then clears the flag.
extern "C" void Graphics_ResetFlaggedObjectResource(void *object) {
 if (*(unsigned int *)((char *)object + 0x464) & 0x40000) {
  Graphics_TransferScreenBuffer((char *)*(void **)((char *)object + 0x328) + 0x40, 0);
  *(unsigned int *)((char *)object + 0x464) &= ~0x40000u;
 }
}
