#include <globaldefs.h>
extern "C" unsigned CombatScript_CollectCommandGroupsByActionKey(void*,unsigned,void**,unsigned);
struct Object{char pad[0x13c];void** target;};
// Original: arm9/main @ 0x02048AE0; symbol: func_02048ae0; size: 0x2C.
extern "C" ARM unsigned GameObject_CollectBattleLinkedRecordsByKey(Object* p,unsigned key,void** out,unsigned capacity){if(!p->target)return 0;void* target=*p->target;if(!target)return 0;return CombatScript_CollectCommandGroupsByActionKey(target,key,out,capacity);}
