#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);extern "C" int Combat_CollectPresentEnemyIndices(void*,short*,int,int);extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);extern "C" void Object3D_ConfigureLinkedAlphaTween(char*,int,int);
// Original: arm9/ov000 @ 0x02163A7C; symbol: SetCollectedCombatantsAlpha31Immediately; size: 0x98.
// Collects two ID groups into sixteen halfwords and sets linked combatant alpha31 immediately.
extern "C" void SetCollectedCombatantsAlpha31Immediately(char* self){void* gs=_ZN9GameState11GetInstanceEv();short ids[16];int count=0;count+=Combat_CollectEligiblePartyIds(*(void**)(self+0x29c),ids,16,count);count+=Combat_CollectPresentEnemyIndices(*(void**)(self+0x29c),ids+count,16-count,0);short* cursor=ids;for(int i=0;i<count;i++){char* object=_ZN9GameState19GetCombatantByIndexEi(gs,*cursor);if(object)Object3D_ConfigureLinkedAlphaTween(object,31,0);cursor++;}}
