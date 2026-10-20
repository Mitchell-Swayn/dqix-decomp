#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" void* GameState_GetObjectWithFlag100(void*,int);extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);extern "C" unsigned FieldAppearance_ReadMemberRefreshRequest(void*);extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
// Original data: arm9/ov017 @ 0x21d6b54; symbol: data_ov017_021d6b54.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0800.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6b56; symbol: data_ov017_021d6b56.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000010009000200070003000500040001000500060004000a000700.
// Observed span: 30 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
struct IndexPair{short index,other;};extern "C" IndexPair ResourceQueueRefreshForChangedMemberEquipment_UnknownRoleInitializedBytes[],ResourceQueueRefreshForChangedMemberEquipment_UnknownRoleInitializedBytes_Variant2[];extern "C" char Resource_QueueRefreshForChangedMemberEquipment_PathDataPrmItembtlprmNat[];

// Original: arm9/ov017 @ 0x021B3678; symbol: Resource_QueueRefreshForChangedMemberEquipment; size: 0x108.
extern "C" int Resource_QueueRefreshForChangedMemberEquipment(char* self){
void *game=_ZN9GameState11GetInstanceEv();void *loader=_ZN16BackgroundLoader11GetInstanceEv();char *object=(char*)GameState_GetObjectWithFlag100(game,*(short*)(self+8));if(!object)return 0;if(!GameObject_GetLinkedIndexedState(object))return 0;
 if(FieldAppearance_ReadMemberRefreshRequest(object)){char *data=*(char**)(object+0x150);if(data)data[0x56e]=0;*(int*)(self+16)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Resource_QueueRefreshForChangedMemberEquipment_PathDataPrmItembtlprmNat,0);return 1;}
 char *data=*(char**)(object+0x150);char *first=data+0x194;char *second=data+0x2f4;for(unsigned char i=0;i<8;++i){short a=ResourceQueueRefreshForChangedMemberEquipment_UnknownRoleInitializedBytes[i].index;if(a>=0){short b=ResourceQueueRefreshForChangedMemberEquipment_UnknownRoleInitializedBytes_Variant2[i].index;if(*(short*)(first+a*32+24)!=*(short*)(second+b*44+40)){*(int*)(self+16)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Resource_QueueRefreshForChangedMemberEquipment_PathDataPrmItembtlprmNat,0);return 1;}}}return 1;
}
