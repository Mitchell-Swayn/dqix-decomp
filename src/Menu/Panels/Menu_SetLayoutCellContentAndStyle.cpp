#include <globaldefs.h>
ARM
struct LayoutCell { unsigned char pad[3]; unsigned char low:4; unsigned char high:4; unsigned pad2[2]; unsigned content; };
extern "C" LayoutCell* Menu_ResolveFirstLayoutCellForGroup(void*, unsigned short);
// Original: arm9/ov023 @ 0x021E23D0; symbol: Menu_SetLayoutCellContentAndStyle; size: 0x48.
// Resolves a layout cell, stores content and updates its packed style nibbles.
extern "C" void Menu_SetLayoutCellContentAndStyle(void* owner, unsigned short group, unsigned content, unsigned char low, unsigned char high) {
 LayoutCell* cell = Menu_ResolveFirstLayoutCellForGroup(owner,group);
 if (!cell) return;
 cell->content = content;
 cell->low = low;
 cell->high = high;
}
