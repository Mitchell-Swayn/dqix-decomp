// Original data: arm9/ov002 @ 0x216cce8; symbol: data_ov002_0216cce8.
// Item property dispatch table. func_ov002_021536ec scans 12-byte records using signed 16-bit property IDs (-1 terminates), then calls the member target with object, selection, item record and property kind.
// Observed values: hex 000000000000000002000000cc3c15020000000007000000a43e1502000000004f00000020401502000000005000000020401502000000001200000030421502000000001a000000f4441502000000001d000000c84615020000000036000000244815020000000055000000b8481502000000002b000000a43e150200000000ffff00000000000000000000.
// Span: 140 bytes to next configured symbol; logical object size may differ.
// Item property dispatch table. func_ov002_021536ec scans 12-byte
// records using signed 16-bit property IDs (-1 terminates), then calls
// the member target with object, selection, item record and property kind.
typedef int (*ItemPropertyCallback)(void *, void *, void *, int);
struct PropertyHandler { short id; unsigned short padding; ItemPropertyCallback target; int adjustmentAndVirtual; };
struct PropertyDispatchTail { ItemPropertyCallback firstTarget; int firstAdjustmentAndVirtual; PropertyHandler remaining[11]; };
extern "C" {
extern int PartyMenu_ApplyHpRecoveryToTargets(void *object, void *selection, void *itemRecord, int propertyKind);
extern int PartyMenu_RemovePoisonFromTargets(void *object, void *selection, void *itemRecord, int propertyKind);
extern int PartyMenu_ApplyHpRecoveryAndRemovePoison(void *object, void *selection, void *itemRecord, int propertyKind);
extern int PartyMenu_ReviveActionTargets(void *object, void *selection, void *itemRecord, int propertyKind);
extern int PartyMenu_ApplyMpRecoveryToTargets(void *object, void *selection, void *itemRecord, int propertyKind);
extern int PartyMenu_ApplyStatIncreaseItemToTargets(void *object, void *selection, void *itemRecord, int propertyKind);
extern int GameState_ApplyPartyFlagInEligibleZone(void *object, void *selection, void *itemRecord, int propertyKind);
extern int PartyMenu_RejectUnsupportedActionEffect(void *object, void *selection, void *itemRecord, int propertyKind);
PropertyDispatchTail PartyMenu_DispatchActionEffects_ItemPropertyDispatchRecords_Copy4 = { 0, 0, {
    { 2, 0, PartyMenu_ApplyHpRecoveryToTargets, 0 },
    { 7, 0, PartyMenu_RemovePoisonFromTargets, 0 },
    { 79, 0, PartyMenu_ApplyHpRecoveryAndRemovePoison, 0 },
    { 80, 0, PartyMenu_ApplyHpRecoveryAndRemovePoison, 0 },
    { 18, 0, PartyMenu_ReviveActionTargets, 0 },
    { 26, 0, PartyMenu_ApplyMpRecoveryToTargets, 0 },
    { 29, 0, PartyMenu_ApplyStatIncreaseItemToTargets, 0 },
    { 54, 0, GameState_ApplyPartyFlagInEligibleZone, 0 },
    { 85, 0, PartyMenu_RejectUnsupportedActionEffect, 0 },
    { 43, 0, PartyMenu_RemovePoisonFromTargets, 0 },
    { -1, 0, 0, 0 },
} };
}
