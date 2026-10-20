#include <globaldefs.h>
#include <System/BGBases.h>
#include <Graphics/NSBXX/JACInternal.h>
ARM
extern "C" void WfcUtility_RemoveTaskImmediately(int, unsigned int);
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
// Original data: arm9/ov031 @ 0x2290d38; symbol: data_ov031_02290d38.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223C760; symbol: func_ov031_0223c760; size: 0x64.
extern "C" void WfcUtility_DestroyBackgroundTextCanvas(void *owner) {
    WfcUtility_RemoveTaskImmediately(1, *(unsigned int *)((char *)owner + 0x2c));
    void *base = (char *)WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage + 0x610;
    if (owner == base) {
        MIi_CpuClear16(0, (void *)GetMainBG0CharacterBase(), 0x6000);
    } else {
        MIi_CpuClear16(0, (void *)GetMainBG0CharacterBase(), 0x3000);
    }
    WfcUtility_FreeAllocationAndClearPointer((void **)((char *)owner + 0x28));
}
