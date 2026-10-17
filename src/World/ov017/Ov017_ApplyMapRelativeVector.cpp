#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void Vector3fix_Subtract(const void*, const void*, void*);
extern "C" int func_ov017_0218db14(void*, const void*, int, int, unsigned char);
// Original: arm9/ov017 @ 0x0218DAA8; symbol: func_ov017_0218daa8; size: 0x6C.
extern "C" ARM int Ov017_ApplyMapRelativeVector(void* owner, const void* position, int arg2, int arg3, unsigned char mode) {
    void* map = _ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
    if (!position) return 0;
    if (!map) return 0;
    int delta[3];
    Vector3fix_Subtract((char*)map + 0x44, position, delta);
    return func_ov017_0218db14(owner, delta, arg2, arg3, mode);
}
