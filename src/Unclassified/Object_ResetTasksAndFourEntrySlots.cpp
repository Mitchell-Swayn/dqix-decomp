#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void func_020dc7e8(int, int);
extern "C" void func_020200c0(int, void *);
// Original: arm9/main @ 0x02020AA0; symbol: func_02020aa0; size: 0x4C.
extern "C" void Object_ResetTasksAndFourEntrySlots(void *object, int, int, int) {
    func_020dc7e8(6, -1);
    func_020dc7e8(7, -1);
    signed char i = 0;
    goto check;
body:
    func_020200c0(i, (char *)object + 0xe8);
    i = (signed char)(i + 1);
check:
    if (i < 4) goto body;
}
