#include <globaldefs.h>
extern "C" void Graphics_ResetCountedTransferEntriesWithModeZero(void*);
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void Object_ConfigureTextCountThroughEmbeddedHandler(void*, int);
extern "C" void func_020439b0(void*, int);
// Original: arm9/ov017 @ 0x021AAEC8; symbol: func_ov017_021aaec8; size: 0x40.
extern "C" void Graphics_ResetTransferStateAndConfigureTextCount(void* object) {
    if (*(unsigned*)((char*)object + 0x14) == 5) {
        void* state = *(void**)((char*)object + 0x18);
        if (state) Graphics_ResetCountedTransferEntriesWithModeZero(state);
    }
    unsigned value = ReadWordFieldAtOffset1C();
    Object_ConfigureTextCountThroughEmbeddedHandler((void*)value, 8);
    func_020439b0((void*)value, 0);
}
