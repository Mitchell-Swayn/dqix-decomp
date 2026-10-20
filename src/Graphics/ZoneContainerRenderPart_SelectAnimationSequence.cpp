#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x2114e50; symbol: data_02114e50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct A{char pad[0x84];unsigned char enabled:1;};extern unsigned int FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;
// Original: arm9/main @ 0x020478BC; symbol: func_020478bc; size: 0x70.
void ZoneContainerRenderPart_SelectAnimationSequence(A *a,int id){char *p=(char *)a;if(!a->enabled)return;if(*(int *)(p+0x14)<=0)return;if(*(int *)(p+0x74)==id||id==0)return;*(int *)(p+0x70)=0;*(int *)(p+0x74)=id;*(int *)(p+0x78)=FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;char *data=*(char **)(p+12);char *entry=*(char **)(data+*(int *)(p+0x74)*8+4);*(int *)(p+0x7c)=*(int *)(entry+*(int *)(p+0x70)*12+4);}
}
