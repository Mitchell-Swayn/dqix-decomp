#include <globaldefs.h>
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x21016e0; symbol: data_021016e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char NetworkConfigureStateFromMode_UnknownRoleZeroInitializedStorage[];
extern "C" void MI_CpuCopy8(const void *, void *, unsigned);
extern "C" int Network_BuildAndSubmitConnectionAuxiliaryData();
extern "C" int Network_BeginStateThreeOperationUnlessAlreadyActive();
// Original: arm9/main @ 0x0202DC40; symbol: func_0202dc40; size: 0x74.
extern "C" int Network_ConfigureStateFromMode(unsigned mode, const void *payload) {
    *(unsigned *)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage + 0x2c) = 0x440;
    *(unsigned *)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage + 0x38) = 0x80;
    *(unsigned *)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage + 0x34) = mode;
    *(unsigned *)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage + 0x10) = 3;
    if (mode == 1 || mode == 3 || mode == 5) {
        MI_CpuCopy8(payload, NetworkConfigureStateFromMode_UnknownRoleZeroInitializedStorage, 0xc0);
        if (*(unsigned *)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage + 0x30)) return Network_BuildAndSubmitConnectionAuxiliaryData();
        return Network_BeginStateThreeOperationUnlessAlreadyActive();
    }
    return 0;
}
