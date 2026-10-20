#include <globaldefs.h>
ARM
struct Record { signed char id; char reserved[63]; }; struct RecordList { Record *records; short count; };
// Original: arm9/main @ 0x02089FB0; symbol: func_02089fb0; size: 0x68.
extern "C" Record *CharacterTemplate_FindEntryById(RecordList *self,int id) { if(id<0) return 0; short i; Record *records=self->records; if(!records) return 0; short count=self->count; if(count==0) return 0; for(i=0;i<count;++i) { int current=records[i].id; if(current!=id) continue; return records+i; } return 0; }
