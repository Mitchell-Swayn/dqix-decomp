#include <globaldefs.h>
struct Context {char pad[0x1c];unsigned short id;char pad1e[2];void* lookup;};
extern "C" void WriteResolvedLookupEntryXY(void*,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020E28F0; symbol: func_020e28f0; size: 0x20.
extern "C" void DispatchLookupCoordinatesThroughOwnerID(Context* p,unsigned x,unsigned y) {WriteResolvedLookupEntryXY(p->lookup,p->id,x,y);}
