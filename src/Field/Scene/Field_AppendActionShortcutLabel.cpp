#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x0219A544; symbol: AppendResolvedCategoryLabel; size: 0x100.
// Appends a type-specific record label, resolving a positive protagonist index when needed.
extern "C" {
// Original data: arm9/ov017 @ 0x21d6470; symbol: data_ov017_021d6470.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0300000004000000050000000600000007000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern unsigned int FieldAppendActionShortcutLabel_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov017 @ 0x21d6460; symbol: data_ov017_021d6460.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 70000000700000007000000080000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern int FieldAppendActionShortcutLabel_UnknownRoleInitializedBytes[];
void *_ZN9GameState11GetInstanceEv();
void *_ZN9GameState14GetProtagonistEv(void *state);
int GameState_GetActionShortcutAssignment(void *object, unsigned index);
void *ResourceStringTable_GetTextByKey(void *records, int index);
int TextMarkup_AppendTenTag(char *out, int tag, int parameter);
int TextMarkup_AppendXPositionTag(char *out, int value);
unsigned int Text_AppendCenteredTextUsingComputedWidth(char *out, const char *text, int width, int mode);
}
struct FiveEntryIndexTable { unsigned int entries[5]; };
extern "C" void Field_AppendActionShortcutLabel(void *self, char *out, unsigned category, int index) {
    if (out == 0) return;
    if (category == 3 && index > 0)
        TextMarkup_AppendTenTag(out, 3, 2);
    if (category == 3 && index <= 0) {
        FiveEntryIndexTable local;
        *(FiveEntryIndexTable *)&local = *(FiveEntryIndexTable *)FieldAppendActionShortcutLabel_UnknownRoleInitializedBytes_Variant2;
        void *gameState;
        void *protagonist;
        unsigned char i;
        i = 0;
        gameState = _ZN9GameState11GetInstanceEv();
        protagonist = _ZN9GameState14GetProtagonistEv(gameState);
        while (((volatile unsigned int *)local.entries)[i] != 7) {
            signed char found = (signed char)GameState_GetActionShortcutAssignment(protagonist, ((volatile unsigned int *)local.entries)[i]);
            index = found;
            if (index > 0) break;
            ++i;
        }
    }
    if (index < 0) index = 0;
    void *records = *(void **)((char *)self + 0x4084);
    const char *text = (const char *)ResourceStringTable_GetTextByKey(records, index);
    if (text != 0) {
        TextMarkup_AppendXPositionTag(out, 0);
        Text_AppendCenteredTextUsingComputedWidth(out, text, FieldAppendActionShortcutLabel_UnknownRoleInitializedBytes[category], 0);
    }
}
