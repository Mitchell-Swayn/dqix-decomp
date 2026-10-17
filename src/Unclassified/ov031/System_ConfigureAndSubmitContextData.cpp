#include <globaldefs.h>
THUMB
extern "C" unsigned char data_ov031_0224e6e0[];
extern "C" unsigned char data_ov031_0224b0dc[];
extern "C" void func_ov031_0221e52c(void *, unsigned int, unsigned int);
extern "C" void System_Copy8WithReversedPointers(void *, const void *, unsigned int);
extern "C" unsigned int func_ov031_0221e650(const char *);
extern "C" void func_ov031_0221e354(void *, unsigned int, void *, unsigned int);
extern "C" void func_ov031_0221e028(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, void *);
extern "C" void func_ov031_0221e080(void *, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x0221DEDC; symbol: func_ov031_0221dedc; size: 0x6C.
extern "C" int System_ConfigureAndSubmitContextData(void *unused, const unsigned char *data, unsigned int value) {
    void *context = *(void **)(data_ov031_0224e6e0 + 0x14);
    func_ov031_0221e52c(context, 0, 0x5dc);
    unsigned char buffer[8];
    System_Copy8WithReversedPointers(buffer, data + 0x10, 8);
    unsigned int name = func_ov031_0221e650((const char *)data_ov031_0224b0dc);
    func_ov031_0221e354(buffer, 8, data_ov031_0224b0dc, name);
    func_ov031_0221e028(context, 0x3000, 0, 0, 0, 0x11, buffer);
    func_ov031_0221e080(context, 0x18, 0, value);
    return 0;
}
