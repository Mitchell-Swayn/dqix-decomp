#include <globaldefs.h>
extern "C" int ResourceManager_StartResolvedKeyEntry(void*);extern "C" void SetPresentObjectField110Flag4(void*);
// Original: arm9/main @ 0x020BEC30; symbol: func_020bec30; size: 0x28.
extern "C" int ProcessObjectAfterReadinessPredicate(void* self) {if(!ResourceManager_StartResolvedKeyEntry(self))return 0;SetPresentObjectField110Flag4(self);return 1;}
