#include <globaldefs.h>
ARM
extern "C" void KrakPot_RearmDialogueNotification(void *self);
extern "C" void Util_DispatchPendingModeOnce(char *self);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int _ZNK9GameState21GetEffectiveDeltaTimeEv(void *self);
// Original: arm9/ov006 @ 0x02159FB0; symbol: func_ov006_02159fb0; size: 0x5C.
extern "C" void KrakPot_UpdateDialogueNotificationTimer(unsigned char *self) {
    if (*(int *)(self + 0x3B0) < 0) {
        *(unsigned int *)(self + 0x3A8) = 0;
        KrakPot_RearmDialogueNotification(self);
        return;
    }
    if (*(unsigned int *)(self + 0x3A8) > 0x3C) {
        *(unsigned int *)(self + 0x3A8) = 0;
        KrakPot_RearmDialogueNotification(self);
        Util_DispatchPendingModeOnce((char *)self);
    }
    unsigned int delta = _ZNK9GameState21GetEffectiveDeltaTimeEv(_ZN9GameState11GetInstanceEv());
    *(unsigned int *)(self + 0x3A8) += delta;
}
