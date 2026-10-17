#include <globaldefs.h>
struct Entry{char pad[0xc2];unsigned short index;unsigned char flag;char tail[0x1b];};struct Object{char pad[0x98];void* owner;Entry* entries;char pad2[16];unsigned char flag;char pad3[3];unsigned char count;};extern "C" void TextCanvas_ResetLayoutAndDisplayFlags(void*);
// Original: arm9/main @ 0x0205D6E4; symbol: func_0205d6e4; size: 0xB0.
extern "C" ARM void RemoveEntriesFromEndAndUpdateFlags(Object* p,unsigned count){if(!p->owner || !p->entries || !p->count)return;for(unsigned char i=0;i<count;i++){Entry* e=p->entries+(p->count-1);e->index=0;e->flag=0;TextCanvas_ResetLayoutAndDisplayFlags(e);unsigned char left=--p->count;if(!left)return;p->entries[left-1].index=0;p->flag=p->entries[p->count-1].flag;}}
