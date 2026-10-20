#include <globaldefs.h>

extern "C" unsigned UI_ReadLinkedInfoHighFlagNibble(void*, void*);

// Original: arm9/main @ 0x0205AF18; symbol: func_0205af18; size: 0x20.
extern "C" ARM unsigned short Graphics_GetCellPaletteBank(void* owner, void* record) {
    if(record) return (unsigned short)UI_ReadLinkedInfoHighFlagNibble(owner, record);
    return 0;
}
