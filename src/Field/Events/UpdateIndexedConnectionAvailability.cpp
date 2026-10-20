#include <globaldefs.h>
ARM
struct MapGameObject; struct GameResources; struct Node;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void *Network_GetConnectionManager();
extern "C" int Network_GetLocalMemberId(char*);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" int LinkedList_ContainsTag(Node**,int);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void FieldNetwork_QueueMemberHalfwordResponse(unsigned char,unsigned char,short);
// Original: arm9/ov017 @ 0x021B996C; symbol: func_ov017_021b996c; size: 0x12C.
// Queues connection availability using object identity, state IDs and resource tag 4.
extern "C" void UpdateIndexedConnectionAvailability(unsigned char *self,int objectIndex,int connection,unsigned char index,unsigned short id) {
 char *state=(char*)Network_GetConnectionManager();
 if(connection!=Network_GetLocalMemberId(state)&&connection!=4)return;
 unsigned char *game=(unsigned char*)_ZN9GameState11GetInstanceEv();
 void *object=_ZN9GameState20GetGameObjectByIndexEi(game,objectIndex);
 MapGameObject *other=_ZN9GameState20GetUnknownGameObjectEv(game);
 unsigned short field=_ZNK8Object3D10GetField06Ev(object);
 if(field!=_ZNK8Object3D10GetField06Ev(other)){FieldNetwork_QueueMemberHalfwordResponse(index,1,1);return;}
 if(*(int*)(self+0x12c)!=id && id!=*(int*)(game+0x5724)){
  if(LinkedList_ContainsTag(*(Node***)((unsigned char*)GameResources_GetInstance()+0x36fc),4)) {FieldNetwork_QueueMemberHalfwordResponse(index,1,0);return;}
  FieldNetwork_QueueMemberHalfwordResponse(index,1,1);return;
 }
 if(*(int*)(TextContext_GetSharedInstance()+0x998)){FieldNetwork_QueueMemberHalfwordResponse(index,1,0);return;}
 if(index<(unsigned char)Network_GetLocalMemberId(state)){FieldNetwork_QueueMemberHalfwordResponse(index,1,1);return;}
 FieldNetwork_QueueMemberHalfwordResponse(index,1,0);
}
