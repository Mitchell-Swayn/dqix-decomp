#pragma optimize_for_size off
#pragma opt_common_subs off
#include <globaldefs.h>

extern "C" void ResourceJob_RunCallbacksUnderMutexes(void*);
extern "C" void InitializeRangeStateAndDerivedValue(void* target, int value, int duration);

struct FlaggedObject {
    char pad0[0xe8];
    char subobject[0x28];       // 0xe8
    int flagBit0 : 1;           // 0x110
    int flagBit1 : 1;
    int flagBit2 : 1;
    int flagBit3 : 1;
    int flagRest : 28;
    char pad1[0x150 - 0x114];
    int counter;                // 0x150
};

// Original: arm9/main @ 0x020BF148; symbol: func_020bf148; size: 0x58.
extern "C" void EnableSubobjectRangeAndResetCounterWhenFlagged(FlaggedObject* self, int enable) {
    if ((int)((unsigned int)(*(unsigned int*)((char*)self + 0x110)) << 30) >> 31 == 0) {
        ResourceJob_RunCallbacksUnderMutexes(self);
        return;
    }
    if (enable == 0) {
        ResourceJob_RunCallbacksUnderMutexes(self);
        return;
    }
    InitializeRangeStateAndDerivedValue(self->subobject, 0, enable);
    self->flagBit3 = 1;
    self->counter = 0;
}
