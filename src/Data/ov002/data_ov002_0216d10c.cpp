// Menu state content builders; func_ov002_0215bba8 supplies adjusted menu object, output buffer, and alternate-mode flag in r0/r1/r2.
// ARM member-function dispatch ABI: adjustmentAndVirtual >> 1 is the
// this adjustment; bit 0 selects a virtual-table offset. All entries here
// are direct and have zero adjustment. Function return values are unused.
typedef void (*MenuCallback)(void *menu, void *output, int alternateMode);
struct MenuDispatchEntry { MenuCallback target; int adjustmentAndVirtual; };
extern "C" {
extern void Text_AppendSixResourceOptions(void *menu, void *output, int alternateMode);
extern void func_ov002_0215c348(void *menu, void *output, int alternateMode);
extern void func_ov002_0215c52c(void *menu, void *output, int alternateMode);
extern void Graphics_AppendPartyMemberListText(void *menu, void *output, int alternateMode);
extern void func_ov002_0215c988(void *menu, void *output, int alternateMode);
extern void func_ov002_0215cd98(void *menu, void *output, int alternateMode);
extern void func_ov002_0215d0e8(void *menu, void *output, int alternateMode);
extern void func_ov002_0215d214(void *menu, void *output, int alternateMode);
extern void Graphics_FormatColoredMemberList(void *menu, void *output, int alternateMode);
extern void Text_BuildPagedPrimaryRecordNameList(void *menu, void *output, int alternateMode);
extern void Graphics_AppendIndexedPartyAndExtraText(void *menu, void *output, int alternateMode);
extern void Graphics_AppendTwoSequentialTextFragments(void *menu, void *output, int alternateMode);
extern void func_ov002_0215de9c(void *menu, void *output, int alternateMode);
extern void Text_AppendAvailablePartyMemberList(void *menu, void *output, int alternateMode);
extern void func_ov002_0215e644(void *menu, void *output, int alternateMode);
extern void func_ov002_0215e9c4(void *menu, void *output, int alternateMode);
extern void func_ov002_0215ec4c(void *menu, void *output, int alternateMode);
extern void Graphics_FormatSelectedDescriptorOutput(void *menu, void *output, int alternateMode);
extern void func_ov002_0215f084(void *menu, void *output, int alternateMode);
extern void Graphics_FormatPagedByteKeyEntries(void *menu, void *output, int alternateMode);
extern void func_ov002_0215f4e8(void *menu, void *output, int alternateMode);
extern void GameState_AppendResolvedIndexedFormatText(void *menu, void *output, int alternateMode);
extern void Text_AppendPartyMemberSelectionList(void *menu, void *output, int alternateMode);
extern void func_ov002_0215fbd4(void *menu, void *output, int alternateMode);
extern void Graphics_FormatPartyMemberStatusText(void *menu, void *output, int alternateMode);
extern void func_ov002_02160004(void *menu, void *output, int alternateMode);
extern void Text_AppendCursorTagWithOptionalFormattedArguments(void *menu, void *output, int alternateMode);
extern void Graphics_AppendTwoCenteredIndexedTextLines(void *menu, void *output, int alternateMode);
extern void func_ov002_0216049c(void *menu, void *output, int alternateMode);
extern void func_ov002_021605d4(void *menu, void *output, int alternateMode);
extern void Text_BuildSevenMappedOptionsAndFinalRow(void *menu, void *output, int alternateMode);
extern void Text_AppendPagedLookupGrid(void *menu, void *output, int alternateMode);
extern void func_ov002_02160ce8(void *menu, void *output, int alternateMode);
extern void Text_AppendTwoIndexedFragmentsWithSeparator(void *menu, void *output, int alternateMode);
extern void func_ov002_02161234(void *menu, void *output, int alternateMode);
extern void Graphics_AppendCursorAndResourceTextFragments(void *menu, void *output, int alternateMode);
MenuDispatchEntry data_ov002_0216d10c[44] = {
    { 0, 0 },
    { Text_AppendSixResourceOptions, 0 },
    { func_ov002_0215c348, 0 },
    { func_ov002_0215c52c, 0 },
    { Graphics_AppendPartyMemberListText, 0 },
    { func_ov002_0215c988, 0 },
    { func_ov002_0215cd98, 0 },
    { func_ov002_0215d0e8, 0 },
    { func_ov002_0215d214, 0 },
    { Graphics_FormatColoredMemberList, 0 },
    { Text_BuildPagedPrimaryRecordNameList, 0 },
    { Graphics_AppendIndexedPartyAndExtraText, 0 },
    { Graphics_AppendTwoSequentialTextFragments, 0 },
    { func_ov002_0215de9c, 0 },
    { Text_AppendAvailablePartyMemberList, 0 },
    { func_ov002_0215e644, 0 },
    { func_ov002_0215e9c4, 0 },
    { func_ov002_0215ec4c, 0 },
    { Graphics_FormatSelectedDescriptorOutput, 0 },
    { func_ov002_0215f084, 0 },
    { Graphics_FormatPagedByteKeyEntries, 0 },
    { func_ov002_0215f4e8, 0 },
    { GameState_AppendResolvedIndexedFormatText, 0 },
    { 0, 0 },
    { Text_AppendPartyMemberSelectionList, 0 },
    { func_ov002_0215fbd4, 0 },
    { Graphics_FormatPartyMemberStatusText, 0 },
    { func_ov002_02160004, 0 },
    { Text_AppendCursorTagWithOptionalFormattedArguments, 0 },
    { Graphics_AppendTwoCenteredIndexedTextLines, 0 },
    { 0, 0 },
    { func_ov002_0216049c, 0 },
    { func_ov002_021605d4, 0 },
    { Text_BuildSevenMappedOptionsAndFinalRow, 0 },
    { Text_AppendPagedLookupGrid, 0 },
    { func_ov002_02160ce8, 0 },
    { 0, 0 },
    { Text_AppendTwoIndexedFragmentsWithSeparator, 0 },
    { func_ov002_02161234, 0 },
    { Graphics_AppendCursorAndResourceTextFragments, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
};
}
