#include <globaldefs.h>
ARM
extern "C" void func_ov011_021848a0(void *, unsigned int);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
// Original: arm9/ov004 @ 0x02165868; symbol: func_ov004_02165868; size: 0x20.
extern "C" void func_ov004_02165868(void *self) {
    func_ov011_021848a0(self, 0x6c);
    volatile unsigned char *p = (volatile unsigned char *)_ZN9GameState11GetInstanceEv() + 0x6000;
    p[0x46e] = 0;
}
