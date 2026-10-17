#include <globaldefs.h>
struct LookupEntry {unsigned first;unsigned short x,y,id;char pad[11];unsigned char flags;char tail[2];};
struct Lookup {LookupEntry* entries;unsigned short count;};
extern "C" LookupEntry* FindRecordPointerByKey(Lookup*,unsigned);
// Original: arm9/main @ 0x020E27EC; symbol: func_020e27ec; size: 0x20.
extern "C" void WriteResolvedLookupEntryXY(Lookup* lookup,unsigned id,unsigned x,unsigned y) {LookupEntry* p=FindRecordPointerByKey(lookup,id);if(p){p->x=x;p->y=y;}}
