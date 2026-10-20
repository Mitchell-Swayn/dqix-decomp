#include <globaldefs.h>
ARM
// Original data: arm9/ov002 @ 0x216c9c0; symbol: data_ov002_0216c9c0.
// Menu logical slot to storage slot mapping; Overlay_WriteByteAtTableOffsetFromObjectIndex reads index*4.
// Initial values: hex 00000000020000000100000003000000040000000500000006000000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" unsigned PartyMenuAssignMappedCommandSlot_MenuLogicalSlotToStorageSlotMapping[];
// Original: arm9/ov002 @ 0x0215A9CC; symbol: Overlay_WriteByteAtTableOffsetFromObjectIndex; size: 0x24.
// Uses the signed index at object offset 0x1C0A to select a table offset, then writes the supplied byte at object offset 0x1C7C plus that offset.
extern "C" void PartyMenu_AssignMappedCommandSlot(void *object, unsigned char value) {
    int index = *(short *)((char *)object + 0x1c0a);
    unsigned offset = PartyMenuAssignMappedCommandSlot_MenuLogicalSlotToStorageSlotMapping[index];
    *((unsigned char *)object + offset + 0x1c7c) = value;
}
