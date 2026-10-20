// Original data: arm9/ov002 @ 0x216cb1c; symbol: data_ov002_0216cb1c.
// Menu state rebuild transitions; func_ov002_0215bba8 scans source/destination pairs with eight-byte stride until negative source. Original symbols split the first source word from the table tail.
// Observed values: hex 08000000090000000d000000110000001200000011000000130000001f00000020000000ffffffffffffffff.
// Span: 44 bytes to next configured symbol; logical object size may differ.
// Menu state rebuild transitions; func_ov002_0215bba8 scans
// source/destination pairs with eight-byte stride until negative source.
// Original symbols split the first source word from the table tail.
struct MenuStateTransition { int source, destination; };
struct MenuStateTransitionTail { int firstDestination; MenuStateTransition remaining[5]; };
extern "C" const MenuStateTransitionTail PartyMenu_RefreshChangedSelectionText_StateRebuildTransitionRecords_Copy2 = { 8, {
    { 9, 13 },
    { 17, 18 },
    { 17, 19 },
    { 31, 32 },
    { -1, -1 },
} };
