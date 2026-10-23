#include <globaldefs.h>
ARM
extern "C" int FastIntModulus(int, int);
// Original data: arm9/ov031 @ 0x2290c8c; symbol: data_ov031_02290c8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0222C870; symbol: Graphics_WriteModuloDerivedValueToDisplayRegisters; size: 0x5C.
// When shared byte+0x56 is set, computes a masked modulo-derived value, writes display registers 0x04000010 and 0x04000018, then clears the byte.
extern "C" void Graphics_WriteModuloDerivedValueToDisplayRegisters(void*,void*) {
    if (!*(unsigned char*)(*(char**)((char*)&TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 4) + 0x56)) return;
    int value = FastIntModulus(*(unsigned short*)((char*)&TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 2), 0x1c) - 0x32;
    unsigned int display = 0x01ff0000 & ((unsigned int)value << 16);
    *(volatile unsigned int*)0x04000010 = display;
    *(volatile unsigned int*)0x04000018 = display;
    *(unsigned char*)(*(char**)((char*)&TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 4) + 0x56) = 0;
}
