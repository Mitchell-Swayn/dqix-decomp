#include <globaldefs.h>
ARM
extern "C" void ResetEachIndexedEntryResource(void *);
extern "C" void func_ov003_0215db2c(void *);
// Original: arm9/ov003 @ 0x0215CA68; symbol: func_ov003_0215ca68; size: 0x28.
extern "C" void Resource_ResetIndexedEntriesWhenEnabled(void *object) {
    unsigned char *p = (unsigned char *)object;
    if (p[0x3bc]) {
        ResetEachIndexedEntryResource(p + 0x98);
        func_ov003_0215db2c(object);
    }
}
