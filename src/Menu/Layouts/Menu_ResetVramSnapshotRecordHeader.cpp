#include <globaldefs.h>
struct Item { unsigned short id, flags; char pad[0x70]; unsigned parent, next; };
// Original: arm9/ov011 @ 0x02184374; symbol: func_ov011_02184374; size: 0x18.
extern "C" void Menu_ResetVramSnapshotRecordHeader(Item* self) { self->id=0; self->flags=0; self->parent=0; self->next=0; }
