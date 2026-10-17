#pragma optimization_level 4
#include <globaldefs.h>
extern "C" unsigned* Object_ReadInitialOptionalResourceWord(void*);
// Original: arm9/main @ 0x02055168; symbol: func_02055168; size: 0x18.
extern "C" unsigned Object_ReadOptionalResolvedValue(void* object) { unsigned* p=Object_ReadInitialOptionalResourceWord(object); if (p==0) return 0; else return *p; }
