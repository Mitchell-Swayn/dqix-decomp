#include <globaldefs.h>
ARM
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x2109d88; symbol: data_02109d88.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* ScriptQueryContextGetActiveInstance_UnknownRoleZeroInitializedStorage;
extern "C" void DisableInterruptsAndHaltForever();
extern "C" void Resource_InitializeSb2ScriptBuffers(void*,void*,void*,int,void*,int);
extern "C" void Script_RegisterFortyNineIndexedOpcodeHandlers(void*);
struct State {char pad[8];void* context;void* argument;char object[1];};
// Original: arm9/main @ 0x0209FD64; symbol: func_0209fd64; size: 0x84.
extern "C" void Memory_AllocateContextBuffersAndInitializeScriptObject(State* p,SafeAllocator* allocator,void* context,void* argument) {
    ScriptQueryContextGetActiveInstance_UnknownRoleZeroInitializedStorage=p;p->context=context;p->argument=argument;
    void* a=allocator->Allocate(1024);void* b=allocator->Allocate(6144);
    if(!a||!b)DisableInterruptsAndHaltForever();
    Resource_InitializeSb2ScriptBuffers(p->object,p->context,a,128,b,512);
    Script_RegisterFortyNineIndexedOpcodeHandlers(p->object);
}
