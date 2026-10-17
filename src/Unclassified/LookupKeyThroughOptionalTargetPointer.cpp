#include <globaldefs.h>
extern "C" void* FindValueInLinkedHalfwordLists(void*,unsigned);
struct Object{char pad[0x13c];void** target;};
// Original: arm9/main @ 0x02048AB4; symbol: func_02048ab4; size: 0x2C.
extern "C" ARM void* LookupKeyThroughOptionalTargetPointer(Object* p,unsigned key){if(!p->target)return 0;void* target=*p->target;if(!target)return 0;return FindValueInLinkedHalfwordLists(target,key);}
