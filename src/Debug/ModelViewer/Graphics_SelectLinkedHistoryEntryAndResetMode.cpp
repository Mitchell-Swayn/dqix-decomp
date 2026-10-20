#include <globaldefs.h>
ARM
struct History;
struct HistoryNode { unsigned value; HistoryNode* next; };
extern "C" void CharacterViewer_PushMenuHistory(History*, int);
extern "C" void CharacterViewer_RebuildMenu(void*, int);
// Original: arm9/ov015 @ 0x02191EA4; symbol: func_ov015_02191ea4; size: 0x60.
// Selects an indexed history node, saves its value, and resets the owner mode.
extern "C" void Graphics_SelectLinkedHistoryEntryAndResetMode(unsigned char* self, int index) {
    int current;
    HistoryNode* node = *(HistoryNode**)(self + 0x2c);
    if (!node) return;
    current = 0;
    while (current < index) {
        node = node->next;
        ++current;
    }
    if (!node) return;
    *(unsigned*)(self + 0x34) = node->value;
    CharacterViewer_PushMenuHistory((History*)self, *(int*)(self + 0x1a4));
    *(int*)(self + 0x1a4) = 0x25;
    CharacterViewer_RebuildMenu(self, 0);
}
