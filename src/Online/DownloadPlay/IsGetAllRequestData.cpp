#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e3424; symbol: data_ov027_021e3424.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char IsGetAllRequestData_UnknownRoleZeroInitializedStorage[];
struct RequestBuffer { unsigned char records[15][32]; unsigned masks[15]; };
struct RequestConfig { unsigned unused; RequestBuffer *buffer; unsigned pieceLength; int pieceCount; };
#define C ((RequestConfig*)IsGetAllRequestData_UnknownRoleZeroInitializedStorage)
// Original: arm9/ov027 @ 0x021DD864; symbol: func_ov027_021dd864; size: 0x54.
// Checks each expected request-piece bit for the selected child.
extern "C" int IsGetAllRequestData(unsigned child)
{
    for(unsigned short piece=0;piece<C->pieceCount;piece++)if(!(C->buffer->masks[child-1]&(1<<piece)))return 0;
    return 1;
}
