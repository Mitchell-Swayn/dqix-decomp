#include <globaldefs.h>
ARM
struct BitZero {unsigned char value:1;unsigned char rest:7;};
extern "C" char* _ZN9GameState11GetInstanceEv(...);
extern "C" char* Zone3D_GetMainInstance(...);
extern "C" char* GameResources_GetInstance(...);
extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(...);
extern "C" char* GameObject_ResolveLinkedStatsOrNull(...);
extern "C" char* Network_GetConnectionManager(...);
extern "C" int Network_IsSessionActive(...);
extern "C" int Network_IsParentOrOffline(...);
extern "C" void Tavern_ResetOtherPartyMembersFollowTrails(...);
extern "C" void FieldEvent_InitializeLuidaScriptRequest(...);
extern "C" void LinkedQueue_AppendAndMarkActive(...);
extern "C" void Field_LatchSessionTransition(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov003 @ 0x02163D7C; symbol: Resource_LinkIndexedObjectStateAndNotifyConnection; size: 0xd0.
// Initializes a shared resource node from indexed object state, links it, and notifies active connection.
extern "C" void Resource_LinkIndexedObjectStateAndNotifyConnection(char* self){Tavern_ResetOtherPartyMembersFollowTrails(self);char* game=_ZN9GameState11GetInstanceEv();char* world=Zone3D_GetMainInstance();char* resources=GameResources_GetInstance();char* list=P(resources,0x36fc);char* node=P(resources,0x3734);char* state=GameObject_ResolveLinkedStatsOrNull(_ZN9GameState20GetGameObjectByIndexEi(game,*(signed char*)(self+0x4a2)));char* connection=Network_GetConnectionManager();FieldEvent_InitializeLuidaScriptRequest(node,P(world,8),1);B(node,0xcd)=*(signed char*)(self+0x4a2);B(node,0xce)=((BitZero*)(state+0x14))->value;B(node,0xcf)=0;LinkedQueue_AppendAndMarkActive(list,node,0);B(self,0x4a3)=16;U(self,0x464)&=~0x8000;if(Network_IsSessionActive(connection)&&Network_IsParentOrOffline(connection))Field_LatchSessionTransition(resources);}
