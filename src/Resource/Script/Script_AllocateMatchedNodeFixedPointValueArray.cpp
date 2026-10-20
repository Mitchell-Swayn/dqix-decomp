#include <globaldefs.h>
ARM
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x2108cec; symbol: data_02108cec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Node{unsigned char pad[0x44];unsigned short id;unsigned char pad46[0x16];int* values;unsigned char pad60[16];Node* next;};struct State{unsigned char pad[10];unsigned short id;int padc;void* object;SafeAllocator* alloc;};extern "C" {extern State ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage;Node* LinkedList_FindNodeByUnsignedKey(void*,int);
// Original: arm9/main @ 0x0206D8E8; symbol: func_0206d8e8; size: 0xF0.
int Script_AllocateMatchedNodeFixedPointValueArray(Script::Parameter* p){int id=p->ToInt();Node* node=LinkedList_FindNodeByUnsignedKey(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.object,id);if(!node)return 0;while(node){if(node->id==ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.id)break;node=node->next;}if(!node)return 0;node->values=(int*)ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.alloc->Allocate(16);if(node->values){node->values[3]=(int)(4096.0f*(p+1)->ToFloat());node->values[0]=(int)(4096.0f*(p+2)->ToFloat());node->values[1]=0;node->values[2]=(int)(4096.0f*(p+3)->ToFloat());}return 1;}}
