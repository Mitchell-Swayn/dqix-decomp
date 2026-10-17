#include <globaldefs.h>
extern "C" void* ReadWordAtOffset0();extern "C" int ReadScriptParameterAsInteger(void*);extern "C" void SetNestedSecondWordForTypeThree(void*,int);extern "C" int ReadLinkedByteArrayAtOffset8D5C(void*,int);
// Original: arm9/main @ 0x0209DA08; symbol: func_0209da08; size: 0x40.
extern "C" ARM int Script_WriteResolvedStateValueToParameter(char* p){void* state=ReadWordAtOffset0();if(!state)return 0;int id=ReadScriptParameterAsInteger(p);int value=ReadLinkedByteArrayAtOffset8D5C(state,id);SetNestedSecondWordForTypeThree(p+8,value);return 1;}
