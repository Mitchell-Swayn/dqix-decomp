#include <globaldefs.h>
ARM
#pragma force_active on
// Original data: arm9/ov031 @ 0x02290d2c; symbol: data_ov031_02290d2c.
// Initial value: zero-filled at load; runtime pointer or shared state storage.
// Field offsets and indexed loads follow the original instructions.
// Full initial contents and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *WfcUtilityExpandSpriteCellTemplate_UnknownRoleZeroInitializedStorage[];
extern "C" void *WfcUtility_AllocateSpriteGroup(int, unsigned, int);
extern "C" void *WfcUtility_GetSpriteGroupEntry(void *, unsigned);
extern "C" void WfcUtility_ExpandSpriteCellTemplate(unsigned, unsigned, void *);
// Original: arm9/ov031 @ 0x0223BE70; symbol: func_ov031_0223be70; size: 0x48.
// Allocates a sprite group and expands the selected cell template into its entries.
extern "C" void * WfcUtility_CreateSpriteGroupFromCellTemplate(unsigned table, unsigned index, int fromFront)
{
    unsigned char *templates = WfcUtilityExpandSpriteCellTemplate_UnknownRoleZeroInitializedStorage[table];
    void *group = WfcUtility_AllocateSpriteGroup(table, *(unsigned short *)(templates + index * 8), fromFront);
    void *entry = WfcUtility_GetSpriteGroupEntry(group, 0);
    WfcUtility_ExpandSpriteCellTemplate(table, index, entry);
    return group;
}
#pragma force_active reset
