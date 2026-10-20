#include <globaldefs.h>
ARM

extern "C" void *GameResources_GetInstance();
extern "C" int Script_ReadParameterString(void *);
extern "C" int sprintf(char *buffer, const char *format, ...);
extern "C" const char Script_LoadEventTextTable_PathDataS[];

// Original: arm9/ov001 @ 0x021613D0; symbol: func_ov001_021613d0; size: 0x38.
extern "C" int Event_ScriptSetSceneResourcePath(void *object) {
    char *base = *(char **)((char *)GameResources_GetInstance() + 0x3734);
    char *buffer = base + 0xd8;
    unsigned int value = Script_ReadParameterString(object);
    sprintf(buffer, Script_LoadEventTextTable_PathDataS, value);
    return 1;
}
