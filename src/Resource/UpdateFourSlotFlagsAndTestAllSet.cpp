#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Network_GetConnectionManager();extern "C" int Network_IsMemberActive(void*,int);extern "C" void* GameState_FindIndexedObjectWithFlag1000(void*,int);extern "C" void FieldMonster_RecordPartyHideResponse(void*,int,int);
// Original: arm9/main @ 0x0207973C; symbol: func_0207973c; size: 0x80.
extern "C" int UpdateFourSlotFlagsAndTestAllSet(unsigned char* p){void* state=_ZN9GameState11GetInstanceEv();void* list=Network_GetConnectionManager();for(int i=0;i<4;i++)if(!Network_IsMemberActive(list,i)||GameState_FindIndexedObjectWithFlag1000(state,i))FieldMonster_RecordPartyHideResponse(p,i,1);return (p[382]&15)==15;}
