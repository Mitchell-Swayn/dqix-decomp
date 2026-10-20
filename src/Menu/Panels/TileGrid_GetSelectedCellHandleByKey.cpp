#include <globaldefs.h>
ARM
extern "C" void *TileGrid_ResolveByKey(void *, unsigned int);
extern "C" unsigned int Menu_GetSelectedGridColumn(void *);
extern "C" unsigned int Menu_GetSelectedGridRow(void *);
extern "C" int Menu_ReadGridEntryOrZero(void *, unsigned int, unsigned int);
// Original: arm9/ov023 @ 0x021F6558; symbol: UpdateRecordFromResolvedType7Object; size: 0x38.
// Looks up a type-7 object; when present, forwards its halfwords +0x28 and +0x2A to the record updater.
extern "C" int TileGrid_GetSelectedCellHandleByKey(void *state, unsigned int index) {
 void *obj = TileGrid_ResolveByKey(state, index);
 if (!obj) return -1;
 unsigned int value2a = Menu_GetSelectedGridColumn(obj);
 unsigned int value28 = Menu_GetSelectedGridRow(obj);
 return Menu_ReadGridEntryOrZero(obj, value28, value2a);
}
