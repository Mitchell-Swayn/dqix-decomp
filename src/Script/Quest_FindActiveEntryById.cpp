#include <globaldefs.h>
ARM
struct Entry{unsigned id:9;unsigned flags:23;unsigned data[3];};struct List{unsigned char count;char pad[3];Entry entries[1];};
// Original: arm9/main @ 0x02096134; symbol: func_02096134; size: 0x58.
extern "C" Entry* Quest_FindActiveEntryById(List* p,int id){if(id>204||id<0)return 0;for(int i=0;i<p->count;i++){Entry* q=&p->entries[i];if(id==q->id)return q;}return 0;}
