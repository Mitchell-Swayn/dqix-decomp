#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" unsigned short func_ov017_021bbc04(char*);
extern "C" void SetHalfwordAtOffset11A(unsigned char*, unsigned short);
extern "C" void Field_WriteNestedHalfword(void*, unsigned short);
// Original: arm9/ov001 @ 0x02162210; symbol: func_ov001_02162210; size: 0x3C.
extern "C" int Resource_CopyAndClearNestedHalfword(void) {
    char* resource = *(char**)((char*)GameResources_GetInstance() + 0x3734);
    unsigned short value = func_ov017_021bbc04(resource);
    if (value != 0) {
        SetHalfwordAtOffset11A((unsigned char*)resource, value);
        Field_WriteNestedHalfword(resource, 0);
    }
    return 1;
}
