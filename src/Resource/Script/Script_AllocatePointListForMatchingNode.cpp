#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x2108cec; symbol: data_02108cec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Point{Vector3fix value;int end;Point* next;};struct Node{char pad[31];unsigned char mode;char pad2[20];Point* head;char pad3[12];unsigned short id;char pad4[42];Node* next;};struct State{char pad[10];unsigned short id;char pad2[4];void* list;SafeAllocator* allocator;};extern "C" State ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage;extern "C" Node* LinkedList_FindNodeByUnsignedKey(void*,int);
// Original: arm9/main @ 0x0206C938; symbol: func_0206c938; size: 0x104.
extern "C" ARM int Script_AllocatePointListForMatchingNode(Script::Parameter* params,int count){int key=(params++)->ToInt();Node* n=LinkedList_FindNodeByUnsignedKey(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.list,key);if(!n)return 0;if((count-1)%3)return 0;while(n){if(n->id==ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.id)break;n=n->next;}if(!n)return 0;n->mode=10;int points=(count-1)/3;Point* previous=0;for(int i=0;i<points;i++){Point* point=(Point*)ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.allocator->Allocate(sizeof(Point));if(!point)return 0;params=params->ToVec3fix(&point->value);point->end=0;if(!previous)n->head=point;else previous->next=point;previous=point;}previous->next=n->head;previous->end=1;return 1;}
