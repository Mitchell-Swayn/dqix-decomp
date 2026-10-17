#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov025_021ef988[];
extern "C" unsigned short func_ov025_021eb050(void*);
extern "C" void Object_WriteHalfwordAtOffset57C(void*, unsigned short);
// Original: arm9/ov025 @ 0x021E3C3C; symbol: func_ov025_021e3c3c; size: 0x3C.
extern "C" int Object_ClearOffset57COnMatchingValue(void* self) {
    if (*(unsigned short*)((char*)self + 8) == func_ov025_021eb050(*(void**)(data_ov025_021ef988 + 0xc))) {
        Object_WriteHalfwordAtOffset57C(*(void**)(data_ov025_021ef988 + 0xc), 0);
    }
    return 1;
}
