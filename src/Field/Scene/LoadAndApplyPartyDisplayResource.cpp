#include <globaldefs.h>
ARM
#include <Resource/GameResources.h>
#include <Graphics/Vector.h>
struct GameState;struct Object3D;struct Object;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* Object_GetGlobalSixteenEntryDisplayState();
extern "C" unsigned Memory_ReadMaximumAlignedAllocation(char*);
extern "C" int Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned);
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void TextureVRAM_CloneSavedAllocationBounds(const Object*,Object*);
extern "C" char LoadAndApplyPartyDisplayResource_PathDataEffectEm1830Chr[];
extern "C" void* _Z25LoadFileIntoNewAllocationPKcR13SafeAllocatorPj(const char*,SafeAllocator*,unsigned*);
extern "C" int AllocateInitializeAndAppendLinkedNode(int*,unsigned,SafeAllocator*,unsigned,unsigned,unsigned);
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
extern "C" int _ZNK8Object3D17GetInheritedAlphaEv(void*);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" void* _ZN8Vector3iaSERKS_(void*,const void*);
extern "C" void _ZNK8Object3D8GetScaleEv(Vector3i*,const Object3D*);
extern "C" int ObjectPool_SpawnFromTemplateKey(void*,int,void*);
extern "C" void Network_QueuePartyDisplayRequestForCurrentZone(unsigned char);
struct Flags {unsigned char a:1,b:1,c:1,d:1,e:1,f:1,g:1,h:1;};
struct Entry{unsigned char first,pad[15],active;Flags flags;short zero;short invalid[4];short negativeScale;unsigned short pad1e;int word;int beforeVector[2];int vector[3];int extras[3];Vector3i scale;};
static inline char* ResourceBlock(GameResources *r){return r->unknown_2cc;}
// Original: arm9/ov017 @ 0x021C2B6C; symbol: func_ov017_021c2b6c; size: 0x2E4.
// Loads shared display resource then applies default records to eligible party objects.
extern "C" void LoadAndApplyPartyDisplayResource(unsigned char *p){
 GameState *game=(GameState*)_ZN9GameState11GetInstanceEv();GameResources *r=GameResources_GetInstance();void *display=Object_GetGlobalSixteenEntryDisplayState();
 if(!p[0x8d]){
 if(Memory_ReadMaximumAlignedAllocation((char*)&Main_UnknownRoleZeroInitializedStorage_Variant3)<0x8000){Filesystem_FreeCachedTableIfAllocationNeedsSpace(0x8000);p[0x96]=1;}
 void *memory=AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3,0x8000);_ZN13SafeAllocator11CreateTypeAEPvj(p+8,memory,0x8000);_ZN13SafeAllocator5ResetEv(p+8);
 TextureVRAM_CloneSavedAllocationBounds((Object*)(ResourceBlock(r)+0xc40),(Object*)(p+0x1c));unsigned size=0;
 void *file=_Z25LoadFileIntoNewAllocationPKcR13SafeAllocatorPj(LoadAndApplyPartyDisplayResource_PathDataEffectEm1830Chr,(SafeAllocator*)(p+8),&size);
 if(!file){p[0x8c]=3;return;}
 AllocateInitializeAndAppendLinkedNode((int*)display,0x11,(SafeAllocator*)(p+8),(unsigned)file,size,(unsigned)(p+0x1c));p[0x8d]++;
 }else if(p[0x8d]==1){
 Object3D *selected=_ZN9GameState21GetPartyMemberByIndexEi(game,p[0x95]);if(!selected){p[0x8c]=3;return;}
 Entry entries[4];
 for(int i=0;i<4;i++){
 unsigned char *object=(unsigned char*)_ZN9GameState21GetPartyMemberByIndexEi(game,i);if(!object)continue;if(!_ZNK8Object3D17GetInheritedAlphaEv(object))continue;
 unsigned short field=_ZNK8Object3D10GetField06Ev(selected);if(field!=_ZNK8Object3D10GetField06Ev(object)||*(unsigned short*)(object+0x1b2))continue;
 if(**(unsigned**)(object+0x130)&1)continue;
 entries[i].first=0;entries[i].active=1;entries[i].zero=0;entries[i].invalid[0]=-1;entries[i].invalid[1]=-1;entries[i].invalid[2]=-1;entries[i].invalid[3]=-1;entries[i].negativeScale=-0x1000;
 entries[i].word=0;entries[i].beforeVector[0]=0;entries[i].beforeVector[1]=0;entries[i].vector[0]=0;entries[i].vector[1]=0;entries[i].vector[2]=0;entries[i].extras[0]=0;entries[i].extras[1]=0;entries[i].extras[2]=0;
 entries[i].scale.x=0x1000;entries[i].scale.y=0x1000;entries[i].scale.z=0x1000;
 Entry *entry=&entries[i];entry->flags.a=0;entry->flags.b=0;entry->flags.c=1;entry->flags.d=0;entry->flags.e=0;entry->flags.f=0;entry->flags.g=0;entry->flags.h=0;
 _ZN8Vector3iaSERKS_(entry->vector,object+0x44);Vector3i scale;_ZNK8Object3D8GetScaleEv(&scale,(Object3D*)object);_ZN8Vector3iaSERKS_(&entry->scale,&scale);
 ObjectPool_SpawnFromTemplateKey(display,0x11,entry);
 }
 *(int*)(p+0x90)=1;Network_QueuePartyDisplayRequestForCurrentZone(p[0x95]);
 }
}
