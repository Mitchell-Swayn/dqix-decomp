#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct GameResources;struct IntegerParameterView;
struct Node { unsigned char type;char text[0x22];char pad;int id;Node* next;unsigned char flag; };
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned int EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;
extern "C" char Script_LoadEventTextTable_PathDataS[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned int,unsigned int);
extern "C" GameResources* GameResources_GetInstance();
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" unsigned int Script_ReadParameterString(void*);
// Original: arm9/ov001 @ 0x021612C8; symbol: func_ov001_021612c8; size: 0xAC.
extern "C" int Script_AppendFormattedResourceNode(unsigned char* parameters) {
Node* node;
unsigned char* status=*(unsigned char**)((unsigned char*)GameResources_GetInstance()+0x3734);
node=(Node*)_ZN13SafeAllocator8AllocateEj(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage,0x30);
node->type=0;memset(node->text,0,0x22);node->id=-1;node->next=0;node->flag=0;
sprintf(node->text,Script_LoadEventTextTable_PathDataS,Script_ReadParameterString(parameters));
node->type=Script_ReadParameterAsInteger((IntegerParameterView*)(parameters+8));
Node* tail=*(Node**)(status+0xd4);
if(!tail)*(Node**)(status+0xd4)=node;
else {while(tail->next)tail=tail->next;tail->next=node;}
return 1;
}
