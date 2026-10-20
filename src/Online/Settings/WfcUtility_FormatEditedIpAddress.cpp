#include <globaldefs.h>
ARM
extern "C" void System_FormatUnboundedString(unsigned, unsigned, ...);
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
extern "C" unsigned int WfcUtility_FormatEditedIpAddress_Format3D3D3D3D;
// Original: arm9/ov031 @ 0x02235F30; symbol: func_ov031_02235f30; size: 0x40.
extern "C" void WfcUtility_FormatEditedIpAddress(unsigned arg) {
    unsigned char* p = (unsigned char*)NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
    System_FormatUnboundedString(arg, (unsigned)&WfcUtility_FormatEditedIpAddress_Format3D3D3D3D,
        p[0x4c0], p[0x4c1], p[0x4c2], p[0x4c3]);
}
