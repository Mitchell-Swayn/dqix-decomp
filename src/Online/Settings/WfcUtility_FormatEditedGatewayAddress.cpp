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
// Original: arm9/ov031 @ 0x02235FB0; symbol: func_ov031_02235fb0; size: 0x44.
extern "C" void WfcUtility_FormatEditedGatewayAddress(unsigned value) {
    unsigned char *state = (unsigned char *)NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
    unsigned char *arguments = state + 0x4c4;
    System_FormatUnboundedString(value, (unsigned)&WfcUtility_FormatEditedIpAddress_Format3D3D3D3D,
        arguments[0], arguments[1], arguments[2], arguments[3]);
}
