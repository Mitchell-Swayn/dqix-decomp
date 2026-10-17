#include <globaldefs.h>
ARM

extern "C" void *ReadGlobalValueAt020FB3F0(void);
extern "C" void UpdateObjectThroughThreeHandlers(int object);
extern "C" bool _ZN13ZoneState084018IsValueInRangeC3b5Ei(void *, int);
extern "C" void SnapshotBlockAndVolatileWordPair(char *p);

// Original: arm9/ov017 @ 0x0218D5C8; symbol: func_ov017_0218d5c8; size: 0x50.
extern "C" void World_UpdateAndSnapshotObjectState(char *self) {
    int pending = *(int *)(self + 0x4498);
    if (pending != 0) {
        UpdateObjectThroughThreeHandlers(pending);
    }
    char *global = (char *)ReadGlobalValueAt020FB3F0();
    int value = *(unsigned short *)global;
    bool inRange = _ZN13ZoneState084018IsValueInRangeC3b5Ei(global + 0x840, value);
    char *snapshot = self + 0x2cc;
    if (inRange) snapshot += 0x930;
    else snapshot += 0xc40;
    SnapshotBlockAndVolatileWordPair(snapshot);
    *(int *)(self + 0x4498) = 0;
}
