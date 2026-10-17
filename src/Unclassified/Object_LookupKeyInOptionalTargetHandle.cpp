#include <globaldefs.h>
extern "C" unsigned func_ov000_02169aa4(void*,unsigned,void**,unsigned);
struct Object{char pad[0x13c];void** target;};
// Original: arm9/main @ 0x02048AE0; symbol: func_02048ae0; size: 0x2C.
extern "C" ARM unsigned Object_LookupKeyInOptionalTargetHandle(Object* p,unsigned key,void** out,unsigned capacity){if(!p->target)return 0;void* target=*p->target;if(!target)return 0;return func_ov000_02169aa4(target,key,out,capacity);}
