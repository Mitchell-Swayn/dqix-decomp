#include <globaldefs.h>
ARM
extern "C" unsigned char DlcDownload_FormatSdkUserAgent_FormatNitroWiFiSDKDD[];
extern "C" void Text_FormatBoundedVariadicString(void *a, unsigned b, unsigned c, ...);
// Original: arm9/ov031 @ 0x0223EA60; symbol: func_ov031_0223ea60; size: 0x24.
extern "C" void DlcDownload_FormatSdkUserAgent(void *object) {
    Text_FormatBoundedVariadicString(object, 0x21, (unsigned)DlcDownload_FormatSdkUserAgent_FormatNitroWiFiSDKDD, 3, 1);
}
