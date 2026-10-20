// Two modes of four navigation keys with four signed directional destinations; func_ov031_022338b4 indexes mode*16 + key*4 + direction; negative values signal fallback.
struct MenuNavigation { signed char destinations[2][4][4]; unsigned short alignmentPadding; };
// Original data: arm9/ov031 @ 0x224912e; symbol: data_ov031_0224912e.
// Two modes of four navigation keys with four signed directional destinations; func_ov031_022338b4 indexes mode*16 + key*4 + direction; negative values signal fallback.
// Initial values: hex fffefffe03000300ffffffff01000100fffefffe0300020001000300020001000000.
// Observed span: 34 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" const MenuNavigation WfcConnectionMethodMoveChooserSelection_TwoModesOfFourNavigationKeysWithFourSignedDirectionalDestinations = { {
    {
        { -1, -2, -1, -2 },
        { 3, 0, 3, 0 },
        { -1, -1, -1, -1 },
        { 1, 0, 1, 0 },
    },
    {
        { -1, -2, -1, -2 },
        { 3, 0, 2, 0 },
        { 1, 0, 3, 0 },
        { 2, 0, 1, 0 },
    },
}, 0 };
