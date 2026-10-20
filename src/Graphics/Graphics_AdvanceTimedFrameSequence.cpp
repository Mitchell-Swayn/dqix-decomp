#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x2114e00; symbol: data_02114e00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e50; symbol: data_02114e50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct A{char pad[0x84];unsigned char on:1;unsigned char active:1;};extern unsigned char GraphicsAdvanceTimedFrameSequence_UnknownRoleZeroInitializedStorage;extern unsigned int FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;
// Original: arm9/main @ 0x0204724C; symbol: func_0204724c; size: 0x98.
void Graphics_AdvanceTimedFrameSequence(A *a){char *p=(char *)a;if(!a->on)return;if(!a->active)return;if(GraphicsAdvanceTimedFrameSequence_UnknownRoleZeroInitializedStorage){*(unsigned int *)(p+0x78)=FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;return;}if(*(unsigned int *)(p+0x7c)>=FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2-*(unsigned int *)(p+0x78))return;unsigned int index=*(unsigned int *)(p+0x70)*12;char *list=*(char **)(p+12);char *entry=*(char **)(list+*(int *)(p+0x74)*8+4)+index;*(unsigned int *)(p+0x70)=*(unsigned int *)entry;*(unsigned int *)(p+0x78)=FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;*(unsigned int *)(p+0x7c)=*(unsigned int *)(entry+4);}
}
