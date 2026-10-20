#include <globaldefs.h>
#include <std_library_functions.h>
ARM
// Original data: arm9/ov004 @ 0x217018c; symbol: data_ov004_0217018c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 0000000070ba160210c8160250c7160204d0160288d11602c4d1160258d3160204d51602b0d51602a0d61602dcd6160218d7160220d71602f8d7160220d81602 ...; full span in module reference.
// Observed span: 79 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned int TitleMenuAllocateAndInstallScriptCallbacks_UnknownRoleProcedureReferenceRecords[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned int, unsigned int);
extern "C" void Menu_SetCallbackTableAndCount(void *, unsigned int, unsigned int);
struct TemplateBlob { unsigned int words[54]; };
// Original: arm9/ov004 @ 0x0216E9CC; symbol: func_ov004_0216e9cc; size: 0x6C.
extern "C" void TitleMenu_AllocateAndInstallScriptCallbacks(unsigned int allocator, void *state) {
    struct TemplateBlob local = *(struct TemplateBlob *)TitleMenuAllocateAndInstallScriptCallbacks_UnknownRoleProcedureReferenceRecords;
    void *copy = _ZN13SafeAllocator8AllocateEj(allocator, 0xd8);
    memcpy(copy, &local, 0xd8);
    Menu_SetCallbackTableAndCount(state, (unsigned int)copy, 0x36);
}
