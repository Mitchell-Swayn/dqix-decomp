#include <globaldefs.h>
ARM
struct GameState; struct Object3D; struct MapGameObject; struct Object; struct GameResources;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameResources_GetInstance();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void* ReadGlobalAt02100044();
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" void MoveQueuedRecordAndApplySourceValue(Object*,const void*,short);
struct Payload { unsigned char flags; unsigned char member:4; unsigned char slot:4; unsigned short field,value; char pad[10]; };
struct Record { unsigned char kind; unsigned char pad[3]; Payload data; };
// Original: arm9/ov017 @ 0x021C41FC; symbol: func_ov017_021c41fc; size: 0x160.
extern "C" void GameState_QueuePartyMemberFields(int index,int slot) {
 void* game=_ZN9GameState11GetInstanceEv();
 GameResources_GetInstance();
 Object3D* obj=_ZN9GameState21GetPartyMemberByIndexEi((GameState*)game,index);
 if(obj) {
  Object* queue=(Object*)ReadGlobalAt02100044();
  Record record;
  Payload* p=&record.data;
  record.kind=0;
  p->member=(unsigned char)index;
  p->field=_ZNK8Object3D10GetField06Ev(obj);
  p->flags=0;
  if(slot<0) p->slot=0;
  else {p->slot=(unsigned char)slot; p->flags|=1;}
  int value=*(int*)((char*)obj+0x15c);
  if(value<0) p->value=0;
  else {p->value=value; p->flags|=2;}
  MapGameObject* map=_ZN9GameState20GetUnknownGameObjectEv(game);
  if(map && index==*(short*)((char*)map+4)) {
   if(p->field==10000) p->field=5900;
   else if(p->field==10100) p->field=6401;
   if(p->value) {
    if(p->value==10000) p->value=5900;
    else if(p->value==10100) p->value=6401;
   }
  }
  MoveQueuedRecordAndApplySourceValue(queue,&record,0);
 }
}
