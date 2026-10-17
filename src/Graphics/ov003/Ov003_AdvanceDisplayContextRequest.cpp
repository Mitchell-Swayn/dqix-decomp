#include <globaldefs.h>
extern "C" unsigned int Object_ReadGlobalDisplayContextWord(void);
extern "C" void IgnoreDisplayContextRequest(int, int, int);
extern "C" int ReturnOne_Main02094B4C(void);
// Original: arm9/ov003 @ 0x02159464; symbol: func_ov003_02159464; size: 0x60.
extern "C" void Ov003_AdvanceDisplayContextRequest(char *object) {
    if (*(unsigned char *)(object + 0x59d) == 0) return;
    unsigned int context = Object_ReadGlobalDisplayContextWord();
    if (*(unsigned char *)(object + 0x59e) == 0) {
        IgnoreDisplayContextRequest(context, 0x200, 1);
        *(unsigned char *)(object + 0x59e) = *(unsigned char *)(object + 0x59e) + 1;
        return;
    }
    if (*(unsigned char *)(object + 0x59e) != 1) return;
    if (ReturnOne_Main02094B4C() != 0) {
        *(unsigned char *)(object + 0x59d) = 0;
        *(unsigned char *)(object + 0x59e) = 0;
    }
}
