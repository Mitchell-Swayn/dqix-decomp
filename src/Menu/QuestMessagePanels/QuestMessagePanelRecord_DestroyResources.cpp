#include <globaldefs.h>
ARM
struct State;
extern "C" void BackgroundLoader_RemoveTasksDestroyAllocatorsAndResetGraphicsState(State *p);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *allocator);
// Original: arm9/ov004 @ 0x021678BC; symbol: func_ov004_021678bc; size: 0x1C.
extern "C" void QuestMessagePanelRecord_DestroyResources(State *self) {
    BackgroundLoader_RemoveTasksDestroyAllocatorsAndResetGraphicsState((State *)((char *)self + 0x34));
    _ZN13SafeAllocator7DestroyEv((char *)self + 0x20);
}
