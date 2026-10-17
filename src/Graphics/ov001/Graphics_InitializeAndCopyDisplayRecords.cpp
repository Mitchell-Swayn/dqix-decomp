#include <globaldefs.h>
ARM

extern "C" void func_ov001_021588bc(void *, void *, unsigned);
extern "C" void InitializeSessionRecords(void *, void *, unsigned);
extern "C" void func_ov001_0215a79c(void);
extern "C" unsigned char data_ov001_02165880[];

// Original: arm9/ov001 @ 0x0215A8DC; symbol: func_ov001_0215a8dc; size: 0x78.
extern "C" void Graphics_InitializeAndCopyDisplayRecords(void) {
    volatile unsigned short *display = (volatile unsigned short *)0x04000060;
    *display = (unsigned short)(*display & 0xCFFB);
    func_ov001_021588bc(*(void **)(data_ov001_02165880 + 0x24), *(void **)(data_ov001_02165880 + 8), 8);
    for (int i = 0; i < 0x18; i++) {
        void *destination = (char *)*(void **)(data_ov001_02165880 + 0x1C) + i * 0x588;
        void *source = *(void **)(data_ov001_02165880 + 0x20);
        InitializeSessionRecords(destination, source, 0x1C);
    }
    func_ov001_0215a79c();
}
