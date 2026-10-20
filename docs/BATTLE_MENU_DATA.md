# Battle-menu data symbols

The ten reviewed symbols below belong to `BATTLE-MENUS`. All addresses are
loaded ARM9 `ov000` addresses. Original identifiers are `data_ov000_<address>`;
[the data-name registry](../config/usa/data_names.json) retains those identifiers,
reference evidence, inferred types, byte extents and original-byte hashes.

These are data symbols, not functions. The types describe observed access and
bytes; they are not new compiled data definitions. Original binary data still
supplies these objects, so naming does not increase reconstructed coverage.

| Address | Name | Inferred type and meaning |
| --- | --- | --- |
| `02183380` | `BattleMenu_ItemChoiceEquipmentSlotOrder` | `uint8_t[8]`: equipment slots appended after carried-item choices by `GameState_AppendActiveObjectRecords`. |
| `02183388` | `BattleMenu_EquipmentLookupSlotOrder` | `uint8_t[8]`: slots searched by `BattleMenu_FindItemByEquipmentKey`. |
| `02183444` | `BattleMenu_VocationActionIds` | `uint16_t[]`: action IDs indexed by vocation kind in `BattleMenu_CommitMatchingPartyVocationActions`. |
| `021834cc` | `BattleMenu_SelectionCanvasPairs` | `uint8_t[4][2]`: paired selection canvases used by `BattleMenu_PopSelectionPanels`. |
| `021834cd` | `BattleMenu_SelectionCanvasPartnerColumn` | Strided byte view of the second column of the preceding table; aliases its address plus one. |
| `021834e0` | `BattleMenu_TwoColumnLabelOrder` | `int32_t[6]`: message order for `Text_AppendSixAlternatingWidthAlignedLabels`. |
| `02183ff4` | `BattleMenu_EmptyCommandLabel` | `char[1]`: empty label fallback in `BattleMenu_RefreshMemberCommandLabel`. |
| `02183ff5` | `BattleMenu_MessageArchivePath` | `char[26]`: NUL-terminated `data/bin/menu/str_btl.gp2`, loaded by `BattleMenu_LoadControllerResources`. |
| `02184060` | `BattleMenu_GroupedNameColumnSuffix` | `char[9]`: NUL-terminated `<X=120> ` appended by `Graphics_AppendGroupedMemberNameText`. |
| `02184069` | `BattleMenu_EmptyItemWidthMarkup` | `char[6]`: NUL-terminated `<W=0>` for missing item entries in `Graphics_FormatPagedRecordNamesWithStyle`. |

## Layout and interpretation

Both equipment-slot arrays contain `8, 9, 7, 0, 5, 1, 6, 10`.
They occupy distinct addresses and remain separate objects despite identical bytes.

The observed 28-byte vocation-table span contains
`505, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 527, 516, 0`.
The next configured symbol bounds that span. The logical array length and the
purpose of the trailing zero remain uncertain; it may be alignment padding.

The canvas pairs are `(15, 34), (17, 36), (16, 35), (21, 22)`.
The partner-column symbol addresses the same allocation with a two-byte stride;
its seven-byte observed span is not a separate seven-element array.

The two-column label order is `0, 3, 1, 4, 2, 5`. These values control message
lookup order and column placement, rather than identifying six separate strings.
