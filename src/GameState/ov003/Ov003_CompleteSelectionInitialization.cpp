#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance();
extern "C" void func_ov003_0217f118(void*);
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void SetByteFieldAtOffset253ToOne(void*);
extern "C" void* GameState_GetField3B0ObjectWithFlag4(void*);
extern "C" void Object_SetWordAtOffset23CTo1(void*);
extern "C" void ClearMaskedFlagsAtOffset244(unsigned char*, unsigned char);
extern "C" void ClearWordAtOffset4MaskedBits(int, unsigned);
// Original: arm9/ov003 @ 0x0217F1B8; symbol: func_ov003_0217f1b8; size: 0x60.
extern "C" ARM void Ov003_CompleteSelectionInitialization(void* object) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* resources = GameResources_GetInstance();
    func_ov003_0217f118(object);
    SetByteFieldAtOffset253ToOne(_ZN9GameState20GetUnknownGameObjectEv(state));
    void* target = GameState_GetField3B0ObjectWithFlag4(state);
    Object_SetWordAtOffset23CTo1(target);
    ClearMaskedFlagsAtOffset244((unsigned char*)target, 2);
    ClearWordAtOffset4MaskedBits((int)resources, 0xc0);
    *((unsigned char*)object + 1) = 1;
}
