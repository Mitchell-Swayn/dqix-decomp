#include <globaldefs.h>
ARM
extern "C" void func_ov006_021571b8(void *, int);
extern "C" void Ov006_ProcessObjectWhenFlag800Set(void *);
// Original: arm9/ov006 @ 0x0215A5DC; symbol: func_ov006_0215a5dc; size: 0x20.
extern "C" void Object_UpdateRelatedField10State(void *object) {
    unsigned char *p = (unsigned char *)object;
    func_ov006_021571b8(*(void **)(p + 0x10), p[0x38b]);
    Ov006_ProcessObjectWhenFlag800Set(*(void **)(p + 0x10));
}
