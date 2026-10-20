#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21dd940; symbol: data_ov027_021dd940.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBAddGameInfo_UnknownRoleZeroInitializedStorage[];
struct FixedBeaconState { unsigned char pad[28]; unsigned char *entry,*cursor; unsigned char state,pad1[3],total; };
#define S ((FixedBeaconState*)MBAddGameInfo_UnknownRoleZeroInitializedStorage)
// Original: arm9/ov027 @ 0x021DAF6C; symbol: func_ov027_021daf6c; size: 0x54.
// Initializes fixed-beacon chunk count and skips missing icon data when marked unavailable.
extern "C" void MBi_InitSendFixedBeacon(void)
{
    if(S->state!=2)return;
    unsigned char *entry=S->entry;
    if(!entry[0x4b2]) { S->total=9; S->cursor=entry; }
    else { S->total=4; S->cursor=entry+0x220; }
    S->state=3;
}
