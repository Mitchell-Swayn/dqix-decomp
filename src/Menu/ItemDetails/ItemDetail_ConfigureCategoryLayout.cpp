#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" char* MenuLayout_FindGroupByKey(char*, int);
extern "C" void Menu_SetLayoutCellContentAndStyle(void*, unsigned short, unsigned int, unsigned char, unsigned char);
struct ResourceStringTable;
extern "C" char* ResourceStringTable_GetTextByKey(ResourceStringTable*, int);
// Original data: arm9/ov023 @ 0x021FF9E0; symbol: data_ov023_021ff9e0.
// The shared item-detail state stores the label string table at +0x14.
extern "C" char MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[];
struct ItemCategoryBits { unsigned int category : 4; unsigned int remaining : 28; };
#define SHOW_LAYOUT_GROUP(KEY) do { \
    char* group = MenuLayout_FindGroupByKey(layout, KEY); \
    if (group) *(unsigned char*)(group + 0x16) &= ~1; \
} while (0)
#define SET_LAYOUT_LABEL(GROUP, KEY, STYLE) \
    Menu_SetLayoutCellContentAndStyle(layout, GROUP, \
        (unsigned int)ResourceStringTable_GetTextByKey(*(ResourceStringTable**)(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage + 0x14), KEY), STYLE, 15)
// Original: arm9/ov023 @ 0x021DBD10; symbol: func_ov023_021dbd10; size: 0x298.
// Selects the equipment or general-item layout groups and fills the latter's category labels.
extern "C" void ItemDetail_ConfigureCategoryLayout(char* layout, char* item) {
    if (!layout || !item) return;
    int equipment = ((ItemCategoryBits*)(item + 8))->category <= 7 ? 1 : 0;
    if (equipment) {
        SHOW_LAYOUT_GROUP(9);
        SHOW_LAYOUT_GROUP(28);
        SHOW_LAYOUT_GROUP(27);
        SHOW_LAYOUT_GROUP(11);
        SHOW_LAYOUT_GROUP(42);
        SHOW_LAYOUT_GROUP(44);
    } else {
        SHOW_LAYOUT_GROUP(20);
        SHOW_LAYOUT_GROUP(19);
        SHOW_LAYOUT_GROUP(16);
        SHOW_LAYOUT_GROUP(18);
        SHOW_LAYOUT_GROUP(15);
        SHOW_LAYOUT_GROUP(14);
        SET_LAYOUT_LABEL(25, 36, 10);
        SET_LAYOUT_LABEL(23, 35, 8);
        SET_LAYOUT_LABEL(26, 37, 10);
        SET_LAYOUT_LABEL(24, 35, 8);
        SET_LAYOUT_LABEL(21, 38, 10);
        SET_LAYOUT_LABEL(22, 39, 10);
    }
}
#undef SHOW_LAYOUT_GROUP
#undef SET_LAYOUT_LABEL
