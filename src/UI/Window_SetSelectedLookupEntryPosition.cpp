#include <globaldefs.h>
struct Context {char pad[0x1c];unsigned short id;char pad1e[2];void* lookup;};
extern "C" void Window_SetLookupEntryPosition(void*,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020E28F0; symbol: func_020e28f0; size: 0x20.
extern "C" void Window_SetSelectedLookupEntryPosition(Context* p,unsigned x,unsigned y) {Window_SetLookupEntryPosition(p->lookup,p->id,x,y);}
