#include <globaldefs.h>
ARM
extern "C" unsigned VectorizedMemset(void*, int, unsigned);
extern "C" void MI_CpuCopy8(const void*, void*, unsigned);
extern "C" void WfcUtility_CommitEditedConnectionProfile();
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage[];
struct PageModeBits { unsigned char selector : 2; unsigned char reserved : 6; };
// Original: arm9/ov031 @ 0x02236364; symbol: Graphics_InitializeDisplayPageFromFieldSnapshot; size: 0x110.
// Copies the selected fields of an input display snapshot into the shared page, resets page flags, and applies the updated page.
extern "C" void Graphics_InitializeDisplayPageFromFieldSnapshot(const unsigned char* input) {
    unsigned char* page = *(unsigned char**)NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage + 0x400;
    VectorizedMemset(page, 0, 0xef);
    MI_CpuCopy8(input, page + 0xd1, 5);
    MI_CpuCopy8(input + 6, page + 0xd6, 5);
    MI_CpuCopy8(input + 0xc, page + 0xdb, 5);
    MI_CpuCopy8(input + 0x12, page + 0xe0, 5);
    MI_CpuCopy8(input + 0x18, page + 0x60, 0x20);
    MI_CpuCopy8(input + 0x39, page + 0x80, 0xd);
    MI_CpuCopy8(input + 0x47, page + 0x90, 0xd);
    MI_CpuCopy8(input + 0x55, page + 0xa0, 0xd);
    MI_CpuCopy8(input + 0x63, page + 0xb0, 0xd);
    MI_CpuCopy8(input + 0x71, page + 0x40, 0x20);
    PageModeBits* mode = (PageModeBits*)(page + 0xe6);
    mode->selector = 2;
    mode->reserved = 0;
    page[0xe7] = 1;
    VectorizedMemset(page + 0xf0, 0, 4);
    page[0xf5] = 1;
    page[0xf6] = 1;
    WfcUtility_CommitEditedConnectionProfile();
}
