#include <globaldefs.h>
extern "C" void Graphics_ConfigureProfilePageLayout(void*, unsigned int, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void func_ov012_02189dfc(void*, void*, int);
extern "C" void func_0205d304(void*, void*, int, int, int, int, int, int);
struct ProfilePageBits { unsigned short index : 5; unsigned short remaining : 11; };
// Build this profile text page and attach it with its page-specific UI options.
// Original: arm9/ov012 @ 0x02189D68; symbol: func_ov012_02189d68; size: 0x94.
extern "C" void func_ov012_02189d68(unsigned char* screen) {
    Graphics_ConfigureProfilePageLayout(screen, screen[0x1371], 16, 1);
    memset(*(void**)(screen + 0x1374), 0, 0x960);
    func_ov012_02189dfc(screen, *(void**)(screen + 0x1374), 0);
    unsigned int index = ((ProfilePageBits*)(screen + 0x13c4))->index;
    int special = 0;
    if (index > 9) special = 1;
    func_0205d304(screen + 0xac, *(void**)(screen + 0x1374), 0, 0, special, 1, 0, 0);
}
