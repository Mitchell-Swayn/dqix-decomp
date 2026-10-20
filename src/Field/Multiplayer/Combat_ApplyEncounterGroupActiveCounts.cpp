#include <globaldefs.h>
ARM
extern "C" int FieldBattle_GetEncounterRequest(...);
extern "C" int FieldBattle_GetScene(...);
extern "C" int FieldBattle_GetCombatContext(...);
extern "C" void* memset(void*,int,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021C8E70; symbol: ReplaceGroupedActiveCountsFromMatchingPacket; size: 0xc8.
extern "C" void Combat_ApplyEncounterGroupActiveCounts(int unused,char* packet,int unused2,char* resources){
void* owner=P(resources,0x3718);char* descriptor=C(FieldBattle_GetEncounterRequest(owner));if(!descriptor)return;if(!FieldBattle_GetScene(owner))return;char* object=C(FieldBattle_GetCombatContext(owner));if(!object)return;if(H(descriptor,8)!=H(packet,4))return;char* masks=packet+4;int total=0;int i=0;char* groups=object+0x81b0;struct Counts{unsigned char low:4;unsigned char active:4;};for(;i<B(masks,11);i++){char* group=groups+4+i*24;((Counts*)(group+10))->active=B(masks+i,8);total+=((Counts*)(group+10))->active;}B(groups,1)=(B(groups,1)&~15)|((unsigned char)total&15);
}
