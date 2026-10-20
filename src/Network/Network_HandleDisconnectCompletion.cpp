#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[];void Network_RecordWirelessErrorUnlessTerminal(int);
// Original: arm9/main @ 0x0202D5EC; symbol: func_0202d5ec; size: 0x28.
void Network_HandleDisconnectCompletion(unsigned short *p){unsigned int v=p[1];if(!v){NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=1;return;}Network_RecordWirelessErrorUnlessTerminal(v);}
}
