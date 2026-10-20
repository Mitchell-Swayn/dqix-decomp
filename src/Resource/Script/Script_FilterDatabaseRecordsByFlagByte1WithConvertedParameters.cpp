#include <globaldefs.h>
extern "C" int ScriptQueryContext_GetActiveInstance(void); extern "C" void *Script_ReadParameterAsInteger(void *); extern "C" void ScriptQueryContext_FilterBySecondFlagWordMask(int, void *, void *);
ARM
// Original: arm9/main @ 0x0209CEBC; symbol: func_0209cebc; size: 0x44.
extern "C" int Script_FilterDatabaseRecordsByFlagByte1WithConvertedParameters(void *p) {
    int state=ScriptQueryContext_GetActiveInstance(); if (!state) return 0;
    void *first=Script_ReadParameterAsInteger(p); void *second=Script_ReadParameterAsInteger((char *)p+8);
    ScriptQueryContext_FilterBySecondFlagWordMask(state,first,second); return 1;
}
