#include <globaldefs.h>
struct Entry { unsigned short id:11;unsigned short reserved:5; char pad[10]; }; struct Table { Entry *entries; int count; };
// Original: arm9/main @ 0x0209A594; symbol: func_0209a594; size: 0x80.
extern "C" ARM Entry *SkillTable_FindEntryById(Table *t,unsigned id) { int i;Entry *p=t->entries; if(!p)return 0; if((int)id>=287)return 0; if(id==p[id].id)return p+id; for(i=0;i<t->count;i++){if(id==p[i].id)return p+i;} return 0; }
