#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707e8; symbol: data_ov004_021707e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned char *Menu_FindCanvasNodeByKey(void *, int);
// Original: arm9/ov004 @ 0x02163284; symbol: func_ov004_02163284; size: 0x38.
extern "C" int StatusMenu_ResetPreviewTracking(void *self) {
    *(unsigned int *)(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage + 0x20) = 0xFFFFFFFF;
    *(unsigned int *)(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage + 0x24) = 0;
    unsigned char *object = Menu_FindCanvasNodeByKey(self, 9);
    object[0x0C] |= 1;
    return 0;
}
