#include <globaldefs.h>
ARM
extern "C" unsigned char *GetLastTwoHundredTwentyFourByteRecordWhenCountNonzero(unsigned char *);
extern "C" bool TestField9CEqualsThree(int);
extern "C" void Object_SetWordAtOffset30(void *, unsigned int);
// Original: arm9/ov000 @ 0x02175440; symbol: func_ov000_02175440; size: 0x40.
extern "C" void func_ov000_02175440(unsigned char *obj) {
    unsigned char *record = GetLastTwoHundredTwentyFourByteRecordWhenCountNonzero(obj + 0x188);
    if (record == 0) return;
    if (!TestField9CEqualsThree((int)record)) return;
    if ((record[0xc5] & 2) != 0) return;
    Object_SetWordAtOffset30(obj + 0x18c, 0xffffffff);
}
