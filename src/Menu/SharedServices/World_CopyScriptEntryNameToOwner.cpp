#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x217101c; symbol: data_ov004_0217101c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" void *FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;
extern "C" unsigned char *TextContext_GetSharedInstance(void);
extern "C" void TextLayout_ResetFormattingWorkspace(signed char *);
extern "C" unsigned int Resource_ReadIndexedNodeAndFlag(void *, unsigned int *);
extern "C" unsigned int *WorldScriptArray_FindEntryByKey(void *, unsigned int);
extern "C" void TextContext_SetStringArgument(void *, int, const char *);
// Original: arm9/ov004 @ 0x02167310; symbol: func_ov004_02167310; size: 0x60.
extern "C" int World_CopyScriptEntryNameToOwner(void *owner) {
    void *scriptArray = FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;
    unsigned char *object = TextContext_GetSharedInstance();
    TextLayout_ResetFormattingWorkspace((signed char *)object);
    unsigned int output;
    unsigned int key = Resource_ReadIndexedNodeAndFlag(owner, &output);
    unsigned int *entry = WorldScriptArray_FindEntryByKey((unsigned char *)scriptArray + 0xc, key);
    if (entry) TextContext_SetStringArgument(object, 0, (const char *)entry[1]);
    return 0;
}
