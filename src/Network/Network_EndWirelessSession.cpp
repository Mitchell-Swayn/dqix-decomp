#include <globaldefs.h>

// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[];
extern "C" void Network_SetStateFromCallbackError();
extern "C" int WM_End(void (*callback)());

// Original: arm9/main @ 0x0202DF10; symbol: func_0202df10; size: 0x48.
extern "C" int Network_EndWirelessSession()
{
    NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4] = 3;
    int result = WM_End(Network_SetStateFromCallbackError);
    if (result != 2) {
        NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4] = 9;
        return 0;
    }
    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage) + 0xe) = 0;
    return 1;
}
