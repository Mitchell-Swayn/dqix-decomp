#include <globaldefs.h>
ARM
extern "C" unsigned BattleScene_GetActiveInstance(void);
extern "C" void *BattleScene_GetCamera(unsigned char *);
extern "C" void Camera_SetYawTransition(unsigned char *, short, int);
// Original: arm9/ov025 @ 0x021E8584; symbol: func_ov025_021e8584; size: 0x24.
extern "C" int SetOverlayEmbeddedHalfwordFromObjectFields(void *object) {
    unsigned int control = BattleScene_GetActiveInstance();
    void *embedded = BattleScene_GetCamera((unsigned char *)control);
    Camera_SetYawTransition((unsigned char *)embedded, *(short *)((char *)object + 8), *(unsigned short *)((char *)object + 0xa));
    return 1;
}
