#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
extern "C" {
struct E{char name[56];int state;};struct T{unsigned int count;int pad;E *data;};
// Original: arm9/main @ 0x02040404; symbol: func_02040404; size: 0x64.
unsigned int FindActiveRecordIndexByName(T *p,const char *s){unsigned int i;E *data=p->data;if(!data)return -1;for(i=0;i<p->count;i++)if(data[i].state>=0&&strcmp(data[i].name,s)==0)return i;return -1;}
}
