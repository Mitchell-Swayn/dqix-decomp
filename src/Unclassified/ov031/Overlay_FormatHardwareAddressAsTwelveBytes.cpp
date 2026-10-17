#include <globaldefs.h>
ARM
extern "C" void System_ReadHardwareMacAddress(void*);
extern "C" void func_ov031_0223fc7c(void*, unsigned char, unsigned);
extern "C" void func_ov031_0223e454(void*, const void*, unsigned);
// Original: arm9/ov031 @ 0x0223FAE8; symbol: func_ov031_0223fae8; size: 0x60.
extern "C" void Overlay_FormatHardwareAddressAsTwelveBytes(void* output) {
    unsigned char workspace[0x14];
    System_ReadHardwareMacAddress(workspace);
    int count = 0;
    unsigned char* source = workspace;
    int offset = count;
    do {
        func_ov031_0223fc7c(workspace + 6 + offset, *source, 2);
        ++source;
        offset += 2;
        ++count;
    } while (count < 6);
    func_ov031_0223e454(output, workspace + 6, 12);
}
