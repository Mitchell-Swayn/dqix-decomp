#include <globaldefs.h>
#include "Util/Random.h"
extern "C" int ReadScriptParameterAsInteger(void*);extern "C" void SetNestedSecondWordForTypeThree(void*,int);
// Original: arm9/main @ 0x0209D3CC; symbol: func_0209d3cc; size: 0x3C.
extern "C" ARM int Script_WriteRandomValueWithinInclusiveLimit(char* p){Random* random=GetBTRandom();int limit=ReadScriptParameterAsInteger(p);int value=NextRandomMax(random,limit+1);SetNestedSecondWordForTypeThree(p+8,value);return 1;}
