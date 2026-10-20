#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x2165828; symbol: data_ov001_02165828.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 84 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char OverlayEnsureCurrentItemAndProcess_UnknownRoleZeroInitializedStorage[];
extern "C" void Script_ClearExecutionStatusAndArchive(void *);
extern "C" unsigned char *_ZN13SafeAllocator8AllocateEj(void *, unsigned);
extern "C" void Resource_InitializeSb2ScriptBuffers(void *, void *, void *, int, void *, int);
extern "C" void Event_InitializeScriptOpcodeHandlerTable(void *);
// Original: arm9/ov001 @ 0x021538D4; symbol: func_ov001_021538d4; size: 0x74.
extern "C" void Memory_InitializeContextBuffersWhenEnabled(void *script, int unused, void *allocator) {
    if (script == 0 || allocator == 0) {
        Script_ClearExecutionStatusAndArchive(OverlayEnsureCurrentItemAndProcess_UnknownRoleZeroInitializedStorage);
        return;
    }
    void *smallBuffer = _ZN13SafeAllocator8AllocateEj(allocator, 0x400);
    void *largeBuffer = _ZN13SafeAllocator8AllocateEj(allocator, 0x1800);
    Resource_InitializeSb2ScriptBuffers(OverlayEnsureCurrentItemAndProcess_UnknownRoleZeroInitializedStorage, script, smallBuffer, 0x80, largeBuffer, 0x200);
    Event_InitializeScriptOpcodeHandlerTable(OverlayEnsureCurrentItemAndProcess_UnknownRoleZeroInitializedStorage);
}
