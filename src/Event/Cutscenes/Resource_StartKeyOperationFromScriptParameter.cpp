#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void *parameter);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" void Bgm_StopPlaybackAndResetController(int object);
extern "C" void ResourceHandle_StartKeyOperationAndRefreshState(char *p, int key, unsigned int a, unsigned int b);

// Original: arm9/ov001 @ 0x021637A8; symbol: func_ov001_021637a8; size: 0x2C.
extern "C" int Resource_StartKeyOperationFromScriptParameter(void *parameter) {
    int key = Script_ReadParameterAsInteger(parameter);
    char *object = Main_UnknownRoleZeroInitializedStorage_Variant2;
    Bgm_StopPlaybackAndResetController((int)object);
    ((void (*)(char *, int))ResourceHandle_StartKeyOperationAndRefreshState)(object, key);
    return 1;
}
