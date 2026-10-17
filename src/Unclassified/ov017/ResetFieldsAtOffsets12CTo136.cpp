#include <globaldefs.h>
ARM
// Writes 0xFFFFFFFF at offset 0x12C and clears bytes at offsets 0x130, 0x131, 0x132, and 0x136.
// Original: arm9/ov017 @ 0x021b994c; symbol: func_ov017_021b994c; size: 0x20.
extern "C" ARM void ResetFieldsAtOffsets12CTo136(void* self) { unsigned char* bytes = (unsigned char*)self; *(unsigned int*)(bytes + 0x12c) = 0xffffffffu; bytes[0x130] = 0; bytes[0x131] = 0; bytes[0x132] = 0; bytes[0x136] = 0; }
