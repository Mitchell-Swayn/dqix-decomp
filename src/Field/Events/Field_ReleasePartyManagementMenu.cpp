#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(int);extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);extern "C" void _ZN13SafeAllocator7DestroyEv(void*);extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);extern "C" void FileCache_RestoreRomTablesIfSpaceAvailable();extern "C" char* GameResources_GetInstance();extern "C" int LinkedList_ContainsTag(void*,int);extern "C" char* Network_GetConnectionManager();extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/ov017 @ 0x021B67D8; symbol: ReleaseOwnedAllocatorAndMarkConnectionIfQueueAllows; size: 0xb4.
extern "C" void Field_ReleasePartyManagementMenu(char* self){
if(W(self,36)){W(self,36)=0;OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);}void* memory=_ZNK13SafeAllocator18GetSignedAllocatorEv(self+8);if(memory){_ZN13SafeAllocator7DestroyEv(self+8);Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,memory);}FileCache_RestoreRomTablesIfSpaceAvailable();int mark=1;char* resources=GameResources_GetInstance();void* queue=P(resources,0x36fc);char* record=P(resources,0x3734);if(LinkedList_ContainsTag(queue,24))mark=0;if(LinkedList_ContainsTag(queue,4)&&B(record,0xcc)==1)mark=0;if(!mark)return;B(Network_GetConnectionManager(),0x1011)=1;
}
