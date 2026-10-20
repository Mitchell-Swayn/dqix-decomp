#include <globaldefs.h>
ARM
extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned int);
// Original: arm9/ov004 @ 0x021537A8; symbol: func_ov004_021537a8; size: 0x34.
extern "C" void Menu_SetKeyedControlMode(void *state, unsigned int key, int value) {
    void *context = Menu_GetDisplayRecordRegistry(state);
    void *node = MenuRecordList_LocateByKey(context, key);
    if (node == 0) return;
    void **vtable = *(void ***)node;
    ((void (*)(void *, int))vtable[0x3c / 4])(node, value);
}
