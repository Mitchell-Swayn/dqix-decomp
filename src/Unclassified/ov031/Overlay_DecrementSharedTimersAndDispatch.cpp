#include <globaldefs.h>
ARM
extern "C" unsigned data_ov031_02290ca0;
extern "C" void func_ov031_0222f9ec(void);
// Original: arm9/ov031 @ 0x02230CD8; symbol: func_ov031_02230cd8; size: 0x54.
extern "C" void Overlay_DecrementSharedTimersAndDispatch(void) {
    int i = 0;
    do {
        unsigned char* count = *(unsigned char**)((char*)&data_ov031_02290ca0 + 8) + i + 4;
        if (*count != 0) {
            *count = *count - 1;
            if (*(*(unsigned char**)((char*)&data_ov031_02290ca0 + 8) + i + 4) == 0)
                func_ov031_0222f9ec();
        }
        ++i;
    } while (i < 4);
}
