#include <globaldefs.h>
ARM
extern "C" {void* ScriptQueryContext_GetActiveInstance();int Script_ReadParameterAsInteger(void*);void ScriptQueryContext_FilterByAlternateAttributeConditions(void*,int,int);
// Original: arm9/main @ 0x0209D010; symbol: func_0209d010; size: 0x44.
int Script_FilterSixtyFourByteRecordsByPredicateModeOneWithConvertedParameters(unsigned char* p){void* q=ScriptQueryContext_GetActiveInstance();if(!q)return 0;int x=Script_ReadParameterAsInteger(p);int y=Script_ReadParameterAsInteger(p+8);ScriptQueryContext_FilterByAlternateAttributeConditions(q,x,y);return 1;}}
