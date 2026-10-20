#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" {
// Original data: arm9/main @ 0x2112160; symbol: data_02112160.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
ARM extern unsigned char CartridgeHandleRemovalNotification_UnknownRoleZeroInitializedStorage[]; void DisableInterruptsAndHaltForever(); void System_DispatchModeTwoAndTerminate(); struct State { char pad[12]; int done; char gap[8]; int (*callback)(int); };
// Original: arm9/main @ 0x020D18D0; symbol: func_020d18d0; size: 0x5C.
 void Cartridge_HandleRemovalNotification(void*,unsigned int reason) { if((reason&63)==17) { if(((State*)CartridgeHandleRemovalNotification_UnknownRoleZeroInitializedStorage)->done)return; int result=0; int(*callback)(int)=((State*)CartridgeHandleRemovalNotification_UnknownRoleZeroInitializedStorage)->callback; if(callback)result=callback(0); if(result)System_DispatchModeTwoAndTerminate(); ((State*)CartridgeHandleRemovalNotification_UnknownRoleZeroInitializedStorage)->done=1; } else DisableInterruptsAndHaltForever(); }
}
