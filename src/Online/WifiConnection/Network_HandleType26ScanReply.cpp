#include <globaldefs.h>
ARM
#pragma opt_common_subs off
// Original data: arm9/ov031 @ 0x2290cf8; symbol: data_ov031_02290cf8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage;
extern "C" void DisableInterruptsAndHaltForever();
extern "C" int GameState_IsCallbackStateReady();
extern "C" void Network_UpdateWirelessScanEntryCache(char*);
struct Reply {unsigned short type,status;unsigned short unknown[2];unsigned short mode;};
// Original: arm9/ov031 @ 0x022359E0; symbol: func_ov031_022359e0; size: 0x64.
// For a successful type0x26 reply while enabled, mode5 updates scan entries;
// modes4/5 restart the extended scan through the existing canonical helper.
// Other modes follow the original fatal path.
extern "C" void Network_HandleType26ScanReply(Reply* reply) {
 if(reply->status)return;
 if(WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage[0x1e5c] || reply->type!=0x26)return;
 switch(reply->mode) {
 case 5: Network_UpdateWirelessScanEntryCache((char*)reply);GameState_IsCallbackStateReady();return;
 case 4: GameState_IsCallbackStateReady();return;
 default: DisableInterruptsAndHaltForever();return;
 }
}
