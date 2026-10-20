#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x20e8ed8; symbol: data_020e8ed8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ff0102030405060708ff0a0b0c0d0e0f101112131415161718ff1a1b1c1d1e1f20212223242526ff2829ff2b2c2d2e00.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
char *_ZN15LightingManager11GetInstanceEv();void *Network_GetConnectionManager();int Network_IsSessionActive(void *);extern signed char BgmMapZoneKindForLightingAndNetworkSession_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x0209CAF0; symbol: func_0209caf0; size: 0x78.
int Bgm_MapZoneKindForLightingAndNetworkSession(unsigned int i){if(i>=47)return -1;if(!*(int *)(_ZN15LightingManager11GetInstanceEv()+0x98)){int n=BgmMapZoneKindForLightingAndNetworkSession_UnknownRoleInitializedBytes[i];if(n==3)return 4;if(n==5)return 6;}if(Network_IsSessionActive(Network_GetConnectionManager())&&BgmMapZoneKindForLightingAndNetworkSession_UnknownRoleInitializedBytes[i]==14)return 16;return BgmMapZoneKindForLightingAndNetworkSession_UnknownRoleInitializedBytes[i];}
}
