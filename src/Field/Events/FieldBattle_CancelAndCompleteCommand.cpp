#include <globaldefs.h>
ARM
extern "C" void FieldBattle_ReleaseSceneAndRestoreField(void);
// Original: arm9/ov017 @ 0x021B83F0; symbol: Overlay_ResetObjectResourcesAndSetByte1; size: 0x18.
// Calls the overlay cleanup routine with the object in r0, then sets object byte +1 to one.
extern "C" void FieldBattle_CancelAndCompleteCommand(void *obj) {
    FieldBattle_ReleaseSceneAndRestoreField();
    *((unsigned char *)obj + 1) = 1;
}
