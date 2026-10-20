#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" unsigned LinkedQueue_AppendAndMarkActive(...);
extern "C" unsigned Network_IsSessionActive(...);
extern "C" unsigned Network_GetConnectionManager(...);
extern "C" unsigned Network_IsParentOrOffline(...);
extern "C" unsigned Network_IsMemberConnected(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState20GetGameObjectByIndexEi(...);
extern "C" unsigned InitializeType23LinkedNode(...);
// Original: arm9/ov017 @ 0x021b65e0; symbol: GameState_QueueWorldNodeWhenResolvedObjectsPresent; size: 0xd8.
extern "C" void Field_QueuePartyManagementWhenMembersResolved(unsigned self,int value){
unsigned game=_ZN9GameState11GetInstanceEv(),connection=Network_GetConnectionManager();int valid=1;if(!value&&Network_IsSessionActive(connection)&&Network_IsParentOrOffline(connection)){for(int i=0;i<4;++i){if(Network_IsMemberConnected(connection,i)){if(!_ZN9GameState20GetGameObjectByIndexEi(game,i))valid=0;}}}if(!valid)return;
InitializeType23LinkedNode(U32(self+0x3b00));U8(U32(self+0x3b00)+0x1c)=value;LinkedQueue_AppendAndMarkActive(U32(self+0x36fc),U32(self+0x3b00));connection=Network_GetConnectionManager();if(Network_IsParentOrOffline(connection))if(!value)U8(connection+0x1011)=0;
}