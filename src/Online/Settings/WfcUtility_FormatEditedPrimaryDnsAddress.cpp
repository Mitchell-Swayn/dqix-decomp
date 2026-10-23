#include <globaldefs.h>
ARM
#pragma force_active on
// Original data: arm9/ov031 @ 0x02290cfc; symbol: data_ov031_02290cfc.
// Initial value: zero-filled at load; runtime pointer or shared state storage.
// Field offsets and indexed loads follow the original instructions.
// Full initial contents and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x0224be50; symbol: data_ov031_0224be50.
// Initial value: "%3d.%3d.%3d.%3d" plus its terminating null byte.
// Field offsets and indexed loads follow the original instructions.
// Full initial contents and references: docs/data-symbols/ov031.md.
extern "C" unsigned NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
extern "C" unsigned WfcUtility_FormatEditedIpAddress_Format3D3D3D3D;
extern "C" void System_FormatUnboundedString(unsigned, unsigned, ...);
// Original: arm9/ov031 @ 0x02235FF4; symbol: func_ov031_02235ff4; size: 0x44.
// Formats the four edited primary DNS octets into the destination string.
extern "C" void WfcUtility_FormatEditedPrimaryDnsAddress(unsigned destination)
{
    unsigned char *settings = (unsigned char *)NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
    unsigned char *dns = settings + 0x4c8;
    System_FormatUnboundedString(destination, (unsigned)&WfcUtility_FormatEditedIpAddress_Format3D3D3D3D,
        dns[0], dns[1], dns[2], dns[3]);
}
#pragma force_active reset
