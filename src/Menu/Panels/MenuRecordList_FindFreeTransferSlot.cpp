#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F6E5C; symbol: MenuRecordList_FindFreeTransferSlot; size: 0x34.
// Maintains indexed menu record slots and grid access.
extern "C" int MenuRecordList_FindFreeTransferSlot(char* self, unsigned char selector) {
 int index=0;
 for (; index<16; ++index) {
  if (!(*(unsigned short*)(self + selector*2 + 0x2c) & (1 << index))) return index;
 }
 return -1;
}
