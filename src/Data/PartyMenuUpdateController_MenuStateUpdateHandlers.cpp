// Original data: arm9/ov002 @ 0x216cd74; symbol: data_ov002_0216cd74.
// Menu state update handlers; func_ov002_02155960 supplies adjusted menu object in r0. ARM member-function dispatch ABI: adjustmentAndVirtual >> 1 is the this adjustment; bit 0 selects a virtual-table offset. All entries here are direct and have zero adjustment. Function return values are unused.
// Initial values: hex 4c62150200000000ec221602000000007c2516020000000014271602000000006429160200000000502e160200000000e8311602000000006436160200000000 ...; full span in module reference.
// Observed span: 352 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
// Menu state update handlers; func_ov002_02155960 supplies adjusted menu object in r0.
// ARM member-function dispatch ABI: adjustmentAndVirtual >> 1 is the
// this adjustment; bit 0 selects a virtual-table offset. All entries here
// are direct and have zero adjustment. Function return values are unused.
typedef void (*MenuCallback)(void *menu);
struct MenuDispatchEntry { MenuCallback target; int adjustmentAndVirtual; };
extern "C" {
extern void PartyMenu_LoadAndInitializeDisplay(void *menu);
extern void PartyMenu_UpdateMainCommandSelection(void *menu);
extern void PartyMenu_UpdatePartyMemberSceneSelection(void *menu);
extern void PartyMenu_UpdateItemCategorySelection(void *menu);
extern void PartyMenu_UpdateInventoryOwnerSelection(void *menu);
extern void PartyMenu_UpdateInventoryItemSelection(void *menu);
extern void PartyMenu_UpdateItemActionSelection(void *menu);
extern void PartyMenu_UpdateActionTargetSelection(void *menu);
extern void PartyMenu_UpdateItemRecipientSelection(void *menu);
extern void PartyMenu_UpdateImportantItemSelection(void *menu);
extern void PartyMenu_UpdateBulkInventoryOwnerSelection(void *menu);
extern void PartyMenu_IgnoreReservedScreenUpdate(void *menu);
extern void PartyMenu_UpdateItemTransferSlotSelection(void *menu);
extern void PartyMenu_UpdateStatusScreenMemberSelection(void *menu);
extern void PartyMenu_UpdatePartySummaryDisplay(void *menu);
extern void PartyMenu_UpdateFieldActionCasterSelection(void *menu);
extern void PartyMenu_UpdateFieldActionSelection(void *menu);
extern void PartyMenu_UpdateZoomDestinationSelection(void *menu);
extern void PartyMenu_UpdateMiscellaneousCommandSelection(void *menu);
extern void PartyMenu_UpdateAutomaticPartyHealing(void *menu);
extern void PartyMenu_UpdateMemberTacticsAndAppearance(void *menu);
extern void PartyMenu_UpdateTacticsSelection(void *menu);
extern void PartyMenu_UpdateMemberPaletteSelection(void *menu);
extern void PartyMenu_UpdateSkillAllocationAndUnlockNotifications(void *menu);
extern void PartyMenu_UpdateSkillPointMemberSelection(void *menu);
extern void PartyMenu_UpdateActionShortcutSlotSelection(void *menu);
extern void PartyMenu_UpdateActionShortcutAssignment(void *menu);
extern void PartyMenu_UpdateSoundVolumeSettings(void *menu);
extern void PartyMenu_UpdateSaveAndQuit(void *menu);
extern void PartyMenu_UpdateActionConfirmation(void *menu);
extern void PartyMenu_UpdateActionMessagesAndRestoreScreen(void *menu);
extern void PartyMenu_UpdateStoredItemSelectionConfirmation(void *menu);
extern void PartyMenu_UpdateSubscreenCleanup(void *menu);
MenuDispatchEntry PartyMenuUpdateController_MenuStateUpdateHandlers[44] = {
    { PartyMenu_LoadAndInitializeDisplay, 0 },
    { PartyMenu_UpdateMainCommandSelection, 0 },
    { PartyMenu_UpdatePartyMemberSceneSelection, 0 },
    { PartyMenu_UpdateItemCategorySelection, 0 },
    { PartyMenu_UpdateInventoryOwnerSelection, 0 },
    { PartyMenu_UpdateInventoryItemSelection, 0 },
    { PartyMenu_UpdateItemActionSelection, 0 },
    { PartyMenu_UpdateActionTargetSelection, 0 },
    { 0, 0 },
    { PartyMenu_UpdateItemRecipientSelection, 0 },
    { PartyMenu_UpdateImportantItemSelection, 0 },
    { PartyMenu_UpdateBulkInventoryOwnerSelection, 0 },
    { PartyMenu_IgnoreReservedScreenUpdate, 0 },
    { PartyMenu_UpdateItemTransferSlotSelection, 0 },
    { PartyMenu_UpdateStatusScreenMemberSelection, 0 },
    { PartyMenu_UpdatePartySummaryDisplay, 0 },
    { PartyMenu_UpdateFieldActionCasterSelection, 0 },
    { PartyMenu_UpdateFieldActionSelection, 0 },
    { 0, 0 },
    { 0, 0 },
    { PartyMenu_UpdateZoomDestinationSelection, 0 },
    { PartyMenu_UpdateMiscellaneousCommandSelection, 0 },
    { 0, 0 },
    { PartyMenu_UpdateAutomaticPartyHealing, 0 },
    { PartyMenu_UpdateMemberTacticsAndAppearance, 0 },
    { PartyMenu_UpdateTacticsSelection, 0 },
    { 0, 0 },
    { 0, 0 },
    { PartyMenu_UpdateMemberPaletteSelection, 0 },
    { 0, 0 },
    { PartyMenu_UpdateSkillAllocationAndUnlockNotifications, 0 },
    { PartyMenu_UpdateSkillPointMemberSelection, 0 },
    { 0, 0 },
    { PartyMenu_UpdateActionShortcutSlotSelection, 0 },
    { PartyMenu_UpdateActionShortcutAssignment, 0 },
    { PartyMenu_UpdateSoundVolumeSettings, 0 },
    { PartyMenu_UpdateSaveAndQuit, 0 },
    { PartyMenu_UpdateActionConfirmation, 0 },
    { PartyMenu_UpdateActionMessagesAndRestoreScreen, 0 },
    { PartyMenu_UpdateStoredItemSelectionConfirmation, 0 },
    { 0, 0 },
    { 0, 0 },
    { PartyMenu_UpdateSubscreenCleanup, 0 },
    { 0, 0 },
};
}
