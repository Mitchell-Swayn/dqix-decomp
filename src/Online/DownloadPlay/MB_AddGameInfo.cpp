#include <globaldefs.h>
ARM
struct GameInfoNode { unsigned char pad[0x4bc]; GameInfoNode *next; };
// Original data: arm9/ov027 @ 0x21dd940; symbol: data_ov027_021dd940.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBAddGameInfo_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov027 @ 0x021DADAC; symbol: func_ov027_021dadac; size: 0x44.
// Appends a multiboot game information record to the beacon list.
extern "C" void MB_AddGameInfo(GameInfoNode *node)
{
    GameInfoNode *entry=*(GameInfoNode**)(MBAddGameInfo_UnknownRoleZeroInitializedStorage+24);
    if(!entry)*(GameInfoNode**)(MBAddGameInfo_UnknownRoleZeroInitializedStorage+24)=node;
    else { while(entry->next)entry=entry->next; entry->next=node; }
    node->next=0;
}
