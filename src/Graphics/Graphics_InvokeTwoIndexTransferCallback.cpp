#include <globaldefs.h>

ARM
extern "C" {
struct State { unsigned char pad[28]; unsigned char first:4; unsigned char second:4; };
typedef int (*Callback)(void *,void *);
// Original data: arm9/main @ 0x20f01b8; symbol: data_020f01b8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 04a80402dca70402b4a704028ca7040264a704023ca7040214a70402eca60402.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Callback GraphicsInvokeTwoIndexTransferCallback_UnknownRoleProcedureReferenceRecords[4][4];
// Original: arm9/main @ 0x0204B5E8; symbol: func_0204b5e8; size: 0x38.
int Graphics_InvokeTwoIndexTransferCallback(State *p, void *a, void *b) { return GraphicsInvokeTwoIndexTransferCallback_UnknownRoleProcedureReferenceRecords[p->first][p->second](a,b); }
}
