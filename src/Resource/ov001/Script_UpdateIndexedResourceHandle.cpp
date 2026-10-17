#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void*);
extern "C" void ResourceHandle_SetGlobalOwnerAndApplyHandleValue_Main0205EABC(void*, void*, void*);
extern "C" void Initialize1RecordFields_Main020BC078(void*);
extern "C" unsigned char data_ov001_02165958[];
extern "C" unsigned char data_02108760;
// Original: arm9/ov001 @ 0x021635D0; symbol: func_ov001_021635d0; size: 0x70.
extern "C" int Script_UpdateIndexedResourceHandle(void* parameters, int count) {
    unsigned index = (unsigned)ReadScriptParameterAsInteger(parameters);
    if (index >= 0x10) return 0;
    void** slot = (void**)(data_ov001_02165958 + index * 4);
    if (*slot == 0) return 0;
    int value = 0;
    if (count >= 2) value = ReadScriptParameterAsInteger((char*)parameters + 8);
    ResourceHandle_SetGlobalOwnerAndApplyHandleValue_Main0205EABC(&data_02108760, slot, (void*)value);
    Initialize1RecordFields_Main020BC078(slot);
    return 1;
}
