#include <globaldefs.h>
ARM
extern "C" void *Menu_FindCanvasNodeByKey(void *self, unsigned short value);
// Original data: arm9/ov004 @ 0x21707e8; symbol: data_ov004_021707e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[];
extern "C" void CharacterPreview_LoadPartyMemberIntoInactiveBank(void *, void *, int);
// Original: arm9/ov004 @ 0x02162A9C; symbol: func_ov004_02162a9c; size: 0x30.
extern "C" int StatusMenu_InitializeSelectedCharacterModel(void *object) {
    void *entry = Menu_FindCanvasNodeByKey(object, 0x82);
    if (entry != 0)
        CharacterPreview_LoadPartyMemberIntoInactiveBank(entry, *(void **)(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage + 0x1C), 1);
    return 0;
}
