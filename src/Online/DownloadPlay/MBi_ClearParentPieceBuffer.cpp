#include <globaldefs.h>
#include <System/Memory.h>
ARM
// Original data: arm9/ov027 @ 0x21e3424; symbol: data_ov027_021e3424.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char IsGetAllRequestData_UnknownRoleZeroInitializedStorage[];
struct ParentPieces { unsigned char records[15][32]; unsigned masks[15]; };
#define P (*(ParentPieces**)(IsGetAllRequestData_UnknownRoleZeroInitializedStorage+4))
// Original: arm9/ov027 @ 0x021DD5F4; symbol: func_ov027_021dd5f4; size: 0x44.
// Clears the selected child request payload and its received-piece mask.
extern "C" void MBi_ClearParentPieceBuffer(unsigned child)
{
    if(!P)return;
    unsigned index=child-1;
    VectorizedMemset(P->records[index],0,30);
    P->masks[index]=0;
}
