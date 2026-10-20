#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B1FB8; symbol: Unclassified_GetPointerAtOffset2A; size: 0x8.
// Returns the input structure pointer advanced by 0x2A; adjacent accessors read bytes at +0x28/+0x29.
extern "C" void *OnlineDownload_GetLegacyMapDiscovererName(void *self) { return (unsigned char *)self + 0x2a; }
