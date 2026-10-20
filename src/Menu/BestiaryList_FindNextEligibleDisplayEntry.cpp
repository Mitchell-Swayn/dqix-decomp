#include <globaldefs.h>
#pragma optimize_for_size off
struct Entry{char pad[19];unsigned char a:1,b:1,c:1,unused:5;char pad14[6];short value;char pad1c[4];};struct List{unsigned reserved,count:12,flags:20;Entry* entries;};
// Original: arm9/main @ 0x02097668; symbol: func_02097668; size: 0x78.
extern "C" ARM Entry* BestiaryList_FindNextEligibleDisplayEntry(List*p,int minimum){unsigned short count=p->count;Entry* base=p->entries;Entry* result=0;int best=32767;for(unsigned short i=0;i<count;i++){Entry*e=base+i;if(!e->c&&e->a){int v=e->value;if(v>minimum && best>v){best=v;result=e;}}}return result;}
