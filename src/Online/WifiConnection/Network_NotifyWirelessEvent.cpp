#include <globaldefs.h>
#pragma optimize_for_size off
ARM
struct WirelessEvent { unsigned short event; unsigned short detail; int first; int second; int third; };
typedef void (*WirelessEventCallback)(WirelessEvent*);
// Original data: arm9/ov031 @ 0x0224e53c; symbol: data_ov031_0224e53c.
extern "C" unsigned NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0220D9C8; symbol: func_ov031_0220d9c8; size: 0x54.
extern "C" void Network_NotifyWirelessEvent(int event, int detail, int first, int second, int third) {
    unsigned char* workspace = (unsigned char*)NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
    if (*(WirelessEventCallback*)(workspace + 0x227c) == 0) return;
    WirelessEvent packet;
    packet.event = (unsigned short)event;
    packet.detail = (unsigned short)detail;
    packet.first = first;
    packet.second = second;
    packet.third = third;
    (*(WirelessEventCallback*)(workspace + 0x227c))(&packet);
}
