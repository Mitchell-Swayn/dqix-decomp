#include <globaldefs.h>

#pragma opt_lifetimes off
#pragma opt_propagation off
struct State { unsigned char pad0[2]; unsigned short value2; unsigned char pad4[2]; unsigned short sequence; unsigned char pad8[8]; int status; unsigned char pad14[12]; unsigned seed; };
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" State NetworkGetAssociationId_UnknownRoleZeroInitializedStorage;
extern "C" { void System_ReadHardwareMacAddress(unsigned short*); unsigned short Network_SelectAvailableChannelAndStartRequest(unsigned short); void Network_RecordWirelessErrorUnlessTerminal(unsigned); }
// Original: arm9/main @ 0x0202D6C8; symbol: func_0202d6c8; size: 0xC0.
extern "C" ARM int Network_BeginChannelLoadMeasurement() {
    unsigned short id[3];
    System_ReadHardwareMacAddress(id);
    int seed = *(int*)0x027ffc3c;
    unsigned sum = (unsigned)(id[0] + seed + id[1] + id[2]);
    NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.seed = sum * 0x10dcd + 0x3039;
    NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.value2 = 0;
    NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.sequence = 101;
    NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.status = 3;
    int result = Network_SelectAvailableChannelAndStartRequest(1);
    if (result == 24) { Network_RecordWirelessErrorUnlessTerminal(24); NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.status = 9; return 0; }
    if (result == 2) return 1;
    Network_RecordWirelessErrorUnlessTerminal(result); NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.status = 9; return 0;
}
