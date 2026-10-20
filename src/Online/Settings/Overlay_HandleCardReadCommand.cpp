#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d24; symbol: data_ov031_02290d24.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage;
extern "C" void _Z40NitroVM_Command_AcquireCardReadResourcest(unsigned short);
extern "C" void _Z40NitroVM_Command_ReleaseCardReadResourcest(unsigned short);
// Original: arm9/ov031 @ 0x0223B560; symbol: func_ov031_0223b560; size: 0x64.
extern "C" int Overlay_HandleCardReadCommand(void *unused, int command) {
    switch (command) {
    case 9:
        _Z40NitroVM_Command_AcquireCardReadResourcest(*(unsigned short *)(WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage + 0xe4));
        return 0;
    case 10:
        _Z40NitroVM_Command_ReleaseCardReadResourcest(*(unsigned short *)(WfcUtilityUnmountUtilityArchive_UnknownRoleZeroInitializedStorage + 0xe4));
        return 0;
    case 1: return 4;
    default: return 8;
    }
}
