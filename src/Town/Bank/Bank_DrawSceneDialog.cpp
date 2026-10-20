#include <globaldefs.h>
ARM
extern "C" void Bank_DrawDialogAndAmountControls(void *fieldObject);
// Original: arm9/ov003 @ 0x0217E580; symbol: func_ov003_0217e580; size: 0x18.
extern "C" void Bank_DrawSceneDialog(unsigned char *object) {
    void *fieldObject = *(void **)(object + 0x20);
    if (fieldObject != 0) Bank_DrawDialogAndAmountControls(fieldObject);
}
