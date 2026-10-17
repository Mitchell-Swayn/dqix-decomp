#include <globaldefs.h>
ARM
extern "C" void (* volatile data_ov031_02290fc8)(void*);
// Original: arm9/ov031 @ 0x02241720; symbol: func_ov031_02241720; size: 0x3C.
extern "C" void Util_InvokeObjectCallbacks(void* object) {
    if (object == 0)
        return;
    void* value = *(void**)((char*)object + 0x800);
    if (value != 0)
        data_ov031_02290fc8(value);
    data_ov031_02290fc8(object);
}
