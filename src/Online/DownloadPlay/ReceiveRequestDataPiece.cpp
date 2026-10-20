#include <globaldefs.h>
#include <System/Memory.h>
ARM
extern "C" int IsGetAllRequestData(unsigned);
struct RequestPieces { unsigned char records[15][32]; unsigned masks[15]; };
struct PieceConfig { unsigned unused; RequestPieces *buffer; unsigned pieceLength; int lastPiece; };
// Original data: arm9/ov027 @ 0x21e3424; symbol: data_ov027_021e3424.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" PieceConfig IsGetAllRequestData_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov027 @ 0x021DD7D8; symbol: func_ov027_021dd7d8; size: 0x8C.
// Copies a child request fragment and returns its 32-byte record once every piece is received.
extern "C" void *ReceiveRequestDataPiece(unsigned char *packet,unsigned child)
{
    unsigned index;
    if(!IsGetAllRequestData_UnknownRoleZeroInitializedStorage.buffer)return 0;
    unsigned char piece=packet[2];
    if((int)piece>IsGetAllRequestData_UnknownRoleZeroInitializedStorage.lastPiece)return 0;
    index=child-1;
    MI_CpuCopy8(packet+3,IsGetAllRequestData_UnknownRoleZeroInitializedStorage.buffer->records[index]+piece*IsGetAllRequestData_UnknownRoleZeroInitializedStorage.pieceLength,IsGetAllRequestData_UnknownRoleZeroInitializedStorage.pieceLength);
    IsGetAllRequestData_UnknownRoleZeroInitializedStorage.buffer->masks[index]|=1<<piece;
    if(!IsGetAllRequestData(child))return 0;
    return IsGetAllRequestData_UnknownRoleZeroInitializedStorage.buffer->records[index];
}
