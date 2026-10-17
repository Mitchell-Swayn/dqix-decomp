#include <globaldefs.h>
ARM
extern "C" void func_ov003_02159078(void *);
// Original: arm9/ov017 @ 0x021BABC8; symbol: func_ov017_021babc8; size: 0x18.
extern "C" void Object_UpdateResourcesWhenField1CSet(void *object) {
    void *resource = *(void **)((unsigned char *)object + 0x1c);
    if (resource)
        func_ov003_02159078(resource);
}
