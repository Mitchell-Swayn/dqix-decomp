#include <globaldefs.h>
ARM
#pragma opt_propagation off
struct MaskHeader { unsigned short present, enabled; unsigned char entries[1]; };
extern "C" void* ComputeMaskedIndexPopulationStrideAndBase(void*, unsigned, const void*, unsigned);
// Original: arm9/main @ 0x020D6830; symbol: func_020d6830; size: 0x54.
extern "C" void* WM_GetSharedDataAddress(void* self, const MaskHeader* header, unsigned bit) {
 unsigned present = header->present, enabled = header->enabled;
 unsigned mask = 1;
 if (!self) return 0;
 if (!header) return 0;
 if (!(present & (mask << bit))) return 0;
 if (!(enabled & (mask << bit))) return 0;
 return ComputeMaskedIndexPopulationStrideAndBase(self, present, header->entries, bit);
}
