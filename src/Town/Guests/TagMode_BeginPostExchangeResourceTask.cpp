#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" void* Resource_ResetZoneAndAllocator(void*);
extern "C" void Field_InitializeOverlayThirtyOneRequest(void*, unsigned, unsigned);
// Original: arm9/ov003 @ 0x02171CAC; symbol: func_ov003_02171cac; size: 0x4C.
extern "C" void TagMode_BeginPostExchangeResourceTask(unsigned char* object) {
    if (object[0x730] & 2) {
        char* resourceBase = (char*)GameResources_GetInstance() + 0x3000;
        void* target = *(void**)(resourceBase + 0xb48);
        void* value = Resource_ResetZoneAndAllocator(resourceBase);
        Field_InitializeOverlayThirtyOneRequest(target, 0x20, 1);
        *(void**)((char*)target + 8) = value;
        object[0] = 9;
    } else {
        object[0] = 0;
    }
}
