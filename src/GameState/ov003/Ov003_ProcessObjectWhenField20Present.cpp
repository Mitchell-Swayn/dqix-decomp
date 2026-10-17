#include <globaldefs.h>
ARM
extern "C" void GameState_ResetIndexedTransferResources(void *fieldObject);
// Original: arm9/ov003 @ 0x0217E580; symbol: func_ov003_0217e580; size: 0x18.
extern "C" void Ov003_ProcessObjectWhenField20Present(unsigned char *object) {
    void *fieldObject = *(void **)(object + 0x20);
    if (fieldObject != 0) GameState_ResetIndexedTransferResources(fieldObject);
}
