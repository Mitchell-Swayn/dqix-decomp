#include <globaldefs.h>
#include <std_library_functions.h>
ARM
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" {extern void* EventGetObjectSession_UnknownRoleZeroInitializedStorage[];char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);void Event_ResetScriptResourceState();void Graphics_InitializeAndCopyDisplayRecords();}
// Original: arm9/ov001 @ 0x0215A850; symbol: func_ov001_0215a850; size: 0x8C.
extern "C" void Resource_AllocateOverlayScriptObjectBuffers(unsigned allocator){
EventGetObjectSession_UnknownRoleZeroInitializedStorage[2]=_ZN13SafeAllocator8AllocateEj(allocator,0x260);
EventGetObjectSession_UnknownRoleZeroInitializedStorage[9]=_ZN13SafeAllocator8AllocateEj(allocator,0xa28);
EventGetObjectSession_UnknownRoleZeroInitializedStorage[8]=_ZN13SafeAllocator8AllocateEj(allocator,0x700);
EventGetObjectSession_UnknownRoleZeroInitializedStorage[7]=_ZN13SafeAllocator8AllocateEj(allocator,0x84c0);
void* table=_ZN13SafeAllocator8AllocateEj(allocator,0x200);EventGetObjectSession_UnknownRoleZeroInitializedStorage[1]=table;memset(table,0,0x200);
Event_ResetScriptResourceState();Graphics_InitializeAndCopyDisplayRecords();
}
