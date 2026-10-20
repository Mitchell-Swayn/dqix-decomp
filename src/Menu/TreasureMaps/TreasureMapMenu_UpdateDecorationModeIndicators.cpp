#include <globaldefs.h>
ARM
// Original: arm9/ov004 @ 0x021651C8; symbol: UpdatePairRecordFlagFromGlobalMode; size: 0xF4.
// Updates bit eight on two keyed records after the corresponding validity checks.
extern "C" {
// Original data: arm9/ov004 @ 0x2171010; symbol: data_ov004_02171010.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern unsigned char *PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage;
void *Menu_GetDisplayRecordRegistry(void *self);
void *MenuRecordList_LocateByKey(void **head, unsigned short value);
unsigned MenuRecord_GetType(void *record);
}
extern "C" int TreasureMapMenu_UpdateDecorationModeIndicators(void *self) {
    if (!PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage[0x18f4]) return 0;
    void *record = MenuRecordList_LocateByKey((void **)Menu_GetDisplayRecordRegistry(self), (unsigned short)0x1f5);
    if (!record) return 0;
    if (MenuRecord_GetType(record) != 1) return 0;
    unsigned char current = PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage[0x18fc];
    if (current == 0) *((unsigned char *)record + 0xc) |= 0x08;
    else if (current == 1) { unsigned int bits = *((unsigned char *)record + 0xc); bits &= ~8u; *((unsigned char *)record + 0xc) = (unsigned char)bits; }
    record = MenuRecordList_LocateByKey((void **)Menu_GetDisplayRecordRegistry(self), (unsigned short)0x1f6);
    if (!record) return 0;
    if (MenuRecord_GetType(record) != 1) return 0;
    current = PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage[0x18fc];
    if (current == 0) { unsigned int bits = *((unsigned char *)record + 0xc); bits &= ~8u; *((unsigned char *)record + 0xc) = (unsigned char)bits; }
    else if (current == 1) *((unsigned char *)record + 0xc) |= 0x08;
    return 0;
}
