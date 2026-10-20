#include <globaldefs.h>
ARM
extern "C" void *Menu_FindInventoryDetailWidgetByKey(void);
extern "C" void *MenuBackground_GetResourceState(void *);
// Original: arm9/ov004 @ 0x02157088; symbol: func_ov004_02157088; size: 0x1C.
extern "C" void *Menu_GetInventoryDetailState(void) {
    void *pointer = Menu_FindInventoryDetailWidgetByKey();
    if (pointer == 0)
        return 0;
    return MenuBackground_GetResourceState(pointer);
}
