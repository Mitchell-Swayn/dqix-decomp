#include <globaldefs.h>
extern "C" void* Network_GetConnectionManager(); extern "C" int Network_IsSessionActive(void*); extern "C" int Network_IsParentOrOffline(void*);
// Original: arm9/ov017 @ 0x021A01BC; symbol: func_ov017_021a01bc; size: 0x38.
extern "C" ARM void Field_MarkClientZoneRefreshPending(void* self) { void* context=Network_GetConnectionManager();if(!Network_IsSessionActive(context))return;if(!Network_IsParentOrOffline(context))*((unsigned char*)self+0x42e9)=1; }
