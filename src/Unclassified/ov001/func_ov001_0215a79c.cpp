#include <globaldefs.h>
ARM
extern unsigned char data_ov001_021658b8[];
extern unsigned int data_ov001_021659a8[];
extern unsigned char data_ov001_02165958[];
extern "C" void Initialize1RecordFields_Main020BC078(void*);
// Original: arm9/ov001 @ 0x0215A79C; symbol: func_ov001_0215a79c; size: 0x7C.
extern "C" void func_ov001_0215a79c(void) {
    *(unsigned int*)(data_ov001_021658b8 + 0xe8) = 0;
    *(unsigned int*)(data_ov001_021658b8 + 0xec) = 0;
    *(unsigned int*)(data_ov001_021658b8 + 0xe0) = 0;
    for (int i = 0; i < 0xe9; i++) data_ov001_021659a8[i] = 0;
    *(unsigned int*)(data_ov001_021658b8 + 0xe4) = 0;
    for (int i = 0; i < 0x10; i++) Initialize1RecordFields_Main020BC078(data_ov001_02165958 + i * 4);
    *(unsigned int*)(data_ov001_021658b8 + 0x4b4) = 0;
    *(unsigned int*)(data_ov001_021658b8 + 0x4b8) = 0;
}
