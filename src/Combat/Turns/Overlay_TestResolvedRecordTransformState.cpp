#include <globaldefs.h>
ARM
extern "C" char* BattleScene_ResolveCurrentActionRecord(char*);
extern "C" int Combat_IsDefaultOrSpecialPresentationAction(int);
extern "C" void* ActionData_GetGlobalTables();
extern "C" void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
// Original: arm9/ov000 @ 0x021627FC; symbol: func_ov000_021627fc; size: 0x68.
extern "C" int Overlay_TestResolvedRecordTransformState(char *p) {
    char *record = BattleScene_ResolveCurrentActionRecord(p);
    if (!record) return 0;
    unsigned short id = *(unsigned short *)record;
    int selector = id;
    if (Combat_IsDefaultOrSpecialPresentationAction(selector)) selector = 1;
    char *result = (char *)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char *)ActionData_GetGlobalTables(), (short)selector);
    if (!result) return 0;
    unsigned state = *(unsigned *)(result + 0x14) >> 28;
    if (state == 5) return 1;
    if (state == 2) return 1;
    return 0;
}
