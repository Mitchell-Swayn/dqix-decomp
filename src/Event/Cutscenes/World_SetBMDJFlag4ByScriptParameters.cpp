#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void *_ZN6Zone3D20FindLastBMDJInstanceEii(void *zone, int groupID, int instanceID);
extern "C" void _Z15UpdateBMDJFlag4PN17Zone3D_BMDJStruct13InstanceEntryEii(void *instance, int groupID, int clear);
// Original: arm9/ov001 @ 0x02163DEC; symbol: func_ov001_02163dec; size: 0x64.
extern "C" int World_SetBMDJFlag4ByScriptParameters(IntegerParameterView *parameter) {
    int groupID = Script_ReadParameterAsInteger(parameter);
    int instanceID = Script_ReadParameterAsInteger((IntegerParameterView *)((unsigned char *)parameter + 8));
    void *zone = Zone3D_GetMainInstance();
    if (zone == 0) {
        return 0;
    }
    void *instance = _ZN6Zone3D20FindLastBMDJInstanceEii(zone, groupID, instanceID);
    if (instance == 0) {
        return 0;
    }
    int clear = Script_ReadParameterAsInteger((IntegerParameterView *)((unsigned char *)parameter + 0x10));
    _Z15UpdateBMDJFlag4PN17Zone3D_BMDJStruct13InstanceEntryEii(instance, groupID, clear);
    return 1;
}
