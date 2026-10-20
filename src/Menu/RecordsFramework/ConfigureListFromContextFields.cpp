#include <globaldefs.h>
ARM
extern "C" void MenuRecordList_ReleaseSpriteSlotRange(void *, unsigned char, unsigned short, int);
extern "C" void UnlinkNodeFromDoublyLinkedList(void *, void *);
extern "C" void MenuRecordList_ReleaseTransferSlot(void *, unsigned char, unsigned);
// Original: arm9/ov023 @ 0x021FB640; symbol: ConfigureListFromContextFields; size: 0x40.
// Copies context fields +0x7E, +0x90, +0x94, and +0x5C into the three adjacent list setters.
extern "C" void ConfigureListFromContextFields(const unsigned char *context, void *list) {
    MenuRecordList_ReleaseSpriteSlotRange(list, context[0x7e], *(const unsigned short *)(context + 0x90), 1);
    UnlinkNodeFromDoublyLinkedList(list, (void *)(context + 0x94));
    MenuRecordList_ReleaseTransferSlot(list, context[0x7e], *(const unsigned *)(context + 0x5c));
}
