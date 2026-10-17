#include <globaldefs.h>
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void* GetPointerSelectedByByteIndex(char*);
extern "C" unsigned char data_ov025_021ef988[];
extern "C" int Combat_FormatScaledValue(int, char*);
extern "C" int func_ov025_021e25a4(char*);
extern "C" void AppendNonnegativeValueToBoundedHalfwordList(unsigned char*, int);
// Original: arm9/ov025 @ 0x021E4A08; symbol: func_ov025_021e4a08; size: 0x50.
extern "C" int BackgroundLoader_FormatAndAppendSelectedValue(void* object) {
    (void)_ZN16BackgroundLoader11GetInstanceEv();
    GetPointerSelectedByByteIndex(*(char**)(data_ov025_021ef988 + 0x0c));
    char buffer[0x50];
    Combat_FormatScaledValue(*(int*)((char*)object + 8), buffer);
    int value = func_ov025_021e25a4(buffer);
    AppendNonnegativeValueToBoundedHalfwordList(*(unsigned char**)(data_ov025_021ef988 + 0x0c), value);
    return 1;
}
