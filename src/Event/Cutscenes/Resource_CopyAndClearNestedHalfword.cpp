#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" unsigned short FieldEvent_GetPendingContinuationEventId(char*);
extern "C" void FieldEvent_SetContinuationEventId(unsigned char*, unsigned short);
extern "C" void FieldEvent_SetPendingContinuationEventId(void*, unsigned short);
// Original: arm9/ov001 @ 0x02162210; symbol: func_ov001_02162210; size: 0x3C.
extern "C" int Resource_CopyAndClearNestedHalfword(void) {
    char* resource = *(char**)((char*)GameResources_GetInstance() + 0x3734);
    unsigned short value = FieldEvent_GetPendingContinuationEventId(resource);
    if (value != 0) {
        FieldEvent_SetContinuationEventId((unsigned char*)resource, value);
        FieldEvent_SetPendingContinuationEventId(resource, 0);
    }
    return 1;
}
