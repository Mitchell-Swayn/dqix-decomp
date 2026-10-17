#include <globaldefs.h>
ARM
extern "C" void *func_ov011_021849c8(void *);
extern "C" void *func_ov023_021f6880(void *, unsigned int);
extern "C" unsigned OV023_ReadHalfwordField04(void *);
extern "C" void func_ov023_021fbddc(void *);
// Original: arm9/ov004 @ 0x0216863C; symbol: func_ov004_0216863c; size: 0x34.
extern "C" int Ov004_CheckAndUpdateTypeSeven(void *state) {
    void *object = func_ov011_021849c8(state);
    object = func_ov023_021f6880(object, 7);
    if (object != 0 && OV023_ReadHalfwordField04(object) == 0x10) {
        func_ov023_021fbddc(object);
    }
    return 0;
}
