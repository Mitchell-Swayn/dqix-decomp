#include <globaldefs.h>
ARM
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x2108cec; symbol: data_02108cec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State{unsigned char pad[10];unsigned short serial,id;unsigned short padE;void* object;SafeAllocator* alloc;};extern "C" {extern State ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage;void Script_InitializeActorMotionDescriptor(void*);void LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(void*,int);void Script_InsertActorMotionDescriptorByPriority(void*,void*);
// Original: arm9/main @ 0x0206C010; symbol: func_0206c010; size: 0xE8.
int Script_InsertOrRemoveVectorNodeBySerial(Script::Parameter* p,int count){ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.serial++;unsigned int id=p->ToInt();if(id!=ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.id)return 1;unsigned char* node=(unsigned char*)ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.alloc->Allocate(0x78);if(!node)return 0;Script_InitializeActorMotionDescriptor(node);*(short*)(node+2)=id;node[0]=(p+1)->ToInt();if(count<3){LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.object,node[0]);return 1;}Script::Parameter* next=(p+2)->ToVec3fix((Vector3fix*)(node+16));*(short*)(node+0x1c)=(int)(4096.0f*next->ToFloat());if(count>6)node[0x1e]=(next+1)->ToInt();*(unsigned short*)(node+0x44)=ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.serial;Script_InsertActorMotionDescriptorByPriority(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.object,node);return 1;}}
