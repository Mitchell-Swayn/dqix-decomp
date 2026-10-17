#include <globaldefs.h>
ARM
extern "C" void *func_ov004_0215e47c(void *self, unsigned short value);
extern "C" unsigned char data_ov004_021707e8[];
extern "C" void func_ov023_021fc71c(void *, void *, int);
// Original: arm9/ov004 @ 0x02162A9C; symbol: func_ov004_02162a9c; size: 0x30.
extern "C" int Unclassified_ApplyType130LookupToGlobalContext(void *object) {
    void *entry = func_ov004_0215e47c(object, 0x82);
    if (entry != 0)
        func_ov023_021fc71c(entry, *(void **)(data_ov004_021707e8 + 0x1C), 1);
    return 0;
}
