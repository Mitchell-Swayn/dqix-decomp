#include <globaldefs.h>
ARM
struct Ids{short value[8];};extern "C" Ids TestCollectedObjectResourceIdentifier_CombatantSelectionInitialIds;extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(void*,short*,int,int);extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" char* GameState_FindIndexedObjectWithFlag400(void*,int);
// Original: arm9/ov000 @ 0x0215FC8C; symbol: TestCollectedObjectResourceIdentifier; size: 0x98.
// Tests whether any collected indexed object has a matching resource halfword10.
extern "C" int TestCollectedObjectResourceIdentifier(void* self,unsigned identifier){Ids ids=TestCollectedObjectResourceIdentifier_CombatantSelectionInitialIds;short count=Combat_CollectGroupIndicesByDescriptorFlags(self,ids.value,8,0);for(int i=0;i<count;i++){int id=ids.value[i];void* gs=_ZN9GameState11GetInstanceEv();char* object=GameState_FindIndexedObjectWithFlag400(gs,id);if(object){char* resource=*(char**)(object+0x144);if(resource && *(unsigned short*)(resource+0x10)==identifier)return 1;}}return 0;}
