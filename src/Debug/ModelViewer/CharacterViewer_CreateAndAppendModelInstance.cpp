#include <globaldefs.h>
ARM
extern "C" int AllocatorUnion_AllocateFourByteAligned(...);
extern "C" int CharacterViewer_LoadModelByKind(...);
extern "C" int CharacterViewer_InitializeModelForMenuCategory(...);
extern "C" int CharacterViewer_DestroyModelInstanceResources(...);
extern "C" int Memory_FreeThroughAllocatorUnion(...);
extern "C" int CharacterViewer_InitializeModelInstance(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov015 @ 0x021919E4; symbol: AllocateInitializeAndAppendModeSelectedRecord.
extern "C" char* CharacterViewer_CreateAndAppendModelInstance(char*self,char*descriptor){
char*node=C(AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,8));if(!node)return 0;W(node,0)=0;W(node,4)=0;P(node,0)=C(AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,92));char*record=P(node,0);if(!record){Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,node);return 0;}CharacterViewer_InitializeModelInstance(record);if(!CharacterViewer_InitializeModelForMenuCategory(record,self,descriptor)){Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,P(node,0));P(node,0)=0;Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,node);return 0;}if(!CharacterViewer_LoadModelByKind(record,descriptor)){CharacterViewer_DestroyModelInstanceResources(P(node,0));Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,P(node,0));P(node,0)=0;Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,node);return 0;}char**link=(char**)(self+44);while(*link)link=(char**)(*link+4);*link=node;return P(node,0);
}
