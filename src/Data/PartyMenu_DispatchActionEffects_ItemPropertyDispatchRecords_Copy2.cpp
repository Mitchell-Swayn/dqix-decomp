// Original data: arm9/ov002 @ 0x216ccc4; symbol: data_ov002_0216ccc4.
// Item property dispatch table. func_ov002_021536ec scans 12-byte records using signed 16-bit property IDs (-1 terminates), then calls the member target with object, selection, item record and property kind.
// Observed values: hex 000000000000000005000000a43e150200000000ffff00000000000000000000.
// Span: 32 bytes to next configured symbol; logical object size may differ.
// Item property dispatch table. func_ov002_021536ec scans 12-byte
// records using signed 16-bit property IDs (-1 terminates), then calls
// the member target with object, selection, item record and property kind.
typedef int (*ItemPropertyCallback)(void *, void *, void *, int);
struct PropertyHandler { short id; unsigned short padding; ItemPropertyCallback target; int adjustmentAndVirtual; };
struct PropertyDispatchTail { ItemPropertyCallback firstTarget; int firstAdjustmentAndVirtual; PropertyHandler remaining[2]; };
extern "C" {
extern int PartyMenu_RemovePoisonFromTargets(void *object, void *selection, void *itemRecord, int propertyKind);
PropertyDispatchTail PartyMenu_DispatchActionEffects_ItemPropertyDispatchRecords_Copy2 = { 0, 0, {
    { 5, 0, PartyMenu_RemovePoisonFromTargets, 0 },
    { -1, 0, 0, 0 },
} };
}
