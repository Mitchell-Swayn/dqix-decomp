#include <globaldefs.h>
ARM
extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned int);
extern "C" unsigned int MenuRecord_GetType(void *);
extern "C" void *Menu_GetRecordMessageTable(void *);
// Original: arm9/ov004 @ 0x0216EA38; symbol: func_ov004_0216ea38; size: 0x3C.
extern "C" void *Menu_FindMessageTableByWidgetKey(void *state, unsigned int key) {
    void *context = Menu_GetDisplayRecordRegistry(state);
    void *object = MenuRecordList_LocateByKey(context, key);
    if (object == 0) goto fail;
    if (MenuRecord_GetType(object) != 4) goto fail;
    return Menu_GetRecordMessageTable(object);
fail:
    return 0;
}
