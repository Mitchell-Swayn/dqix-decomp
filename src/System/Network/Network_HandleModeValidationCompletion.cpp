#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void Network_RecordWirelessErrorUnlessTerminal(void);
extern "C" int WM_SetIndCallback(unsigned int);
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0202DB08; symbol: func_0202db08; size: 0x5C.
extern "C" void Network_HandleModeValidationCompletion(int param_1) {
    if (*(unsigned short *)(param_1 + 2) != 0) {
        Network_RecordWirelessErrorUnlessTerminal();
        NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4] = 10;
        return;
    }
    if (WM_SetIndCallback(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[16]) != 0) {
        Network_RecordWirelessErrorUnlessTerminal();
        NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4] = 10;
        return;
    }
    NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4] = 1;
}
