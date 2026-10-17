#include <globaldefs.h>
ARM
extern "C" unsigned int Object_ReadGlobalDisplayContextWord();
extern "C" void DisplayContext_IgnoreCommand(void *context, int command, int parameter, int option0, int option1);
extern "C" int ReturnOne_Main02094B4C(unsigned);
// Original: arm9/ov003 @ 0x02160EC4; symbol: func_ov003_02160ec4; size: 0x88.
extern "C" void Graphics_AdvanceDisplayCommandFlag1000(char *self) {
    if (*(unsigned *)(self + 0x464) & 0x1000) {
        if (*(unsigned char *)(self + 0x4a7) == 0) {
            DisplayContext_IgnoreCommand((void *)Object_ReadGlobalDisplayContextWord(), 501, 102, 0, 0);
            ++*(unsigned char *)(self + 0x4a7);
        } else if (*(unsigned char *)(self + 0x4a7) == 1) {
            if (ReturnOne_Main02094B4C(Object_ReadGlobalDisplayContextWord())) {
                *(unsigned *)(self + 0x464) &= ~0x1000;
                ++*(unsigned char *)(self + 0x4a7);
            }
        }
    }
}
