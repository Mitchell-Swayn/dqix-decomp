#include <globaldefs.h>
extern "C" unsigned char data_ov031_0224e590[];
extern "C" int func_ov031_0220f4bc();
extern "C" int Overlay_UnblockContextsWhenInactive();
extern "C" int func_ov031_02211410();
extern "C" void func_ov031_02211b98(unsigned, void *, unsigned);
// Original: arm9/ov031 @ 0x0221126C; symbol: func_ov031_0221126c; size: 0x78.
extern "C" int OV031_ProcessSharedStringRequest(void) {
    int ok = 1;
    void *request = *(void **)data_ov031_0224e590;
    if (!request) return ok;
    *(unsigned *)request = 3;
    if (func_ov031_0220f4bc() == 0) ok = 0;
    if (Overlay_UnblockContextsWhenInactive() == 0) ok = 0;
    if (ok) {
        unsigned length = func_ov031_02211410();
        func_ov031_02211b98(0x53574300, *(void **)data_ov031_0224e590, length);
        *(void **)data_ov031_0224e590 = 0;
    }
    return ok;
}
