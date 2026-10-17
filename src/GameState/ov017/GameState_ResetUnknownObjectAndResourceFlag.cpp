#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState20GetUnknownGameObjectEv(void *);
extern "C" void SetByteFieldAtOffset253ToOne(void *);
extern "C" void ClearHalfwordAtOffsetC6(void *);
extern "C" void Object_SetByteBEAndSavePreviousInBF(void *, int);
extern "C" void *GameResources_GetInstance(void);
extern "C" void *GameState_GetField3B0ObjectWithFlag4(void *);
extern "C" void Object_SetWordAtOffset23CTo1(void *);
extern "C" void ClearWordAtOffset4MaskedBits(void *, unsigned int);
// Original: arm9/ov017 @ 0x021BFF2C; symbol: func_ov017_021bff2c; size: 0x60.
extern "C" void GameState_ResetUnknownObjectAndResourceFlag(void) {
    void *state = _ZN9GameState11GetInstanceEv();
    void *object = _ZN9GameState20GetUnknownGameObjectEv(state);
    SetByteFieldAtOffset253ToOne(object);
    ClearHalfwordAtOffsetC6(object);
    Object_SetByteBEAndSavePreviousInBF(object, 0);
    void *resources = GameResources_GetInstance();
    void *flagged = GameState_GetField3B0ObjectWithFlag4(state);
    if (flagged != 0) Object_SetWordAtOffset23CTo1(flagged);
    if (resources != 0) ClearWordAtOffset4MaskedBits(resources, 0x80);
}
