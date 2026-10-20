#include <globaldefs.h>
ARM
extern "C" void System_FormatUnboundedString(unsigned, unsigned, ...);
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
extern "C" unsigned char WfcUtility_FormatEditedIpAddress_Format3D3D3D3D[];

// Original: arm9/ov031 @ 0x02236038; symbol: func_ov031_02236038; size: 0x44.
extern "C" void WfcUtility_FormatEditedSecondaryDnsAddress(unsigned first) {
    unsigned char *state = NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
    unsigned char *arguments = state + 0x4cc;
    System_FormatUnboundedString(first,
        (unsigned)WfcUtility_FormatEditedIpAddress_Format3D3D3D3D,
        arguments[0], arguments[1], arguments[2], arguments[3]);
}
