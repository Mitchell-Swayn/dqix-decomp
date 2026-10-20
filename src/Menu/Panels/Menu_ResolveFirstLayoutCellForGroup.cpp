#include <globaldefs.h>
ARM
extern "C" char *MenuLayout_FindGroupByKey(char *, int);
extern "C" void *Menu_FindLayoutCellByKey(void *, int);
// Original: arm9/ov023 @ 0x021E2418; symbol: Resource_FindValidatedRecordAndResolveNestedKey; size: 0x38.
// Finds a 24-byte record by key, validates its fields, then resolves the nested signed key.
extern "C" void *Menu_ResolveFirstLayoutCellForGroup(void *obj, int key) {
    char *record = MenuLayout_FindGroupByKey((char *)obj, key);
    if (record == 0 || *(unsigned short *)(record + 2) == 0 || *(void **)(record + 4) == 0) return 0;
    int id = *(short *)*(void **)(record + 4);
    return Menu_FindLayoutCellByKey(obj, id);
}
