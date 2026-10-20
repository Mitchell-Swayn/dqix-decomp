#pragma once

// Reviewed binary-backed battle-menu data; declarations do not define storage.
extern "C" {
// Original data: arm9/ov000 @ 0x02183380; symbol: data_ov000_02183380.
// Equipment-slot order used by GameState_AppendActiveObjectRecords to append occupied equipment records after carried-item choices.
// Values (uint8_t[8]): {8, 9, 7, 0, 5, 1, 6, 10}.
extern unsigned char BattleMenu_ItemChoiceEquipmentSlotOrder[];

// Original data: arm9/ov000 @ 0x02183388; symbol: data_ov000_02183388.
// Identical equipment-slot order used independently by BattleMenu_FindItemByEquipmentKey to search equipped records by key.
// Values (uint8_t[8]): {8, 9, 7, 0, 5, 1, 6, 10}.
extern unsigned char BattleMenu_EquipmentLookupSlotOrder[];

// Original data: arm9/ov000 @ 0x02183444; symbol: data_ov000_02183444.
// BattleMenu_CommitMatchingPartyVocationActions indexes this table by vocation kind and compares the action ID with each selected party command. The observed span contains 13 nonzero IDs and a trailing zero; the trailing zero may be padding.
// Values (uint16_t[]): {505, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 527, 516, 0}; trailing zero may be padding.
extern unsigned short BattleMenu_VocationActionIds[];

// Original data: arm9/ov000 @ 0x021834cc; symbol: data_ov000_021834cc.
// BattleMenu_PopSelectionPanels walks four pairs with stride two. The first column identifies canvas IDs requiring paired-panel handling; the second identifies the partner canvas to reset.
// Values (uint8_t[4][2]): {{15, 34}, {17, 36}, {16, 35}, {21, 22}}.
extern unsigned char BattleMenu_SelectionCanvasPairs[];

// Original data: arm9/ov000 @ 0x021834cd; symbol: data_ov000_021834cd.
// Aliases SelectionCanvasPairs + 1. The consumer indexes with stride two to read the four partner IDs; this is not a separate allocation.
// Values (strided uint8_t view): {34, 36, 35, 22}, stride 2; aliases BattleMenu_SelectionCanvasPairs + 1.
extern unsigned char BattleMenu_SelectionCanvasPartnerColumn[];

// Original data: arm9/ov000 @ 0x021834e0; symbol: data_ov000_021834e0.
// Text_AppendSixAlternatingWidthAlignedLabels uses order 0,3,1,4,2,5 to alternate the two display columns while resolving message IDs.
// Values (int32_t[6]): {0, 3, 1, 4, 2, 5}.
extern int BattleMenu_TwoColumnLabelOrder[];

// Original data: arm9/ov000 @ 0x02183ff4; symbol: data_ov000_02183ff4.
// The single null byte is the empty-string fallback passed to TextSprite_FormatAndUpdateTextReference when a command label cannot be resolved.
// Values (char[1]): "" (one NUL byte).
extern const char BattleMenu_EmptyCommandLabel[];

// Original data: arm9/ov000 @ 0x02183ff5; symbol: data_ov000_02183ff5.
// Null-terminated data/bin/menu/str_btl.gp2 resource path; the load relocation from arm9/ov000:02173590 belongs to BattleMenu_LoadControllerResources.
// Values (char[26]): "data/bin/menu/str_btl.gp2" + NUL (26 bytes).
extern char BattleMenu_MessageArchivePath[];

// Original data: arm9/ov000 @ 0x02184060; symbol: data_ov000_02184060.
// Literal <X=120> followed by a space; appended after grouped enemy/member-name text to position subsequent text.
// Values (char[9]): "<X=120> " + NUL (9 bytes; includes trailing space).
extern char BattleMenu_GroupedNameColumnSuffix[];

// Original data: arm9/ov000 @ 0x02184069; symbol: data_ov000_02184069.
// Literal <W=0>; Graphics_FormatPagedRecordNamesWithStyle emits it for a missing item entry.
// Values (char[6]): "<W=0>" + NUL (6 bytes).
extern char BattleMenu_EmptyItemWidthMarkup[];

}
