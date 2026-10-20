#include <globaldefs.h>
#include <System/Mutex.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original data: arm9/main @ 0x2112754; symbol: data_02112754.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern Mutex ObjectInvokeLockMutex_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020D21F8; symbol: func_020d21f8; size: 0x14.
    void Object_InvokeLockMutex(){
        LockMutex(&ObjectInvokeLockMutex_UnknownRoleZeroInitializedStorage);
    }
}
