#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *_ZN9GameState20GetUnknownGameObjectEv(void *);
extern "C" void GameObject_RequestMovementInputEnable(void *);
extern "C" void *SystemState_GetGlobalFlags();
extern "C" void SystemState_ClearFlags(unsigned int *, unsigned int);
extern "C" void Field_RestoreBackgroundsAfterActionShortcutDisplay(void *);
extern "C" int LinkedQueue_GetFrontKindOrInvalid(char **);
extern "C" void GameObject_DisableMovementInput(void *, int);

// Original: arm9/ov017 @ 0x02199E98; symbol: ResetUnknownObjectStateForSelectedCodes; size: 0x70.
// When state +0x4080 is set, updates the unknown game object and global mask, runs the state helper, then clears fields/resets animation for selected codes.
extern "C" void ResetUnknownObjectStateForSelectedCodes(void *state) {
    if (*(void **)((unsigned char *)state + 0x4080) == 0) return;
    void *object = _ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
    GameObject_RequestMovementInputEnable(object);
    SystemState_ClearFlags((unsigned int *)SystemState_GetGlobalFlags(), 0x400);
    Field_RestoreBackgroundsAfterActionShortcutDisplay(state);
    char **indirect = *(char ***)((unsigned char *)state + 0x36fc);
    int code = LinkedQueue_GetFrontKindOrInvalid(indirect);
    if (code == 0xa || code == 4 || code == 3 || code == 0x21 || code == 0x24)
        GameObject_DisableMovementInput(object, 1);
}
