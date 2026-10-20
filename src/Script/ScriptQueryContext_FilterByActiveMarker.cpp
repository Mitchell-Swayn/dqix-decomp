#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct Entry{unsigned char pad[31];unsigned char active;unsigned char tail[32];};struct State{int pad;unsigned char* source;unsigned char pad8[0x90];int count;Entry entries[16];int copied;Entry scratch[16];};
// Original: arm9/main @ 0x0209F774; symbol: func_0209f774; size: 0xF0.
extern "C" void ScriptQueryContext_FilterByActiveMarker(State* p,int compact){if(!compact){p->count=0;unsigned char count=p->source[0x8e07];for(int i=0;i<count;i++){Entry* entry=(Entry*)(p->source+0x5c60)+i;if(entry&&entry->active){int index=p->count++;memcpy(p->entries+index,entry,64);}}return;}p->copied=0;memset(p->scratch,0,1024);for(int i=0;i<p->count;i++){Entry* entry=p->entries+i;if(entry->active){int index=p->copied;p->copied++;memcpy(p->scratch+index,entry,64);}}p->count=p->copied;memcpy(p->entries,p->scratch,1024);}