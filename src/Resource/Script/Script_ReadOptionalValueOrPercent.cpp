#include <globaldefs.h>
ARM
extern "C" {void* ReadWordAtOffset0();int ReadScriptParameterAsInteger(void*);int Object_ReadOptionalObjectValueOrPercent(void*,int);void SetNestedSecondWordForTypeThree(void*,int);
// Original: arm9/main @ 0x0209D44C; symbol: func_0209d44c; size: 0x40.
int Script_ReadOptionalValueOrPercent(unsigned char* p){void* q=ReadWordAtOffset0();if(!q)return 0;int x=ReadScriptParameterAsInteger(p);x=Object_ReadOptionalObjectValueOrPercent(q,x);SetNestedSecondWordForTypeThree(p+8,x);return 1;}}
