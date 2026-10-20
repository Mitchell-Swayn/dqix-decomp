#include <globaldefs.h>
struct Active{char pad[0x17b8];unsigned char value;};struct Flags{unsigned char a:1,b:1,c:1,rest:5;};struct Entry{char pad[0x16];Flags flags;char pad1;unsigned id;};
// Original: arm9/main @ 0x02045C00; symbol: func_02045c00; size: 0xAC.
extern "C" ARM int TextEntry_FindCachedGlyphForCurrentStyle(unsigned char* base,unsigned id){if(!id)return -1;for(int i=0;i<128;++i){if(((Active*)(base+i))->value){Entry* p=(Entry*)(base+0x9b8+i*28);if(id==p->id){unsigned char flags=base[0x195b];if(flags&128){if(p->flags.c)return i;}else if(flags&2){if(p->flags.b)return i;}else return i;}}}return -1;}
