#include <globaldefs.h>
ARM
extern "C" unsigned char data_02108760;
extern "C" void DispatchStoredResourceHandleAtOffsetC0(unsigned char *);
extern "C" void UpdateObjectStateAndStoredValue(void *, unsigned int, unsigned short);
extern "C" void ResourceHandle_InvokeOperationWithValidHalfwordIndex(char *, int, int);
extern "C" unsigned long long _Z19GetCurrentTimestampv(void);
extern "C" void *ReadGlobalAt02108F0C(void);
extern "C" void Object_CaptureCurrentZoneOnce(char *);
// Original: arm9/ov017 @ 0x021C2E50; symbol: func_ov017_021c2e50; size: 0x54.
extern "C" void Resource_StartHandleAndCaptureTimestamp(unsigned char *state) {
    DispatchStoredResourceHandleAtOffsetC0(&data_02108760);
    UpdateObjectStateAndStoredValue(&data_02108760, 0xB3, 0xB3);
    ResourceHandle_InvokeOperationWithValidHalfwordIndex((char *)&data_02108760, 0, 0);
    unsigned long long timestamp = _Z19GetCurrentTimestampv();
    *(unsigned int *)(state + 0x98) = (unsigned int)timestamp;
    *(unsigned int *)(state + 0x9C) = (unsigned int)(timestamp >> 32);
    Object_CaptureCurrentZoneOnce((char *)ReadGlobalAt02108F0C());
    state[0x8C] = 3;
}
