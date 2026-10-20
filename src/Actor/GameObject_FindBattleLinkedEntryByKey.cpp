#include <globaldefs.h>
extern "C" void* CombatScript_FindCommandGroupByActionKey(void*,unsigned);
struct Object{char pad[0x13c];void** target;};
// Original: arm9/main @ 0x02048AB4; symbol: func_02048ab4; size: 0x2C.
extern "C" ARM void* GameObject_FindBattleLinkedEntryByKey(Object* p,unsigned key){if(!p->target)return 0;void* target=*p->target;if(!target)return 0;return CombatScript_FindCommandGroupByActionKey(target,key);}
