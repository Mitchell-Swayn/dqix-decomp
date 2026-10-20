#include <globaldefs.h>
ARM
extern "C" {
extern void* Network_GetConnectionManager();
extern int Network_GetDiscoveredPeerCount(void*);
extern int Network_ConnectToDiscoveredPeerByMacAddress(unsigned char*, const void*);
extern int Network_GetDiscoveredPeerDescriptor(int,int);
extern int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
extern void* SystemState_GetGlobalFlags();
extern void SystemState_ClearFlags(unsigned*,unsigned);
extern void* NavigationMessage_GetGlobalInstance();
extern void NavigationMessage_ResetAndEnable(void*);
extern int NavigationMessage_EnqueueWithFormattedMemberName(unsigned char*,short,int,signed char);
extern void GameResources_SetPrimaryFlags(unsigned*,unsigned);
extern void DisplayOverlay_ConfigureGlobalState(unsigned,unsigned,unsigned,unsigned);
extern void SystemState_SetFlags(unsigned*,unsigned);
extern void* GameResources_GetInstance();
}
// Original: arm9/ov017 @ 0x021AEF80; symbol: Network_ApplyConnectionEntryResult; size: 0x118.
// Waits for a matching six-byte network entry, then either activates its result
// or resets the display and inserts a fallback record.
extern "C" int Network_ApplyConnectionEntryResult(unsigned char* self) {
    void* resources = GameResources_GetInstance();
    void* connection = Network_GetConnectionManager();
    int result = Network_ConnectToDiscoveredPeerByMacAddress((unsigned char*)connection, self + 9);
    for (int delay = 0; delay < 6; ++delay) {}
    if (result >= 0) {
        int count = Network_GetDiscoveredPeerCount(connection);
        for (int i = 0; i < count; ++i) {
            int entry = Network_GetDiscoveredPeerDescriptor((int)connection, i);
            if (entry) { for (int j = 0; j < 6; ++j) {} RuntimeMemory_CompareByteRanges((void*)(entry + 4), self + 9, 6); }
        }
    }
    if (result < 0) {
        SystemState_ClearFlags((unsigned*)SystemState_GetGlobalFlags(), 0x8020);
        void* display = NavigationMessage_GetGlobalInstance();
        NavigationMessage_ResetAndEnable(display);
        NavigationMessage_EnqueueWithFormattedMemberName((unsigned char*)display, 4, -1, 0);
        return 3;
    }
    GameResources_SetPrimaryFlags((unsigned*)resources, 0x40);
    *(unsigned short*)(self + 0x12) = 0;
    DisplayOverlay_ConfigureGlobalState(1, 1, 0, 1);
    SystemState_SetFlags((unsigned*)SystemState_GetGlobalFlags(), 0x800000);
    return 1;
}
