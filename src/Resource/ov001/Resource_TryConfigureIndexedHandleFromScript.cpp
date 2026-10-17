#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" void ResourceHandle_SetGlobalOwnerAndApplyHandleValue_Main0205EBB4(void*, void*, void*);
extern "C" void Initialize1RecordFields_Main020BC078(void*);
extern "C" unsigned data_ov001_02165958[];
extern "C" unsigned char data_02108760[];
// Original: arm9/ov001 @ 0x021638CC; symbol: func_ov001_021638cc; size: 0x70.
extern "C" int Resource_TryConfigureIndexedHandleFromScript(IntegerParameterView* parameters, int parameterIndex) {
    unsigned index = (unsigned)ReadScriptParameterAsInteger(parameters);
    if (index >= 0x10) return 0;
    unsigned* entry = &data_ov001_02165958[index];
    if (!*entry) return 0;
    int value = 0;
    if (parameterIndex >= 2) value = ReadScriptParameterAsInteger((IntegerParameterView*)((char*)parameters + 8));
    ResourceHandle_SetGlobalOwnerAndApplyHandleValue_Main0205EBB4(data_02108760, entry, (void*)value);
    Initialize1RecordFields_Main020BC078(entry);
    return 1;
}
