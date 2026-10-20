#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int _ZNK9GameState12GetTickCountEv(void *);
extern "C" void QuestMessagePanel_UpdateAndDrawIndicators(void *, unsigned int);
// Original: arm9/ov004 @ 0x021678D8; symbol: func_ov004_021678d8; size: 0x30.
extern "C" void QuestMessagePanelRecord_UpdateIndicators(void *object) {
    if ((*(unsigned char *)((unsigned char *)object + 0x0c) & 0x10) != 0)
        return;
    unsigned int tick = _ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
    if (tick == 0)
        tick = 1;
    QuestMessagePanel_UpdateAndDrawIndicators((unsigned char *)object + 0x34, tick);
}
