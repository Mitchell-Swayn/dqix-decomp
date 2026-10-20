#include <globaldefs.h>
ARM
#include <Resource/GameResources.h>
struct IntegerParameterView;
extern "C" ARM int Script_ReadParameterAsInteger(IntegerParameterView* parameter);

// Original: arm9/ov001 @ 0x02160904; symbol: func_ov001_02160904; size: 0x34.
// Sets resource object's flag bit zero when the script parameter is zero.
extern "C" int Event_ScriptSetUnknownResourceFlagAt5A4FromZero(IntegerParameterView* parameter)
{
    int value = Script_ReadParameterAsInteger(parameter);
    unsigned char* object = (unsigned char*)GameResources_GetInstance()->unknown_ptr_36d0;
    if (value != 0)
        *(unsigned int*)(object + 0x5a4) &= ~1u;
    else
        *(unsigned int*)(object + 0x5a4) |= 1u;
    return 1;
}
