#include <globaldefs.h>
extern "C" void func_ov006_0215f3d8(void*);
extern "C" void func_ov006_0215f740(void*);
extern "C" int func_ov006_021595b4(void*);
// Original: arm9/ov006 @ 0x02159564; symbol: func_ov006_02159564; size: 0x50.
extern "C" int Object_RefreshIndexedPointerAndCheckSignedState(void* object) {
    *(void**)((char*)object + 0x44) = (char*)object + 0x364;
    func_ov006_0215f3d8(object);
    short current = *(short*)((char*)object + 0x35e);
    short target = **(short**)((char*)object + 0x44);
    if (current != target) {
        func_ov006_0215f740(object);
        return 0;
    }
    return func_ov006_021595b4(object) != 0;
}
