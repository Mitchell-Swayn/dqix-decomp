#include <globaldefs.h>
struct Entry{unsigned char a,b,pad[6];}; struct Object{unsigned char pad[8];Entry* entries;unsigned char rest[120];unsigned char enabled:1;};
// Original: arm9/main @ 0x02047A3C; symbol: func_02047a3c; size: 0x20.
extern "C" ARM unsigned ReadEnabledIndexedEntryValue(Object* p,int i){return p->enabled?p->entries[i].b:0;}
