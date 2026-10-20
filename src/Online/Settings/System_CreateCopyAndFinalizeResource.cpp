#include <globaldefs.h>
ARM
extern "C" void* WfcUtility_LocalizeResourcePath(void*);
extern "C" void* WfcUtility_LoadArchiveResource(void*, unsigned, unsigned);
extern "C" void MIi_CpuCopyFast(const void*, void*, unsigned);
extern "C" void WfcUtility_FreeArchiveResourceAndReturnPoolEntry(void*);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned, void (*)(void*), unsigned, unsigned);
// Original data: arm9/ov031 @ 0x224b3c0; symbol: data_ov031_0224b3c0.
// Help overlay resource paths indexed by help topic.
// Initial values: hex 88b22402f0b1240230b3240248b3240260b3240218b32402d0b2240200b324022cb2240258b2240218b2240204b22402b8b22402a8b32402e8b2240240b22402 ...; full span in module reference.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* SystemCreateCopyAndFinalizeResource_HelpOverlayResourcePathsIndexedByHelpTopic[];
// Original data: arm9/ov031 @ 0x2250bf4; symbol: data_ov031_02250bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* LoadAndSelectMainBG1Data_UnknownRoleZeroInitializedStorage;
extern "C" void LoadAndSelectMainBG1Data(void*);
// Original: arm9/ov031 @ 0x02223998; symbol: func_ov031_02223998; size: 0x5C.
extern "C" void System_CreateCopyAndFinalizeResource(unsigned index) {
    void* base = WfcUtility_LocalizeResourcePath(SystemCreateCopyAndFinalizeResource_HelpOverlayResourcePathsIndexedByHelpTopic[index]);
    void* destination = WfcUtility_LoadArchiveResource(base, 0, 4);
    MIi_CpuCopyFast(destination, LoadAndSelectMainBG1Data_UnknownRoleZeroInitializedStorage, 0xc0);
    WfcUtility_FreeArchiveResourceAndReturnPoolEntry(destination);
    WfcUtility_CreateTaskWithBorrowedContext(1, LoadAndSelectMainBG1Data, 0, 0x78);
}
