#include <globaldefs.h>
extern "C" void* Graphics_CreateBG0CanvasForScreen(unsigned, unsigned);
extern "C" int func_ov031_022276b4(void*, int);
extern "C" unsigned func_ov031_022236d0();
extern "C" unsigned char data_ov031_02290c4c[];
extern "C" void func_ov031_0223c980(void*, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" void MarkPrimaryOrSecondaryBufferReady(void*);
// Original: arm9/ov031 @ 0x022235A0; symbol: func_ov031_022235a0; size: 0x74.
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int index) {
    void* buffer = Graphics_CreateBG0CanvasForScreen(0, 0);
    int value = func_ov031_022276b4(*(void**)data_ov031_02290c4c, index);
    unsigned metric = func_ov031_022236d0();
    func_ov031_0223c980(buffer, 0xd, 0x28, 0xe6, 0x70, 2, metric, (unsigned)value);
    MarkPrimaryOrSecondaryBufferReady(buffer);
}
