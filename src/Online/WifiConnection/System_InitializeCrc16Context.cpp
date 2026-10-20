#include <globaldefs.h>
ARM
extern "C" void *Memory_AllocateZeroedBlock(unsigned, unsigned);
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile unsigned int NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
extern "C" void CRC16_BuildReflectedPolynomialTable(unsigned short *, unsigned);
extern "C" void WfcUtility_ReadFourSettingsPages(void *);
// Original: arm9/ov031 @ 0x02235C18; symbol: System_InitializeCrc16Context; size: 0x44.
// Allocates a 0x6F8-byte context, stores its pointer globally, builds a reflected CRC-16 table at +0x4F8 using polynomial 0xA001, and initializes the context.
extern "C" void System_InitializeCrc16Context(void) {
    void *allocation = Memory_AllocateZeroedBlock(0x6f8, 0x20);
    NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage = (unsigned int)allocation;
    CRC16_BuildReflectedPolynomialTable((unsigned short *)((unsigned char *)allocation + 0x4f8), 0xa001);
    WfcUtility_ReadFourSettingsPages((void *)NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage);
}
