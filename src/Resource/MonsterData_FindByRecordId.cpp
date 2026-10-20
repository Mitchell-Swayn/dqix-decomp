#include <globaldefs.h>
ARM
#pragma optimization_level 4
typedef int (*KeyGetter)(void*);extern "C" int MonsterData_GetRecordId(void*);extern "C" void* MonsterData_FindEntryByExtractedKey(void*,int,KeyGetter);
// Original: arm9/main @ 0x0206F4F0; symbol: func_0206f4f0; size: 0x14.
extern "C" void* MonsterData_FindByRecordId(void* p,int key){return MonsterData_FindEntryByExtractedKey(p,key,MonsterData_GetRecordId);}
