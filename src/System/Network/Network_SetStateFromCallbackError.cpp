#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0202D664; symbol: func_0202d664; size: 0x24.
void Network_SetStateFromCallbackError(unsigned short *p){if(p[1])NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=10;else NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=0;}
}
