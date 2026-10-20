#include "globaldefs.h"
#include "Memory/SafeAllocator.h"
#pragma optimize_for_size off
ARM
// Original data: arm9/main @ 0x2109d8c; symbol: data_02109d8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Object{int unused,a,b;unsigned char state[1];};extern "C" Object* ScriptListContextGetActiveInstance_UnknownRoleZeroInitializedStorage;extern "C" void DisableInterruptsAndHaltForever();extern "C" void Resource_InitializeSb2ScriptBuffers(void*,int,void*,unsigned,void*,unsigned);extern "C" void Script_InitializeOpcodeHandlers(void*);
// Original: arm9/main @ 0x0209FEE4; symbol: func_0209fee4; size: 0x80.
extern "C" void AllocateTwoStateBuffersAndInitializeOwner(Object*p,SafeAllocator* heap,int a,int b){ScriptListContextGetActiveInstance_UnknownRoleZeroInitializedStorage=p;p->a=a;p->b=b;void*x=heap->Allocate(0x400);void*y=heap->Allocate(0x1800);if(!x||!y)DisableInterruptsAndHaltForever();Resource_InitializeSb2ScriptBuffers(p->state,p->a,x,128,y,512);Script_InitializeOpcodeHandlers(p->state);}
