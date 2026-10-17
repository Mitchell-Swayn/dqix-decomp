#include <globaldefs.h>
extern "C" int ReadWordAtOffset0(void); extern "C" void *ReadScriptParameterAsInteger(void *); extern "C" void FilterDatabaseRecordsByFlagByte1(int, void *, void *);
ARM
// Original: arm9/main @ 0x0209CEBC; symbol: func_0209cebc; size: 0x44.
extern "C" int Script_FilterDatabaseRecordsByFlagByte1WithConvertedParameters(void *p) {
    int state=ReadWordAtOffset0(); if (!state) return 0;
    void *first=ReadScriptParameterAsInteger(p); void *second=ReadScriptParameterAsInteger((char *)p+8);
    FilterDatabaseRecordsByFlagByte1(state,first,second); return 1;
}
