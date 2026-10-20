#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" {void* _ZN9GameState11GetInstanceEv();void* _ZN16BackgroundLoader11GetInstanceEv();int Script_ReadParameterAsInteger(void*);int Script_ResolveEventObjectIndex(int);void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);void _ZN8Object3D10InitializeEv(void*);void _ZN8Object3D14ShallowCloneToEPS_(void*,void*);void GameState_SetIndexedObjectAndSlot(void*,int,void*);void _ZN8Object3D8SetScaleEiii(void*,int,int,int);void _ZN8Object3D23SetBCFGAnimationByIndexEii(void*,int,int);extern void* EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov001 @ 0x0215BA64; symbol: Script_CloneIndexedObjectWithDefaultScale; size: 0xd8.
extern "C" int Script_CloneIndexedObjectWithDefaultScale(unsigned char* parameters,int count){void* state=_ZN9GameState11GetInstanceEv();_ZN16BackgroundLoader11GetInstanceEv();int source=Script_ResolveEventObjectIndex(Script_ReadParameterAsInteger(parameters));int destination=Script_ResolveEventObjectIndex(Script_ReadParameterAsInteger(parameters+8));int slot=0;if(count>=3)slot=Script_ReadParameterAsInteger(parameters+16);void* allocator=EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[slot];void* object=_ZN9GameState20GetGameObjectByIndexEi(state,source);if(!object)return 0;void* clone=_ZN13SafeAllocator8AllocateEj(allocator,172);if(!clone)return 0;_ZN8Object3D10InitializeEv(clone);_ZN8Object3D14ShallowCloneToEPS_(object,clone);GameState_SetIndexedObjectAndSlot(state,destination,clone);_ZN8Object3D8SetScaleEiii(clone,266,266,266);_ZN8Object3D23SetBCFGAnimationByIndexEii(clone,0,0);return 1;}
