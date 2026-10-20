#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x20fefec; symbol: data_020fefec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int NetworkGetConnectionManager_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0202AE30; symbol: func_0202ae30; size: 0x1C.
void Network_HandleConnectionEventSixteen(unsigned short *p){if(p[2]==16)NetworkGetConnectionManager_UnknownRoleZeroInitializedStorage[2]=2;}
}
