#include <globaldefs.h>
ARM
extern "C" void System_ReadHardwareMacAddress(void*);
extern "C" void NasAuth_FormatLowercaseHexDigits(void*, unsigned char, unsigned);
extern "C" void DlcDownload_EncodeBase64String(void*, const void*, unsigned);
// Original: arm9/ov031 @ 0x0223FAE8; symbol: func_ov031_0223fae8; size: 0x60.
extern "C" void NasAuth_FormatMacAddressAsLowercaseHex(void* output) {
    unsigned char workspace[0x14];
    System_ReadHardwareMacAddress(workspace);
    int count = 0;
    unsigned char* source = workspace;
    int offset = count;
    do {
        NasAuth_FormatLowercaseHexDigits(workspace + 6 + offset, *source, 2);
        ++source;
        offset += 2;
        ++count;
    } while (count < 6);
    DlcDownload_EncodeBase64String(output, workspace + 6, 12);
}
