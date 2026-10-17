#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int _ZNK9GameState12GetTickCountEv(void *);
extern "C" void func_0204c87c(void *, int);
extern "C" void DrawEnabledPresentRecordGeometry(void *);
extern "C" void func_ov023_021f86fc(void *, int);
// Original: arm9/ov023 @ 0x021F8140; symbol: func_ov023_021f8140; size: 0x50.
extern "C" void Object_UpdateAndDrawPresentRecord(void *object, int value) {
    unsigned char *p = (unsigned char *)object;
    if (p[0xc] & 8) return;
    unsigned int tick = _ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
    func_0204c87c(p + 0x20, tick);
    DrawEnabledPresentRecordGeometry(p + 0x20);
    if (p[0xe5] & 4) func_ov023_021f86fc(object, value);
}
