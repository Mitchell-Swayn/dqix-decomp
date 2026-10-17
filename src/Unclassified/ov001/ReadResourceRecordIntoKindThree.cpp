#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" void* func_ov017_021bbbe4(void*);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
extern "C" void SetKindThreeIndirectWord4(unsigned*, unsigned);
// Original: arm9/ov001 @ 0x0216089C; symbol: func_ov001_0216089c; size: 0x4C.
extern "C" int ReadResourceRecordIntoKindThree(void* output) {
    void* resources = GameResources_GetInstance();
    void* resource = *(void**)((char*)resources + 0x3734);
    unsigned char* record = (unsigned char*)func_ov017_021bbbe4(resource);
    if ((signed char)record[0] < 0)
        return 0;
    SetNestedSecondWordForTypeThree(output, record[0x14]);
    SetKindThreeIndirectWord4((unsigned*)((char*)output + 8), *(unsigned*)(record + 0x18));
    return 1;
}
