#include <globaldefs.h>
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[];
extern "C" void Network_RecordWirelessErrorUnlessTerminal(...);
extern "C" int Network_BeginStateThreeOperationUnlessAlreadyActive(void);
// Original: arm9/main @ 0x0202D1E4; symbol: func_0202d1e4; size: 0x40.
extern "C" void Network_HandleConnectionAuxiliaryDataCompletion(void* object) {
    if (*(unsigned short*)((char*)object+2)!=0) {
        Network_RecordWirelessErrorUnlessTerminal();
        NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=9;
        return;
    }
    if (Network_BeginStateThreeOperationUnlessAlreadyActive()==0)
        NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=9;
}
