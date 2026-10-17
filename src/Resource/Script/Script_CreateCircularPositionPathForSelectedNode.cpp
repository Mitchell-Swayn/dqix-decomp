#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"
struct PositionNode {Vector3fix position;int kind;PositionNode* next;};
struct Object {char pad[0x1f];unsigned char mode;char pad20[2];signed char count;char pad23[0x11];PositionNode* head;char pad38[0xc];unsigned short id;char pad46[0x2a];Object* next;};
struct State {char pad[10];unsigned short id;char padc[4];void* root;SafeAllocator* allocator;};
extern "C" State data_02108cec;
extern "C" Object* LinkedList_FindNodeByUnsignedKey(void*,int);
// Original: arm9/main @ 0x0206C82C; symbol: func_0206c82c; size: 0x10C.
extern "C" ARM int Script_CreateCircularPositionPathForSelectedNode(Script::Parameter* params,int count) {
 int key=(params++)->ToInt();
 Object* object=LinkedList_FindNodeByUnsignedKey(data_02108cec.root,key);if(!object)return 0;
 if((count-1)%3!=0)return 0;
 while(object) {if(object->id==data_02108cec.id)break;object=object->next;}
 if(!object)return 0;
 object->mode=9;int n=(count-1)/3;object->count=n-1;
 PositionNode* previous=0;
 for(int i=0;i<n;++i) {
  PositionNode* node=(PositionNode*)data_02108cec.allocator->Allocate(sizeof(PositionNode));if(!node)return 0;
  params=params->ToVec3fix(&node->position);node->kind=0;
  if(!previous)object->head=node;else previous->next=node;
  previous=node;
 }
 previous->next=object->head;previous->kind=1;return 1;
}
