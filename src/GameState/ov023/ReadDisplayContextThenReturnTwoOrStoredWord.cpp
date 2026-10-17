#include <globaldefs.h>
ARM
extern "C" unsigned int Object_ReadGlobalDisplayContextWord(void);
extern "C" int ReturnOne_Main02094B4C(void);
// Original: arm9/ov023 @ 0x021FD2F8; symbol: func_ov023_021fd2f8; size: 0x20.
extern "C" unsigned int ReadDisplayContextThenReturnTwoOrStoredWord(void *object) {
    Object_ReadGlobalDisplayContextWord();
    if (ReturnOne_Main02094B4C())
        return 2;
    return *(unsigned int *)((char *)object + 0x1c);
}
