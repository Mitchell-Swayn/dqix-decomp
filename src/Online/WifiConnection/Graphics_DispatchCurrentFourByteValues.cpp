#include <globaldefs.h>
ARM
extern "C" void System_FormatUnboundedString(unsigned a, unsigned b, ...);
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
extern "C" unsigned char WfcUtility_FormatEditedIpAddress_Format3D3D3D3D[];
// Original: arm9/ov031 @ 0x02235F70; symbol: func_ov031_02235f70; size: 0x40.
extern "C" void Graphics_DispatchCurrentFourByteValues(unsigned a) {
    unsigned char* state = NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
    System_FormatUnboundedString(a, (unsigned)WfcUtility_FormatEditedIpAddress_Format3D3D3D3D,
        state[0x4f0], state[0x4f1], state[0x4f2], state[0x4f3]);
}
