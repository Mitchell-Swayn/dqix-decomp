#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original data: arm9/main @ 0x2102be0; symbol: data_02102be0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2080 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char NetworkGetEnabledSharedPeerData_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/main @ 0x2101980; symbol: data_02101980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 512 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char NetworkGetEnabledSharedPeerData_UnknownRoleZeroInitializedStorage[];
    bool WM_GetSharedDataAddress(void *,void *,int);
// Original: arm9/main @ 0x0202DCB4; symbol: func_0202dcb4; size: 0x20.
    bool Network_GetEnabledSharedPeerData(int i){
        return WM_GetSharedDataAddress(NetworkGetEnabledSharedPeerData_UnknownRoleZeroInitializedStorage_Variant2,NetworkGetEnabledSharedPeerData_UnknownRoleZeroInitializedStorage,i);
    }
}
