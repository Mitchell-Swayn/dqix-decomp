#include <globaldefs.h>
ARM
extern "C" {void* ReadWordAtOffset0();int ReadScriptParameterAsInteger(void*);void Object_FilterSixtyFourByteRecordsByPredicateModeOne(void*,int,int);
// Original: arm9/main @ 0x0209D010; symbol: func_0209d010; size: 0x44.
int Script_FilterSixtyFourByteRecordsByPredicateModeOneWithConvertedParameters(unsigned char* p){void* q=ReadWordAtOffset0();if(!q)return 0;int x=ReadScriptParameterAsInteger(p);int y=ReadScriptParameterAsInteger(p+8);Object_FilterSixtyFourByteRecordsByPredicateModeOne(q,x,y);return 1;}}
