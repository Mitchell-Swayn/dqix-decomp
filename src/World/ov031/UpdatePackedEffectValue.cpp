#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02250c00[];
extern "C" void ReadPackedEntryFields(void*, int, unsigned*, unsigned*);
extern "C" int func_ov031_022266b0(unsigned, unsigned);
extern "C" int func_ov031_022269d8();
extern "C" int OV031_WriteWordField08(void*, void*);
extern "C" void InitializeOverlayInputHandlers();
// Original: arm9/ov031 @ 0x02225EA0; symbol: func_ov031_02225ea0; size: 0x74.
extern "C" int UpdatePackedEffectValue(void* object) {
    unsigned high, low;
    void* source = *(void**)data_ov031_02250c00;
    ReadPackedEntryFields(*(void**)((char*)source + 0x40), 0, &high, &low);
    unsigned adjusted = low - 0xc;
    low = adjusted;
    if ((int)adjusted > 0xaa) return func_ov031_022266b0(4, adjusted);
    func_ov031_022266b0(4, 0xaa);
    func_ov031_022269d8();
    return OV031_WriteWordField08(object, (void*)InitializeOverlayInputHandlers);
}
