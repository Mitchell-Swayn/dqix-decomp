#include <globaldefs.h>
extern "C" void func_ov023_021e3fc0(void*);
extern "C" void func_ov023_021e4264(void*);
extern "C" void func_ov023_021e4358(void*);
extern "C" void func_ov023_021e43f0(void*);
extern "C" void func_ov005_02154ef0(void*);
// Original: arm9/ov023 @ 0x021E3134; symbol: func_ov023_021e3134; size: 0x50.
extern "C" void Object_RunNestedSetupForValidState(void* object) {
    signed char state = *(signed char*)((char*)object + 0x4e6);
    if (state == 0) return;
    if (state == -1) return;
    func_ov023_021e3fc0(object);
    func_ov023_021e4264(object);
    func_ov023_021e4358(object);
    func_ov023_021e43f0(object);
    void* resource = *(void**)object;
    if (resource) func_ov005_02154ef0(resource);
}
