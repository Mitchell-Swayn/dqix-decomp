#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct R{unsigned int key:12;unsigned int rest:20;int value;};struct E{unsigned short type;short pad;R entries[6];char rest[24];};
// Original: arm9/main @ 0x0209B8D4; symbol: func_0209b8d4; size: 0x70.
R *Script_FindWeightedEntryByGroupAndId(E *p,unsigned int key,unsigned int type,int *index){for(int i=0;i<6;i++)if(p[i].type==type){*index=i;for(int j=0;j<6;j++)if(p[i].entries[j].key==key)return &p[i].entries[j];}return 0;}
}
