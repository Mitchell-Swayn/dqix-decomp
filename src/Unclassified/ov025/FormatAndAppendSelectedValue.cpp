#include <globaldefs.h>
ARM
extern "C" void* data_ov025_021ef988[4];
extern "C" const char data_ov025_021ef7ef[];
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void* GetPointerSelectedByByteIndex(char*);
extern "C" int sprintf(char*, const char*, ...);
extern "C" int func_ov025_021e25a4(const char*);
extern "C" void AppendNonnegativeValueToBoundedHalfwordList(unsigned char*, int);
// Original: arm9/ov025 @ 0x021E40E4; symbol: func_ov025_021e40e4; size: 0x58.
extern "C" int FormatAndAppendSelectedValue(void* object) {
    char buffer[0x50];
    _ZN16BackgroundLoader11GetInstanceEv();
    GetPointerSelectedByByteIndex((char*)data_ov025_021ef988[3]);
    sprintf(buffer, data_ov025_021ef7ef, *(unsigned*)((char*)object + 8));
    int value = func_ov025_021e25a4(buffer);
    AppendNonnegativeValueToBoundedHalfwordList((unsigned char*)((char*)data_ov025_021ef988[3]), value);
    return 1;
}
