#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void *parameter);
extern "C" char *Event_GetObjectSession(int index);
extern "C" void CutsceneActor_InitializeCommandSession(char *record);
// Original: arm9/ov001 @ 0x0215BF34; symbol: func_ov001_0215bf34; size: 0x24.
extern "C" int Script_ResetObjectSession(void *parameter) {
    char *record = Event_GetObjectSession(Script_ReadParameterAsInteger(parameter));
    if (record == 0) return 0;
    CutsceneActor_InitializeCommandSession(record);
    return 1;
}
