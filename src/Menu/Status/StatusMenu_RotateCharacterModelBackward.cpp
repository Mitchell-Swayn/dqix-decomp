#include <globaldefs.h>
ARM
extern "C" void *Menu_FindCanvasNodeByKey(void *, unsigned);
extern "C" void CharacterPreview_RotateActiveModelLeft(void *, void *);
extern "C" void InvokeEntryHandlerForStateKey(void *, unsigned, unsigned);
// Original: arm9/ov004 @ 0x02162B04; symbol: func_ov004_02162b04; size: 0x38.
extern "C" int StatusMenu_RotateCharacterModelBackward(void *arg) {
    void *result = Menu_FindCanvasNodeByKey(arg, 0x82);
    if (result != 0) {
        CharacterPreview_RotateActiveModelLeft(result, arg);
        InvokeEntryHandlerForStateKey(arg, 0x87, 1);
    }
    return 0;
}
