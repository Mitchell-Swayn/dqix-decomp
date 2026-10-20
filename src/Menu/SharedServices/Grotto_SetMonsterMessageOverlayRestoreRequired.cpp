#include <globaldefs.h>
ARM
// Original: arm9/ov004 @ 0x0216FA74; symbol: Object_WriteByteAtOffsetF; size: 0x8.
// Stores the supplied byte at object offset 0x0f. The field meaning is not established.
extern "C" void Grotto_SetMonsterMessageOverlayRestoreRequired(void* self, unsigned char value) { *((unsigned char*)self + 0x0f) = value; }
