#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>

struct ScriptTableState
{
    void* state;
    unsigned char reserved[8];
    SafeAllocator* allocator;
};

extern "C" {
// Original data: arm9/main @ 0x2108efc; symbol: data_02108efc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern ScriptTableState ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage;
    void CharacterTemplate_AllocateEntries(unsigned int* state, SafeAllocator* allocator, int count);
// Original: arm9/main @ 0x02089B64; symbol: func_02089b64; size: 0x2C.
    ARM int Script_AllocateStateByIntegerParameter(Script::Parameter* parameter)
    {
        CharacterTemplate_AllocateEntries((unsigned int*)ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage.state, ScriptAllocateAndCopyNameArray_UnknownRoleZeroInitializedStorage.allocator, (short)parameter->ToInt());
        return 1;
    }
}
