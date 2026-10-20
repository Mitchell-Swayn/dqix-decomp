#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" void* FieldEvent_GetInEventResultDescriptor(void*);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
extern "C" void Script_WriteFloatReferenceOutput(unsigned*, unsigned);
// Original: arm9/ov001 @ 0x0216089C; symbol: func_ov001_0216089c; size: 0x4C.
extern "C" int Event_ScriptReadActiveSceneRecordValues(void* output) {
    void* resources = GameResources_GetInstance();
    void* resource = *(void**)((char*)resources + 0x3734);
    unsigned char* record = (unsigned char*)FieldEvent_GetInEventResultDescriptor(resource);
    if ((signed char)record[0] < 0)
        return 0;
    Script_WriteIntegerReferenceOutput(output, record[0x14]);
    Script_WriteFloatReferenceOutput((unsigned*)((char*)output + 8), *(unsigned*)(record + 0x18));
    return 1;
}
