#include <globaldefs.h>
extern "C" void* ReadWordAtOffset0();extern "C" int ReadScriptParameterAsInteger(void*);extern "C" void SetNestedSecondWordForTypeThree(void*,int);extern "C" int ReadOriginalOrFilteredRecordCount(void*,int);
// Original: arm9/main @ 0x0209D38C; symbol: func_0209d38c; size: 0x40.
extern "C" ARM int Script_ReadSourceOrFilteredRecordCount(char* p){void* state=ReadWordAtOffset0();if(!state)return 0;int id=ReadScriptParameterAsInteger(p);int value=ReadOriginalOrFilteredRecordCount(state,id);SetNestedSecondWordForTypeThree(p+8,value);return 1;}
