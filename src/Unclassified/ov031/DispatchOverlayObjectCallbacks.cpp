#include <globaldefs.h>
ARM
typedef void (*OverlayCallback)(void*);
extern "C" OverlayCallback data_ov031_02290fc8[1];
extern "C" void func_ov031_02240e1c(void*);
// Original: arm9/ov031 @ 0x02240E70; symbol: func_ov031_02240e70; size: 0x78.
extern "C" int DispatchOverlayObjectCallbacks(unsigned char* object) {
    func_ov031_02240e1c(*(void**)(object + 0x34));
    func_ov031_02240e1c(*(void**)(object + 0x38));
    volatile void** fields = (volatile void**)object;
    if (fields[8]) {
        void* nested = *(void**)((char*)fields[8] + 0x800);
        if (nested)
            data_ov031_02290fc8[0](nested);
        data_ov031_02290fc8[0]((void*)fields[8]);
    }
    data_ov031_02290fc8[0]((void*)fields[9]);
    data_ov031_02290fc8[0](object);
    return 1;
}
