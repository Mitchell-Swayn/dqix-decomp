#include <globaldefs.h>
#include <std_library_functions.h>
struct Entry {unsigned flags[4];unsigned short kind;unsigned short unused;unsigned short category;char pad16[8];unsigned char mask;char pad1f[33];};
struct Owner {char pad0[4];char* database;char pad8[0x90];int count;Entry entries[16];int filteredCount;Entry filtered[16];};
// Original: arm9/main @ 0x0209EAEC; symbol: func_0209eaec; size: 0xF8.
extern "C" void ScriptQueryContext_FilterByFourthFlagWordMask(Owner* p,int filter,unsigned key) {if(filter==0){p->count=0;int count=*(unsigned char*)(p->database+0x8e07);for(int i=0;i<count;i++){Entry* source=(Entry*)(p->database+0x5c60+i*0x40);if(source&&(source->flags[3]&key)!=0){memcpy(p->entries+p->count++,source,0x40);}}return;}memset(p->filtered,p->filteredCount=0,0x400);for(int i=0;i<p->count;i++){Entry* source=p->entries+i;if((source->flags[3]&key)!=0){int next=p->filteredCount;p->filteredCount=p->filteredCount+1;memcpy(p->filtered+next,source,0x40);}}p->count=p->filteredCount;memcpy(p->entries,p->filtered,0x400);}
