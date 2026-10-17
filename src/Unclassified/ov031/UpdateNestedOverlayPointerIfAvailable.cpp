#include <globaldefs.h>
ARM
extern "C" void* data_ov031_0224e580;
extern "C" int StoreReadySharedValue(int);
extern "C" void Unclassified_ResetStateAndSetFlags(void);
// Original: arm9/ov031 @ 0x0220F728; symbol: func_ov031_0220f728; size: 0x48.
extern "C" void UpdateNestedOverlayPointerIfAvailable(void) {
    if (StoreReadySharedValue(0)) {
        void* state = *(void**)&data_ov031_0224e580;
        char* object = *(char**)((char*)state + 0x24);
        *(void**)(object + 0x24) = **(void***)((char*)object + 0xc);
        state = *(void**)&data_ov031_0224e580;
        object = *(char**)((char*)state + 0x24);
        *(unsigned*)(object + 0x20) = 1;
    }
    Unclassified_ResetStateAndSetFlags();
}
