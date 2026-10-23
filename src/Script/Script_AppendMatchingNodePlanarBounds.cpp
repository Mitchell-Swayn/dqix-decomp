#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
ARM
struct E;
extern "C" E* LinkedList_FindNodeByUnsignedKey(E**,unsigned);
extern "C" unsigned char ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage[];
struct Bounds { int kind; int values[4]; Bounds* next; };
struct MatchingNode { unsigned char unknown[0x40]; Bounds* bounds; unsigned short serial; unsigned char pad[0x2a]; MatchingNode* next; };
// Original: arm9/main @ 0x0206C4E8; symbol: func_0206c4e8; size: 0x12C.
// Appends four fixed-point planar bounds and a type to the selected serial node.
extern "C" int Script_AppendMatchingNodePlanarBounds(Script::Parameter* params,int) {
 unsigned key=params[0].ToInt();
 MatchingNode* node=(MatchingNode*)LinkedList_FindNodeByUnsignedKey(*(E***)(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage+16),key);
 if(!node)return 0;
 while(node){ if(node->serial==*(unsigned short*)(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage+10))break;node=node->next; }
 if(!node)return 0;
 Bounds* entry=(Bounds*)(*(SafeAllocator**)(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage+20))->Allocate(24);
 entry->values[0]=(int)(4096.0f*params[1].ToFloat());
 entry->values[1]=(int)(4096.0f*params[2].ToFloat());
 entry->values[2]=(int)(4096.0f*params[3].ToFloat());
 entry->values[3]=(int)(4096.0f*params[4].ToFloat());
 entry->kind=params[5].ToInt();entry->next=0;
 Bounds* tail=node->bounds;
 if(!tail){node->bounds=entry;return 1;}
 while(tail->next)tail=tail->next;
 tail->next=entry;return 1;
}
