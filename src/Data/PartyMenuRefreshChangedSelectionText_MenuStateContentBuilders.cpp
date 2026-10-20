// Original data: arm9/ov002 @ 0x216d10c; symbol: data_ov002_0216d10c.
// Menu state content builders; func_ov002_0215bba8 supplies adjusted menu object, output buffer, and alternate-mode flag in r0/r1/r2. ARM member-function dispatch ABI: adjustmentAndVirtual >> 1 is the this adjustment; bit 0 selects a virtual-table offset. All entries here are direct and have zero adjustment. Function return values are unused.
// Initial values: hex 000000000000000078c115020000000048c31502000000002cc51502000000002cc715020000000088c915020000000098cd150200000000e8d0150200000000 ...; full span in module reference.
// Observed span: 352 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
// Menu state content builders; func_ov002_0215bba8 supplies adjusted menu object, output buffer, and alternate-mode flag in r0/r1/r2.
// ARM member-function dispatch ABI: adjustmentAndVirtual >> 1 is the
// this adjustment; bit 0 selects a virtual-table offset. All entries here
// are direct and have zero adjustment. Function return values are unused.
typedef void (*MenuCallback)(void *menu, void *output, int alternateMode);
struct MenuDispatchEntry { MenuCallback target; int adjustmentAndVirtual; };
extern "C" {
extern void Text_AppendSixResourceOptions(void *menu, void *output, int alternateMode);
extern void PartyMenu_AppendSelectableMemberNames(void *menu, void *output, int alternateMode);
extern void PartyMenu_AppendInventoryCategoryOptions(void *menu, void *output, int alternateMode);
extern void Graphics_AppendPartyMemberListText(void *menu, void *output, int alternateMode);
extern void PartyMenu_AppendSelectedOwnerItems(void *menu, void *output, int alternateMode);
extern void Text_AppendCursorPageHeaderAndFourIndexedFragments(void *menu, void *output, int alternateMode);
extern void PartyMenu_AppendActionTargetNames(void *menu, void *output, int alternateMode);
extern void PartyMenu_FormatActionTargetStatus(void *menu, void *output, int alternateMode);
extern void Graphics_FormatColoredMemberList(void *menu, void *output, int alternateMode);
extern void Text_BuildPagedPrimaryRecordNameList(void *menu, void *output, int alternateMode);
extern void Graphics_AppendIndexedPartyAndExtraText(void *menu, void *output, int alternateMode);
extern void Graphics_AppendTwoSequentialTextFragments(void *menu, void *output, int alternateMode);
extern void PartyMenu_AppendItemTransferDestinationSlots(void *menu, void *output, int alternateMode);
extern void Text_AppendAvailablePartyMemberList(void *menu, void *output, int alternateMode);
extern void PartyMenu_FormatPartySummaryPanel(void *menu, void *output, int alternateMode);
extern void PartyMenu_AppendFieldActionMemberNames(void *menu, void *output, int alternateMode);
extern void AppendMenuCursorAndCurrentPageEntries(void *menu, void *output, int alternateMode);
extern void Graphics_FormatSelectedDescriptorOutput(void *menu, void *output, int alternateMode);
extern void PartyMenu_FormatSelectedActionMpCost(void *menu, void *output, int alternateMode);
extern void Graphics_FormatPagedByteKeyEntries(void *menu, void *output, int alternateMode);
extern void PartyMenu_AppendMiscellaneousCommandList(void *menu, void *output, int alternateMode);
extern void PartyMenu_AppendSelectedMiscellaneousCommandHelp(void *menu, void *output, int alternateMode);
extern void Text_AppendPartyMemberSelectionList(void *menu, void *output, int alternateMode);
extern void PartyMenu_AppendTacticsChoices(void *menu, void *output, int alternateMode);
extern void Graphics_FormatPartyMemberStatusText(void *menu, void *output, int alternateMode);
extern void PartyMenu_AppendSelectedMemberCommandHelp(void *menu, void *output, int alternateMode);
extern void Text_AppendCursorTagWithOptionalFormattedArguments(void *menu, void *output, int alternateMode);
extern void Graphics_AppendTwoCenteredIndexedTextLines(void *menu, void *output, int alternateMode);
extern void PartyMenu_AppendSkillPointMemberNames(void *menu, void *output, int alternateMode);
extern void PartyMenu_FormatSelectedMemberSkillPoints(void *menu, void *output, int alternateMode);
extern void Text_BuildSevenMappedOptionsAndFinalRow(void *menu, void *output, int alternateMode);
extern void Text_AppendPagedLookupGrid(void *menu, void *output, int alternateMode);
extern void PartyMenu_AppendSoundVolumeSettings(void *menu, void *output, int alternateMode);
extern void Text_AppendTwoIndexedFragmentsWithSeparator(void *menu, void *output, int alternateMode);
extern void PartyMenu_FormatActionResultMessage(void *menu, void *output, int alternateMode);
extern void Graphics_AppendCursorAndResourceTextFragments(void *menu, void *output, int alternateMode);
MenuDispatchEntry PartyMenuRefreshChangedSelectionText_MenuStateContentBuilders[44] = {
    { 0, 0 },
    { Text_AppendSixResourceOptions, 0 },
    { PartyMenu_AppendSelectableMemberNames, 0 },
    { PartyMenu_AppendInventoryCategoryOptions, 0 },
    { Graphics_AppendPartyMemberListText, 0 },
    { PartyMenu_AppendSelectedOwnerItems, 0 },
    { Text_AppendCursorPageHeaderAndFourIndexedFragments, 0 },
    { PartyMenu_AppendActionTargetNames, 0 },
    { PartyMenu_FormatActionTargetStatus, 0 },
    { Graphics_FormatColoredMemberList, 0 },
    { Text_BuildPagedPrimaryRecordNameList, 0 },
    { Graphics_AppendIndexedPartyAndExtraText, 0 },
    { Graphics_AppendTwoSequentialTextFragments, 0 },
    { PartyMenu_AppendItemTransferDestinationSlots, 0 },
    { Text_AppendAvailablePartyMemberList, 0 },
    { PartyMenu_FormatPartySummaryPanel, 0 },
    { PartyMenu_AppendFieldActionMemberNames, 0 },
    { AppendMenuCursorAndCurrentPageEntries, 0 },
    { Graphics_FormatSelectedDescriptorOutput, 0 },
    { PartyMenu_FormatSelectedActionMpCost, 0 },
    { Graphics_FormatPagedByteKeyEntries, 0 },
    { PartyMenu_AppendMiscellaneousCommandList, 0 },
    { PartyMenu_AppendSelectedMiscellaneousCommandHelp, 0 },
    { 0, 0 },
    { Text_AppendPartyMemberSelectionList, 0 },
    { PartyMenu_AppendTacticsChoices, 0 },
    { Graphics_FormatPartyMemberStatusText, 0 },
    { PartyMenu_AppendSelectedMemberCommandHelp, 0 },
    { Text_AppendCursorTagWithOptionalFormattedArguments, 0 },
    { Graphics_AppendTwoCenteredIndexedTextLines, 0 },
    { 0, 0 },
    { PartyMenu_AppendSkillPointMemberNames, 0 },
    { PartyMenu_FormatSelectedMemberSkillPoints, 0 },
    { Text_BuildSevenMappedOptionsAndFinalRow, 0 },
    { Text_AppendPagedLookupGrid, 0 },
    { PartyMenu_AppendSoundVolumeSettings, 0 },
    { 0, 0 },
    { Text_AppendTwoIndexedFragmentsWithSeparator, 0 },
    { PartyMenu_FormatActionResultMessage, 0 },
    { Graphics_AppendCursorAndResourceTextFragments, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
};
}
