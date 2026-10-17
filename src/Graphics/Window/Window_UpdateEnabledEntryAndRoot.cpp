#include <globaldefs.h>
struct Mode {char pad[0x3f];unsigned char enabled:1;unsigned char rest:7;};struct Obj {char pad[12];Mode* mode;void* root;int unknown;short x,y;unsigned short id,padding;void* entry;};extern "C" void WriteResolvedLookupEntryXY(void*,unsigned short,short,short),Object_UpdateAllCountedResourceEntries(void*),func_020e1780(void*);
// Original: arm9/main @ 0x020E2794; symbol: func_020e2794; size: 0x58.
extern "C" ARM void Window_UpdateEnabledEntryAndRoot(Obj* p,void* q){if(!p->mode->enabled)return;if(p->entry){WriteResolvedLookupEntryXY(p->entry,p->id,p->x,p->y);if(q)Object_UpdateAllCountedResourceEntries(q);}func_020e1780(p->root);}
